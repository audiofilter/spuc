
// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_src
#include <cmath>
#include <spuc/spuc_defines.h>
#include <spuc/complex.h>
#include <spuc/fir_coeff.h>
#include <spuc/remez_fir.h>
#include <spuc/create_remez_lpfir.h>
namespace SPUC {
//! \brief calculates the coefficients for lowpass FIR based on Remez
// constraints
void create_remez_lpfir(fir_coeff<float_type>& remezfir, float_type pass_edge, float_type stop_edge,
                        float_type stop_weight) {
  bool ok = true;
  std::vector<float_type> e1(4);
  std::vector<float_type> f1(4);
  std::vector<float_type> w1(4);
  long nfilt = remezfir.num_taps;
  remez_fir Remz;
  w1[0] = 1.0;
  w1[1] = stop_weight;
  e1[0] = 0;
  e1[1] = pass_edge / 2.0;
  e1[2] = stop_edge / 2.0;
  e1[3] = 0.5;
  f1[0] = 1.0;
  f1[1] = 0.0;
  std::vector<float_type> fir_coef(nfilt);
  ok = Remz.remez(fir_coef, nfilt, 2, e1, f1, w1, 1);
  if (ok) {
    for (int i = 0; i < nfilt; i++) remezfir.settap(i, fir_coef[i]);
  } else {
    for (int i = 0; i < nfilt; i++) remezfir.settap(i, 0);
    remezfir.settap(0, 1);
  }
}
}  // namespace SPUC
