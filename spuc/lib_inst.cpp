
// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_src
#include <iostream>
#include <fstream>
#include <spuc/complex.h>
#include <vector>
#include <spuc/fir.h>
namespace SPUC {

/// Dummy functions for library instantations
int dummy_cl(complex<long> z) {
  int a;
  a = real(z) + imag(z);
  return (a);
}
int dummy_vf(void) {
  double a;
  fir<double, double> z(32);
  std::vector<double> tmp;

  tmp = get_taps(z);

  a = tmp[0];
  return ((int)a);
}
}  // namespace SPUC
