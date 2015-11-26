#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_double_templates
#include <spuc/spuc_types.h>
#include <spuc/quant.h>
#include <spuce/filters/allpass_1.h>
namespace SPUC {
//! \file
//! \brief  Template Class for Allpass halfband IIR Filter
//
//! \brief  Template Class for Allpass halfband IIR Filter
//
//!   The filter is a combination of 2 Allpass sections of
//!   the form  G(z) =  (a*z*z + 1)/(z*z+a)
//!   so that the overall H(z) is
//!   H(z) = 1/z*G(z,a0) + G(z,a1)
//!   The combination of these two allpass functions result
//!   in a lowpass/highpass complementary pair. The class only
//!   uses the low pass filter.
//!   This is similar to allpass_iir, except since this is used
//!   as a halfband filter the output samples are decimated by 2.
//!   So that if the member function clock is called at the higher
//!   (input) sampling rate, the outputs are only valid even second
//!   sample. This is taken advantage off by running the individual
//!   sections effectively at the lower rate.
//!   The invalid samples are set to zero.
//!   This class needs the allpass_1 class
//! \image html allpass_halfband.gif
//! \image latex allpass_halfband.eps
//! \author Tony Kirke
//! \image html iir_allpass1_halfband.png
//! \ingroup double_templates iir
template <class Numeric, class Coeff = float_type> class iir_allpass1_halfband {
 public:
  char even;  //! Keeps track of which filter to clock
 protected:
  //! The 2 1st order allpass filters
  spuce::allpass_1<Numeric, Coeff> A0, A1;
  //! Individual filter outputs
  Numeric out0, out1;

 public:
  iir_allpass1_halfband(Coeff c0, Coeff c1, long round_bits = 0) : A0(c0, 1), A1(c1, 1) {
    even = 0;
  }
  //! reset
  void reset() {
    A0.reset();
    A1.reset();
    out0 = out1 = (Numeric)0;
  }
  //! Shift inputs by one time sample and place new sample into array
  Numeric clock(Numeric input) {
    if (!even) {
      out0 = A0.clock(input);
    } else {
      out1 = A1.clock(input);
    }
    even = !even;
    if (even)
      return (round((out0 + out1), 1));
    else
      return ((Numeric)0);  // to indicate that this sample is not calculated
    // Complimentary filter return(0.5*(out0 - out1));
  }
  char ready(void) { return (even); }
};
// template_instantiations: long; complex<long>; float_type; complex<float_type>
}  // namespace SPUC
