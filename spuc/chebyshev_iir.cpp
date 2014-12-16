
// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_src
#include <spuc/spuc_defines.h>
#include <spuc/complex.h>
#include <cfloat>
#include <spuc/chebyshev_iir.h>
namespace SPUC {
//! fcd = cut-off (1=sampling rate)
//! ord = Filter order
//! ripple = passband ripple in dB
void chebyshev_iir(iir_coeff& filt, float_type fcd, bool lpf, float_type ripple = 3.0) {
  const float_type ten = 10.0;
  long order = filt.order;
  float_type epi = pow(ten, (ripple / ten)) - 1.0;
  epi = pow(epi, (float_type)(1. / (1.0 * order)));
  float_type wca = tan(0.5 * PI * fcd);
  //! wca - pre-warped angular frequency
  long n2 = (order + 1) / 2;
  chebyshev_s(filt.poles, filt.zeros, lpf, wca, epi, order, n2);
  filt.bilinear();
  filt.convert_to_ab();
}
//! Calculate poles (chebyshev)
void chebyshev_s(std::vector<complex<float_type> >& poles, std::vector<complex<float_type> >& zeros, bool lpf,
                 float_type wp, float_type epi, long n, long n2) {
  long l = 0;
  if (n % 2 == 0) l = 1;
  float_type arg;
  float_type x = 1 / epi;
  float_type asinh = log(x + sqrt(1.0 + x * x));
  float_type v0 = asinh / (float_type(n));
  float_type sm = sinh(v0);
  float_type cm = cosh(v0);
  for (int j = 0; j < n2; j++) {
    arg = -0.5 * PI * l / ((float_type)(n));
    if (lpf) {
      poles[j] = -wp * complex<float_type>(-sm * cos(arg), cm * sin(arg));
      zeros[j] = FLT_MAX;
    } else {
      poles[j] = -1.0 / (wp * complex<float_type>(-sm * cos(arg), cm * sin(arg)));
      zeros[j] = 0;
    }
    l += 2;
  }
}
}  // namespace SPUC
