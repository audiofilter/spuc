// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_src
#include <spuc/bartlett.h>
namespace SPUC {
std::vector<double> bartlett(long nf) {
  std::vector<double> w(nf);
  for (int i = 0; i < nf / 2; i++) {
    float win = 2.0 * i / (nf - 1);
    w[i] = win;
    w[nf - 1 - i] = win;
  }
  if (nf % 2 == 1) w[nf / 2] = 1.0;
  return (w);
}
}  // namespace SPUC
