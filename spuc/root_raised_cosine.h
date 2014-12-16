#ifndef SPUC_ROOT_RAISED_COSINE
#define SPUC_ROOT_RAISED_COSINE

// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_template_functions
#include <spuc/spuc_types.h>
#include <spuc/fir_coeff.h>
#include <spuc/root_raised_cosine_imp.h>
namespace SPUC {
//! \file
//! \brief Root Raised Cosine functions
//
//! \brief Root Raised Cosine functions
//
//! \author Tony Kirke
//! \ingroup template_functions comm
template <class T>
void root_raised_cosine_quantized(fir_coeff<T>& rcfir, float_type alpha, int rate, int bits, float_type scale);
//! \author Tony Kirke
//! \ingroup template_functions fir
template <class T> void root_raised_cosine(fir_coeff<T>& rcfir, float_type alpha, int rate) {
  int i;
  int num_taps = rcfir.num_taps;
  double gain = 1.0 / rate;
  for (i = 0; i < num_taps; i++) {
    rcfir.coeff[i] = (T)(gain * root_raised_cosine_imp(alpha, float_type(i), (float_type)rate, num_taps));
  }
}
}  // namespace SPUC
#endif
