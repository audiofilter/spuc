// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_template_functions
#include <cmath>
#include <spuc/complex.h>
#include <spuce/filters/fir_coeff.h>
#include <spuce/filters/root_raised_cosine_imp.h>
#include <spuce/filters/root_raised_cosine.h>
namespace spuce {
//! \ingroup fir
template <>
void root_raised_cosine_quantized(fir_coeff<int64_t>& rcfir, float_type alpha, int rate, int bits, float_type scale) {
  int i;
  int num_taps = rcfir.number_of_taps();
  float_type amplitude = scale * (1 << (bits - 2));
  for (i = 0; i < num_taps; i++) {
      rcfir.settap(i,SPUC_TOLONG(amplitude * root_raised_cosine_imp(alpha, float_type(i), (float_type)rate, num_taps)));
  }
}
//! \ingroup fir
template <>
void root_raised_cosine_quantized(fir_coeff<float>& rcfir, float_type alpha, int rate, int bits, float_type scale) {
  int i;
  int num_taps = rcfir.number_of_taps();
  float_type amplitude = scale * (1 << (bits - 2));
  for (i = 0; i < num_taps; i++) {
      rcfir.settap(i,floor(amplitude * root_raised_cosine_imp(alpha, float_type(i), (float_type)rate, num_taps) + 0.5));
  }
}
//! \ingroup fir
template <>
void root_raised_cosine_quantized(fir_coeff<int>& rcfir, float_type alpha, int rate, int bits, float_type scale) {
  int i;
  int num_taps = rcfir.number_of_taps();
  float_type amplitude = scale * (1 << (bits - 2));
  for (i = 0; i < num_taps; i++) {
      rcfir.settap(i, SPUC_TOINT(amplitude * root_raised_cosine_imp(alpha, float_type(i), (float_type)rate, num_taps)));
  }
}
//! \ingroup fir
template <>
void root_raised_cosine_quantized(fir_coeff<double>& rcfir, float_type alpha, int rate, int bits, float_type scale) {
  int i;
  int num_taps = rcfir.number_of_taps();
  float_type amplitude = scale * (1 << (bits - 2));
  for (i = 0; i < num_taps; i++) {
      rcfir.settap(i, floor(amplitude * root_raised_cosine_imp(alpha, float(i), (float)rate, num_taps) + 0.5));
  }
}
}  // namespace SPUC
