
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
#include <spuc/spuc_defines.h>
#include <spuc/fir_inv_dft.h>
namespace SPUC {
//! \file
//! \brief calculates fir filter coefficients based on frequency sampling design using IDFT
smart_array<float_type> inv_dft_symmetric(const smart_array<float_type>& A, int N) {
  smart_array<float_type> h(N);
  float_type x, val;
  float_type M = (N-1.0)/2.0;
  int END = (N%2 != 0) ? (int)M : (N/2-1);
  for (int n=0; n<N; n++) {
	val = A[0];
	x = TWOPI*(n - M)/N;
	for (int k=1; k<=END; k++) val += 2.0*A[k]*cos(x*k);
	h[n] = val/N;
  }
  return h;
}
//! \brief calculates fir filter coefficients based on frequency sampling design using IDFT
smart_array<float_type> inv_dft(const smart_array<float_type>& A, int N) {
  smart_array<float_type> h(N);
  float_type x, val;
  float_type M = (N-1.0)/2.0;
  int END = (N%2 != 0) ? (int)M : (N/2-1);
  for (int n=0; n<N; n++) {
	val = (N%2 != 0) ? 0 : A[N/2]*sin(PI*(n - M));
	x = TWOPI*(n - M)/N;
	for (int k=1; k<=END; k++) val += 2.0*A[k]*sin(x*k);
	h[n] = val/N;
  }
  return h;
}
} // namespace SPUC
