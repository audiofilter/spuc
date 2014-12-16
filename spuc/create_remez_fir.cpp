
// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_src
#include <cmath>
#include <spuc/spuc_defines.h>
#include <spuc/complex.h>
#include <spuc/fir_coeff.h>
#include <spuc/remez_fir.h>
namespace SPUC {
void create_remez_fir(fir_coeff<float_type>& remezfir, int jtype, int nbands, std::vector<float_type>& edge,
                      std::vector<float_type>& fx, std::vector<float_type>& wtx) {
  bool ok;
  long nfilt = remezfir.num_taps;
  remez_fir Remz;
  std::vector<float_type> fir_coef(nfilt);
  ok = Remz.remez(fir_coef, nfilt, nbands, edge, fx, wtx, jtype);
  if (!ok) {
    for (int i = 0; i < nfilt; i++) remezfir.settap(i, 0);
    remezfir.settap(0, 1);
  } else {
    for (int i = 0; i < nfilt; i++) remezfir.settap(i, fir_coef[i]);
  }
}
}  // namespace SPUC
