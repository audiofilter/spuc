// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_src
#include <spuc/dsp_functions/xcorr.h>
#include <spuc/dsp_functions/fft.h>
#include <spuc/dsp_functions/ifft.h>
namespace SPUC {

std::vector<double> xcorr(const std::vector<double> &x, unsigned maxlag) {
  std::vector<double> R;

  unsigned N = x.size();
  if (maxlag == 0) maxlag = N - 1;

  int np2 = int(ceil(log(N + maxlag) / log(2.0)));
  unsigned M = (1 << np2);

  std::vector<complex<double> > y;
  for (unsigned i = 0; i < M; i++) {
    if (i < N) {
      y.push_back(x[i]);
    } else {
      y.push_back(0.0);
    }
  }

  fft(y, np2);
  for (unsigned i = 0; i < M; i++) y[i] = magsq(y[i]);
  ifft(y, np2);

  double gain = (double)1.0 / N;

  for (unsigned i = 0; i < maxlag; i++) R.push_back(gain * real(y[maxlag - i]));
  for (unsigned i = 0; i < maxlag + 1; i++) R.push_back(gain * real(y[i]));

  return R;
}
}  // namespace SPUC
