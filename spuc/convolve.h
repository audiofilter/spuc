#ifndef SPUC_CONVOLVE
#define SPUC_CONVOLVE

// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_template_array_functions
#include <spuc/spuc_types.h>
#include <vector>
namespace SPUC {
//! \file
// \brief Convolve
//
// \brief Template convolve function
//! \author Tony Kirke,  Copyright(c) 2001
//! \author Tony Kirke
//! \ingroup template_array_functions misc
template <class T> std::vector<T> convolve(const std::vector<T>& x, const std::vector<T>& y) {
  int i, j;
  int M = x.size();
  int N = y.size();
  int L = M + N - 1;
  std::vector<T> c(L);
  for (i = 0; i < L; i++) {
    c[i] = (T)0;
    for (j = 0; j < N; j++) {
      if ((i - j >= 0) & (i - j < M)) c[i] += x[j] * y[i - j];
    }
  }
  return (c);
}
}  // namespace SPUC
#endif
