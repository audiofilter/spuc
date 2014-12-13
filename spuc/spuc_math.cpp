
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
//! \author Tony Kirke
// from directory: spuc_src
#include <spuc/spuc_math.h>
namespace SPUC {
// Exclusive or the bits in x together.
// N is the number of bits in x.
float_type sqrt(float_type x) { return (::sqrt(x)); }
float_type cos(float_type x) { return (::cos(x)); }
complex<float_type> sqrt(complex<float_type> x) {
  float_type mag = sqrt(sqrt(magsq(x)));
  float_type ang = 0.5 * arg(x);  // ambiguity
  return (polar(mag, ang));
}
complex<float_type> sqrt(complex<long> x) {
  float_type mag = sqrt(sqrt(magsq(x)));
  float_type ang = 0.5 * arg(x);  // ambiguity
  return (polar(mag, ang));
}
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
complex<float_type> exp(complex<float_type> x) {
  return (::exp(real(x)) * expj(imag(x)));
}
}  // namespace SPUC
