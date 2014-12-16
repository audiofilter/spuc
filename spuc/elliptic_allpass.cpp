
// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_src
#include <spuc/elliptic_iir.h>
#include <spuc/elliptic_allpass.h>
#include <vector>
#define MINFP 0.005
namespace SPUC {
void elliptic_allpass(std::vector<float_type>& a0, std::vector<float_type>& a1, float_type fp, int L) {
  int N = 2 * L + 1;
  int l;
  int i = 0;
  int j = 0;
  int odd;
  float_type lambda = 1.0;
  float_type d, sn, cn, dn, sn2, beta;
  float_type k, k2, zeta, zeta2;

  if (fp < MINFP) fp = MINFP;
  k = 2 * fp;
  zeta = 1.0 / k;
  zeta2 = zeta * zeta;
  ;
  k2 = k * k;

  odd = (L % 2);
  for (l = 1; l <= L; l++) {
    d = ellik(PI / 2.0, k);
    d = ((2.0 * l - 1.0) / N + 1.0) * d;
    ellpj(d, k2, sn, cn, dn);
    sn2 = sn * sn;
    beta = (zeta + sn2 - lambda * sqrt((1 - sn2) * (zeta2 - sn2))) /
           (zeta + sn2 + lambda * sqrt((1 - sn2) * (zeta2 - sn2)));
    if (l % 2 != odd)
      a1[i++] = beta;
    else
      a0[j++] = beta;
  }
}
}  // namespace SPUC
