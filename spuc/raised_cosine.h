#ifndef SPUC_RAISED_COSINE
#define SPUC_RAISED_COSINE

// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_template_functions
#include <spuc/spuc_types.h>
#include <spuc/fir_coeff.h>
#include <cmath>
#include <spuc/complex.h>
#include <spuc/fir_coeff.h>
#include <spuc/raised_cosine_imp.h>
namespace SPUC {
//! \file
//! \brief  Raised Cosine functions
//
//! \brief  Raised Cosine functions
//! \author Tony Kirke
//! \ingroup template_functions comm
template <class T> void raised_cosine(fir_coeff<T>& rcfir, float_type alpha, float_type rate) {
  int i;
  int num_taps = rcfir.num_taps;
  double gain = 1.0 / rate;
  for (i = 0; i < num_taps; i++) {
    rcfir.coeff[i] = (T)raised_cosine_imp(alpha, float_type(i), rate, num_taps);
    rcfir.coeff[i] = gain * rcfir.coeff[i];
  }
}

}  // namespace SPUC
#endif
