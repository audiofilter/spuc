#ifndef SPUC_IIR_ALLPASS2
#define SPUC_IIR_ALLPASS2

// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_double_templates
#include <spuc/spuc_types.h>
#include <spuc/quant.h>
#include <spuc/allpass_2nd.h>
namespace SPUC {
//! \file
//! \brief  Template Class for IIR filter using sum of 2nd Order Allpass
// sections
//
//! \brief  Template Class for IIR filter using sum of 2nd Order Allpass
// sections
//
//! The filter is a combination of 2 2nd order Allpass sections
//! This class needs the allpass_2nd class
//! \author Tony Kirke
//!  \ingroup double_templates iir
//! \image html allpass_iir.gif
//! \image latex allpass_iir.eps
template <class Numeric, class Coeff = float_type> class iir_allpass2 {
 protected:
  allpass_2nd<Numeric, Coeff> A0, A1;

 public:
  iir_allpass2(Coeff h1a, Coeff h1b, Coeff h2a, Coeff h2b, long round_bits = 0)
      : A0(h1a, h1b, round_bits), A1(h2a, h2b, round_bits) {}
  //! Reset
  void reset() { A0.reset(), A1.reset(); }

  Numeric clock(Numeric input) {
    Numeric out0, out1;
    out0 = A0.clock(input);
    out1 = A1.clock(input);
    return (round((out0 + out1), 1));
  }
};
}  // namespace SPUC
#endif
