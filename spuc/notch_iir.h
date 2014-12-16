#ifndef SPUC_NOTCH_IIR
#define SPUC_NOTCH_IIR

// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_double_templates
#include <spuc/spuc_types.h>
#include <spuc/iir_2nd.h>
namespace SPUC {
//! \file
//! \brief IIR notch filter based on 2nd order biquad
//
//! \brief IIR notch filter based on 2nd order biquad
//! \author Tony Kirke
//! \image html notch_iir.png
//! \ingroup double_templates iir
template <class Numeric, class Coeff = float_type> class notch_iir {
 public:
  iir_2nd<Numeric, Coeff> filter;
  Coeff gain;

  notch_iir(Coeff B, Coeff Y) : filter(1, Y * (1 + B), B, 2 * Y, 1) { gain = (1 + B) * (Coeff)(0.5); }
  void set_coeffs(Coeff B, Coeff Y) {
    filter.set_coeffs(1, Y * (1 + B), B, 2 * Y, 1);
    gain = (1 + B) * (Coeff)(0.5);
  }
  void set_freq(Coeff B) {
    Coeff Y = 0.5 * filter.get_a1();
    filter.set_coeffs(1, Y * (1 + B), B, 2 * Y, 1);
    gain = (1 + B) * (Coeff)(0.5);
  }
  void set_depth(Coeff Y) {
    Coeff B = 0.5 * filter.get_b2();
    filter.set_coeffs(1, Y * (1 + B), B, 2 * Y, 1);
    gain = (1 + B) * (Coeff)(0.5);
  }

  // force gain*x to be Numeric?
  Numeric clock(Numeric x) { return (filter.clock(Numeric(gain * x))); }
};
}  // namespace SPUC
#endif
