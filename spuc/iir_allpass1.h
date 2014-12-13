#ifndef SPUC_IIR_ALLPASS1
#define SPUC_IIR_ALLPASS1

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
#include <spuc/allpass_1.h>
#include <spuc/elliptic_allpass.h>
namespace SPUC {
//! \file
//! \brief  Template Class for IIR Filter using 2 1st order sections
//
//! \brief  Template Class for IIR Filter using 2 1st order sections
//
//!   The filter is a combination of 2 Allpass sections of
//!   the form  G(z) =  (a*z*z + 1)/(z*z+a)
//!   so that the overall H(z) is
//!   H(z) = 1/z*G(z,a0) + G(z,a1)
//!   The combination of these two allpass functions result
//!   in a lowpass/highpass complementary pair. The class only
//!   uses the low pass filter.
//!   This class needs the allpass_1 class
//! \author Tony Kirke
//! \ingroup double_templates iir
//! \image html allpass_halfband.gif
//! \image latex allpass_halfband.eps
template <class Numeric, class Coeff = float_type>
class iir_allpass1 {
 protected:
  //! The 2 1st order allpass filters
  int Delay;
  allpass_1<Numeric, Coeff> A0, A1;
  Numeric prev_input;

 public:
  iir_allpass1(Coeff c0, Coeff c1, long round_bits = 0)
      : Delay(2), A0(c0, Delay, round_bits), A1(c1, Delay, round_bits) {
    reset();
  }
  iir_allpass1(float_type fp) : Delay(2) {
    std::vector<Coeff> a0(1);
    std::vector<Coeff> a1(1);
    elliptic_allpass(a0, a1, fp, 2);
    A0.init(a0[0], Delay);
    A1.init(a1[0], Delay);
    reset();
  }
  //! reset
  void reset() {
    A0.reset();
    A1.reset();
    prev_input = (Numeric)0;
  }
  //! Shift inputs by one time sample and place new sample into array
  Numeric clock(Numeric input) {
    Numeric out0, out1;

    out0 = A0.clock(input);
    out1 = A1.clock(prev_input);
    prev_input = input;

    return (round((out0 + out1), 1));
    // Complimentary filter return(0.5*(out0 - out1));
  }
};
// template_instantiations: long; complex<long>; float_type; complex<float_type>
}  // namespace SPUC
#endif
