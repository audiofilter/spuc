#ifndef SPUC_NESTED_SHELF_ALLPASS_2
#define SPUC_NESTED_SHELF_ALLPASS_2

/*
    Copyright (C) 2014 Tony Kirke

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
// from directory: spuc_double_templates
#include <spuc/spuc_types.h>
#include <spuc/quant.h>
#include <spuc/allpass_2nd.h>
#include <spuc/butterworth_allpass.h>
namespace SPUC {
// from directory: spuc_double_templates
template <class Numeric, class Coeff = float_type>
class nested_shelf_allpass_2 {
 protected:
  //! The 2 1st order allpass filters
  int Delay;
  Coeff b0;
  Coeff b1;
  allpass_2nd<Numeric, Coeff> A0, A1;
  allpass_1<Numeric, Coeff> D0;
  Coeff kb;
  Coeff kc;
  bool hpf;

 public:
  nested_shelf_allpass_2(Coeff B0, Coeff B1, Coeff k)
      : b0(B0),
        b1(B1),
        A0((k * k + b0) / (b0 * k * k + 1), (k * k + b0) / (b0 * k * k + 1)),
        A1((k * k + b1) / (b1 * k * k + 1), (k * k + b1) / (b1 * k * k + 1)),
        D0(k) {
    reset();
    kb = 10.0;
    kb = 1.0;
    hpf = false;
  }
  //! reset
  void reset() {
    A0.reset();
    A1.reset();
    D0.reset();
  }
  void set_hpf(bool h) { hpf = h; }
  //
  void init(float_type fp, float_type k, float_type low_gain,
            float_type high_gain) {
    std::vector<float_type> c0(1);
    std::vector<float_type> c1(1);
    butterworth_allpass(c0, c1, 2);  // ignore fp for butterworth func
    b0 = c0[0];
    b1 = c1[0];

    // std::cout << "b0/1 " << b0 << " " << b1 << "\n";

    Coeff a0 = 2 * k * (b0 + 1) / (b0 * k * k + 1);
    Coeff new_b0 = (k * k + b0) / (b0 * k * k + 1);

    Coeff a1 = 2 * k * (b1 + 1) / (b1 * k * k + 1);
    Coeff new_b1 = (k * k + b1) / (b1 * k * k + 1);

    A0.set_coeffs(new_b0, a0);
    A1.set_coeffs(new_b1, a1);

    D0.init(k, 1);

    kb = pow(10.0, low_gain / 20.0);
    kc = pow(10.0, high_gain / 20.0);
    // std::cout << "kb = " << kb << " kc = " << kc << "\n";
  }
  void print() {
    std::cout << "A0 " << A0.a << " " << A0.b << "\n";
    std::cout << "A1 " << A1.a << " " << A1.b << "\n";
    std::cout << "D0 " << D0.get_coefficient() << "\n";
  }
  void change(Coeff k) {
    Coeff a0 = 2 * k * (b0 + 1) / (b0 * k * k + 1);
    Coeff new_b0 = (k * k + b0) / (b0 * k * k + 1);

    Coeff a1 = 2 * k * (b1 + 1) / (b1 * k * k + 1);
    Coeff new_b1 = (k * k + b1) / (b1 * k * k + 1);

    A0.set_coeffs(new_b0, a0);
    A1.set_coeffs(new_b1, a1);

    D0.init(k, 1);
  }
  //! Shift inputs by one time sample and place new sample into array
  Numeric clock(Numeric input) {
    Numeric out0, out1, dly_input;
    Numeric sumx;

    out0 = A0.clock(input);
    dly_input = D0.clock(input);
    out1 = A1.clock(dly_input);

    if (hpf) {
      sumx = kb * (out0 - out1) + kc * (out0 + out1);
    } else {
      sumx = kb * (out0 + out1) + kc * (out0 - out1);
    }
    return (round(sumx, 1));
    // Complimentary filter return(0.5*(out0 - out1));
  }
};
// template_instantiations: long; complex<long>; float_type; complex<float_type>

}  // namespace SPUC
#endif
