#ifndef SPUC_NESTED_IIR_ALLPASS_2
#define SPUC_NESTED_IIR_ALLPASS_2
// from directory: spuc_double_templates
#include <spuc/spuc_types.h>
#include <spuc/quant.h>
#include <spuc/allpass_2nd.h>
namespace SPUC {
// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_double_templates
template <class Numeric, class Coeff = float_type> class nested_iir_allpass_2 {
 protected:
  //! The 2 1st order allpass filters
  int Delay;
  Coeff b0;
  Coeff b1;
  allpass_2nd<Numeric, Coeff> A0, A1;
  allpass_1<Numeric, Coeff> D0;
  bool hpf;

 public:
  nested_iir_allpass_2(Coeff B0, Coeff B1, Coeff k)
      : b0(B0),
        b1(B1),
        A0((k * k + b0) / (b0 * k * k + 1), (k * k + b0) / (b0 * k * k + 1)),
        A1((k * k + b1) / (b1 * k * k + 1), (k * k + b1) / (b1 * k * k + 1)),
        D0(k) {
    reset();
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
  void init(float_type fp, float_type k) {
    std::vector<float_type> c0(1);
    std::vector<float_type> c1(1);
    elliptic_allpass(c0, c1, fp, 2);
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
  }
  void print() {
    std::cout << "A0 " << A0.get_a() << " " << A0.get_b() << "\n";
    std::cout << "A1 " << A1.get_a() << " " << A1.get_b() << "\n";
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

    out0 = A0.clock(input);
    dly_input = D0.clock(input);
    out1 = A1.clock(dly_input);

    if (hpf) { return (round(out0 - out1, 1)); } else {
      return (round(out0 + out1, 1));
    }
    // Complimentary filter return(0.5*(out0 - out1));
  }
};
// template_instantiations: long; complex<long>; float_type; complex<float_type>

}  // namespace SPUC
#endif
