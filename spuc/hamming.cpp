// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_src
#include <spuc/hamming.h>
#include <spuc/spuc_defines.h>
namespace SPUC {
//! \brief hamming window \f$ w(n) = alpha + beta*cos( 2*\pi*(n-1)/(nf-1) )\f$
std::vector<double> hamming(long nf) {
  std::vector<double> w(nf);
  for (int i = 0; i < nf / 2; i++) {
    float win = 0.54 - 0.46 * std::cos(TWOPI * i / nf);
    w[i] = win;
    w[nf - 1 - i] = win;
  }
  return (w);
}
}  // namespace SPUC
