
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
// from directory: spuc_template_functions
#include <cmath>
#include <spuc/complex.h>
#include <spuc/fir_coeff.h>
#include <spuc/root_raised_cosine_imp.h>
#include <spuc/root_raised_cosine.h>
namespace SPUC {
//! \ingroup fir
template <> void root_raised_cosine_quantized(fir_coeff<long >& rcfir, float_type alpha, int rate, 
									int bits, float_type scale) {
  int i;
  int num_taps = rcfir.num_taps;
  float_type amplitude = scale*(1 << (bits-2));
  for (i=0;i<num_taps;i++) {
	rcfir.coeff[i] = SPUC_TOLONG(amplitude*root_raised_cosine_imp(
																  alpha,float_type(i), (float_type)rate, num_taps));
  } 
}
//! \ingroup fir
template <> void root_raised_cosine_quantized(fir_coeff<float >& rcfir, float_type alpha, int rate, 
									int bits, float_type scale) {
  int i;
  int num_taps = rcfir.num_taps;
  float_type amplitude = scale*(1 << (bits-2));
  for (i=0;i<num_taps;i++) {
	rcfir.coeff[i] = floor(amplitude*root_raised_cosine_imp(
															alpha,float_type(i), (float_type)rate, num_taps)+0.5);
  } 
}
//! \ingroup fir
template <> void root_raised_cosine_quantized(fir_coeff<int >& rcfir, float_type alpha, int rate, 
									int bits, float_type scale) {
  int i;
  int num_taps = rcfir.num_taps;
  float_type amplitude = scale*(1 << (bits-2));
  for (i=0;i<num_taps;i++) {
	rcfir.coeff[i] = SPUC_TOINT(amplitude*root_raised_cosine_imp(
																  alpha,float_type(i), (float_type)rate, num_taps));
  } 
}
//! \ingroup fir
template <> void root_raised_cosine_quantized(fir_coeff<double >& rcfir, float_type alpha, int rate, 
									int bits, float_type scale) {
  int i;
  int num_taps = rcfir.num_taps;
  float_type amplitude = scale*(1 << (bits-2));
  for (i=0;i<num_taps;i++) {
	rcfir.coeff[i] = floor(amplitude*root_raised_cosine_imp(
															alpha,float(i), (float)rate, num_taps)+0.5);
  } 
}
} // namespace SPUC
