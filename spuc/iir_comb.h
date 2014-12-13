#ifndef SPUC_IIR_COMB
#define SPUC_IIR_COMB

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
#include <spuc/complex.h>
#include <spuc/quantiser.h>
#include <spuc/mixed_type.h>
#include <spuc/delay.h>
namespace SPUC {
//! \file
//! \brief  Template for IIR comb type filter with programmable delay and gain
//
//! \brief  Template for IIR comb type filter with programmable delay and gain
//! \author Tony Kirke
//! \image html iir_comb.png
//! \ingroup double_templates iir
template <class Numeric, class Coeff = float_type>
class iir_comb {
 protected:
  Coeff acc_gain;
  Coeff in_gain;
  Numeric out;
  delay<Numeric> dly;
  long delay_size;
  Numeric previous_out;
  Numeric previous_in;
  quantiser<Numeric> Q;

 public:
  iir_comb(Coeff A = 0, long delay = 2, long b = 0)
      : acc_gain(A), in_gain(1 - A), delay_size(delay), Q(b) {
    dly.set_size(delay);
    previous_in = previous_out = out = (Numeric)0;
  }
  void init(Coeff A, long delay) {
    in_gain = 1 - A;
    acc_gain = A;
    delay_size = delay;
    dly.set_size(delay);
  }

  void set_coeff(Coeff A) {
    in_gain = 1 - A;
    acc_gain = A;
  }
  //! Input new sample and calculate output
  Numeric clock(Numeric input) {
    typename mixed_type<Numeric, Coeff>::dtype sum;
    // Shift previous outputs and calculate new output
    sum = acc_gain * previous_out + in_gain * input;
    out = Q(sum);
    previous_out = dly.input(out);
    return (out);
  }
  //! Reset
  void reset() {
    previous_in = previous_out = out = (Numeric)0;
    dly.reset();
  }
};
}  // namespace SPUC
#endif
