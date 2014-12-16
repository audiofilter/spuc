#ifndef SPUC_PARTIAL_CONVOLVE
#define SPUC_PARTIAL_CONVOLVE

// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_template_array_functions
#include <spuc/spuc_types.h>
#include <vector>
namespace SPUC {
//! \file
// \brief partial convolve
//
// \brief Template partial convolve function
//! \author Tony Kirke,  Copyright(c) 2001
//! \author Tony Kirke
//! \ingroup template_array_functions misc
template <class T> std::vector<T> partial_convolve(const std::vector<T>& x, const std::vector<T>& y, int N, int M) {
  int i, j;
  int L = M + N - 1;
  std::vector<T> c(L);
  for (i = 0; i < L; i++) {
    c[i] = (T)0;
    for (j = 0; j < N; j++) {
      if ((i - j >= 0) & (i - j < M)) c[i] += x[j] * y[i - j];
      //        std::cout << "c[" << i << "] = " << c[i] << "\n";
    }
  }
  return (c);
}
}  // namespace SPUC
#endif
