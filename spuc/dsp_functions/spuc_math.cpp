// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_src
#include <spuc/dsp_functions/spuc_math.h>
namespace SPUC {
// function for hyperbolic inverse cosine of x
float_type coshin(float_type x) { return (log(x + sqrt(x * x - 1.))); }
// function for inverse cosine of x
float_type arccos(float_type x) {
  if (x == 0) return (PI / 2.0);
  if (x < 0)
    return (atan(sqrt(1. - x * x) / x));
  else
    return (atan(sqrt(1. - x * x) / x) + PI);
}
// function for hyperbolic cosine of x
float_type cosh(float_type x) { return ((::exp(x) + ::exp(-x)) / 2.); }
float_type sinh(float_type x) { return ((::exp(x) - ::exp(-x)) / 2.); }

complex<float_type> cos(complex<float_type> x) {
  float_type cosh(float_type x);
  float_type cos(float_type x);
  float_type r = cosh(imag(x)) * cos(real(x));
  float_type i = sinh(imag(x)) * sin(real(x));
  return (complex<float_type>(r, i));
}
//! Polar to rectangular conversion
complex<float_type> polar(float_type amp, float_type arg) {
  return (complex<float_type>(amp * cos(arg), amp * sin(arg)));
}
//! complex exponential
complex<float_type> exp(complex<float_type> x) { return (::exp(real(x)) * expj(imag(x))); }
}  // namespace SPUC
