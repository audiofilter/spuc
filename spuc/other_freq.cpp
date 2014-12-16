
// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_src
#include <spuc/complex.h>
#include <spuc/spuc_math.h>
#include <spuc/other_freq.h>
namespace SPUC {

void cic_freq(int rate, int order, int pts, double* w, int freq_off, double inc) {
  double db = 0;
  double sum = 0;
  double wf = inc * PI / (double)pts;
  for (int i = 0; i < pts; i++) {
    if (i != freq_off)
      sum = (1.0 / rate) * sin(0.5 * wf * (i - freq_off) * rate) / sin(0.5 * wf * (i - freq_off));
    else
      sum = 0;
    //	  std::cout << "w1[" << i << "] = " << sum << "\n";
    db = 10.0 * order * log(magsq(sum)) / log(10.0);
    w[i] = db;
  }
}

}  // namespace SPUC
