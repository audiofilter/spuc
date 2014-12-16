#ifndef SPUC_IIR_LPF
#define SPUC_IIR_LPF

// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_double_templates
#include <spuc/spuc_types.h>
#include <iostream>
#include <fstream>
#include <spuc/complex.h>
#include <spuc/quantiser.h>
#include <spuc/mixed_type.h>
#include <spuc/iir_lpf1.h>
namespace SPUC {
//! \file
//! \brief  Template Class for 1st Order low pass iir filter
//!
//! \brief  Template Class for 1st Order low pass iir filter
//
//! <p>The filter is the first order low pass digital filter given by
//! \f$ G(z) =  \frac{1+z^-1}{1-az^-1} \f$ <p>where a is real and |a| < 1
//! Note: Not normalized
//! \author Tony Kirke
//! \ingroup double_templates iir
template <class Numeric, class Coeff = float_type> class iir_lpf : public iir_lpf1<Numeric, Coeff> {
  using SPUC::iir_lpf1<Numeric, Coeff>::gain;
  using SPUC::iir_lpf1<Numeric, Coeff>::previous_in;
  using SPUC::iir_lpf1<Numeric, Coeff>::previous_out;
  using SPUC::iir_lpf1<Numeric, Coeff>::out;
  using SPUC::iir_lpf1<Numeric, Coeff>::Q;

 protected:
  Coeff a;

 public:
  iir_lpf(Coeff A = 0, long b = 0) : iir_lpf1<Numeric, Coeff>(A, b) {
    gain = ((1 - A) / (1 + A));
    a = A / (1 + A);
  }
  Coeff get_a0() { return (gain); }
  Coeff get_b0() { return (a); }
  //! Input new sample and calculate output
  Numeric clock(Numeric input) {
    typename mixed_type<Numeric, Coeff>::dtype sum;
    // Shift previous outputs and calculate new output */
    //	out = gain*previous_out + (1-gain)*input;
    sum = gain * previous_out + a * (input + previous_in);
    out = Q(sum);
    previous_out = out;
    previous_in = input;
    return (out);
  }
};
}  // namespace SPUC
#endif
