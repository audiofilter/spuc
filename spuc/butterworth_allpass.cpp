
// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_src
#include <spuc/butterworth_allpass.h>
namespace SPUC {
void butterworth_allpass(std::vector<float_type>& a0, std::vector<float_type>& a1, int L) {
  int N = 2 * L + 1;
  int J = L / 2;
  int l;
  float_type d;
  for (l = 1; l <= J; l++) {
    d = tan(PI * l / N);
    a1[l - 1] = d * d;
  }
  for (l = J + 1; l <= L; l++) {
    d = 1.0 / tan(PI * l / N);
    a0[l - J - 1] = d * d;
  }
}
}  // namespace SPUC
