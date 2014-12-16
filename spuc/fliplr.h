#ifndef SPUC_FLIPLR
#define SPUC_FLIPLR

// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_template_array_functions
#include <spuc/spuc_types.h>
#include <vector>
namespace SPUC {
//! \file
//! \brief fliplr - same as matlab function
//
//! \brief fliplr - same as matlab function
//! \author Tony Kirke
//! \ingroup template_array_functions misc
template <class T> std::vector<T> fliplr(const std::vector<T>& x) {
  int N = x.size();
  std::vector<T> c(N);
  for (int j = 0; j < N; j++) c[N - j] = x[j];
  return (c);
}
}  // namespace SPUC
#endif
