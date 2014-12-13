
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
#include <spuc/complex.h>
#include <spuc/spuc_math.h>
#include <iostream>
#include <cfloat>
#include <spuc/butterworth_iir.h>
namespace SPUC {
//! Constructor, fcd = cut-off (1=sampling rate)
//! ord = Filter order
//! amax = attenuation at cut-off
void butterworth_iir(iir_coeff& filt, float_type fcd, bool lpf = true,
                     float_type amax = 3.0) {
  // amax - attenuation at cutoff
  const float_type ten = 10.0;
  long order = filt.order;
  float_type epi = pow((float_type)(pow(ten, amax / ten) - 1.0),
                       (float_type)(1. / (2.0 * order)));
  // fcd - desired cutoff frequency (normalized)
  float_type wca = tan(0.5 * PI * fcd) / epi;
  // wca - pre-warped angular frequency
  long n2 = (order + 1) / 2;
  butterworth_s(filt.poles, filt.zeros, lpf, wca, order, n2);
  filt.bilinear();
  filt.convert_to_ab();
}
//! Calculate roots
void butterworth_s(std::vector<complex<float_type> >& poles,
                   std::vector<complex<float_type> >& zeros, bool lpf,
                   float_type wp, long n, long n2) {
  complex<float_type> expj(float_type a);
  long l = 0;
  if (n % 2 == 0) l = 1;
  float_type arg;
  for (int j = 0; j < n2; j++) {
    arg = -0.5 * PI * l / ((float_type)(n));
    if (lpf) {
      poles[j] = wp * expj(arg);
      zeros[j] = FLT_MAX;
    } else {
      poles[j] = 1.0 / wp * expj(arg);
      zeros[j] = 0;
    }
    l += 2;
  }
}
}  // namespace SPUC
