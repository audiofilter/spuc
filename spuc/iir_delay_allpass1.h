#ifndef SPUC_IIR_DELAY_ALLPASS1
#define SPUC_IIR_DELAY_ALLPASS1

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
namespace SPUC {
//! \file
//! \brief  Template Class for IIR filter consisting of 2 1st Order Allpass
//sections
//
//! \brief  Template Class for IIR filter consisting of 2 1st Order Allpass
//sections
//
//! The filter is a combination of 2 Allpass sections of
//! the form  G(z) =  (a*z*z + 1)/(z*z+a)
//! so that the overall H(z) is
//! H(z) = 1/z*G(z,a0) + G(z,a1)
//! The combination of these two allpass functions result
//! in a lowpass/highpass complementary pair. The class only
//! uses the low pass filter.
//! This class needs the allpass_1 class
//! \image html allpass_iir.gif
//! \image latex allpass_iir.eps
//! \author Tony Kirke
//!  \ingroup double_templates iir
template <class Numeric, class Coeff = float_type>
class iir_delay_allpass1 {
 protected:
  allpass_1<Numeric, Coeff> A0, A1;
  delay<Numeric> dly;
  long delay_size;

 public:
  iir_delay_allpass1(Coeff c0, Coeff c1, long delay = 2, long round_bits = 0)
      : A0(c0, delay, round_bits),
        A1(c1, delay, round_bits),
        delay_size(delay) {
    dly.set_size(delay);
  }
  //! Reset
  void reset() {
    dly.reset();
    A0.reset(), A1.reset();
  }
  void set_delay(int d) { dly.set_size(d); }
  //! Shift inputs by one time sample and place new sample into array
  Numeric clock(Numeric input) {
    Numeric out0, out1;

    dly.input(input);
    out0 = A0.clock(input);
    out1 = A1.clock(dly.check(delay_size / 2));
    return (round((out0 + out1), 1));
    // Complimentary filter return(0.5*(out0 - out1));
  }
};
// template_instantiations: long; complex<long>; float_type; complex<float_type>
}  // namespace SPUC
#endif
