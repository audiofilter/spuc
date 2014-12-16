
// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_src
#include <spuc/spuc_defines.h>
#include <spuc/fir_inv_dft.h>
namespace SPUC {
//! \file
//! \brief calculates fir filter coefficients based on frequency sampling design
// using IDFT
std::vector<float_type> inv_dft_symmetric(const std::vector<float_type>& A, int N) {
  std::vector<float_type> h(N);
  float_type x, val;
  float_type M = (N - 1.0) / 2.0;
  int END = (N % 2 != 0) ? (int)M : (N / 2 - 1);
  for (int n = 0; n < N; n++) {
    val = A[0];
    x = TWOPI * (n - M) / N;
    for (int k = 1; k <= END; k++) val += 2.0 * A[k] * cos(x * k);
    h[n] = val / N;
  }
  return h;
}
//! \brief calculates fir filter coefficients based on frequency sampling design
// using IDFT
std::vector<float_type> inv_dft(const std::vector<float_type>& A, int N) {
  std::vector<float_type> h(N);
  float_type x, val;
  float_type M = (N - 1.0) / 2.0;
  int END = (N % 2 != 0) ? (int)M : (N / 2 - 1);
  for (int n = 0; n < N; n++) {
    val = (N % 2 != 0) ? 0 : A[N / 2] * sin(PI * (n - M));
    x = TWOPI * (n - M) / N;
    for (int k = 1; k <= END; k++) val += 2.0 * A[k] * sin(x * k);
    h[n] = val / N;
  }
  return h;
}
}  // namespace SPUC
