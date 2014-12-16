
// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_src
#include <spuc/spuc_defines.h>
#include <spuc/complex.h>
#include <spuc/spuc_math.h>
#include <iostream>
#include <fstream>
#include <spuc/idft.h>
#include <vector>
namespace SPUC {
void idft(std::vector<complex<float_type> > y, int n) {
  int j, l;

  /*  n inverse dft length */
  std::vector<complex<float_type> > x(n + 1);
  complex<float_type> mult;

  /*  calculate the w values recursively */
  //  complex<float_type> w_inc = expj(TWOPI/n);
  //  complex<float_type> w_x = complex<float_type>(1,0);
  for (j = 0; j < n; j++) { x[j] = y[j]; }

  /*  start inverse fft */
  for (l = 0; l < n; l++) {
    y[l] = 0;
    for (j = 0; j < n; j++) {
      mult = x[j] * expj(TWOPI * l * j / (n));
      y[l] += mult;
    }
  }

#define SCALEFFT
#ifdef SCALEFFT
  int i;
  /*  scale all results by 1/n */
  float_type scale = (float_type)(1.0 / n);
  for (i = 0; i < n; i++) y[i] = scale * y[i];
#endif
}
void dft(std::vector<complex<float_type> > y, int n) {
  int j, l;

  /*  n inverse dft length */
  std::vector<complex<float_type> > x(n + 1);

  for (j = 0; j < n; j++) x[j] = y[j];

  /*  start inverse fft */
  for (l = 0; l < n; l++) {
    y[l] = 0;
    for (j = 0; j < n; j++) { y[l] += x[j] * expj(-TWOPI * j * l / n); }
  }
}
}  // namespace SPUC
