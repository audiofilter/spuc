#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_template_array_functions
#include <spuc/spuc_types.h>
#include <vector>
namespace SPUC {
//! \file
//! \brief Compute the autocorrelation of the Vector
//
//! \author Tony Kirke,  Copyright(c) 2001
//! \ingroup template_array_functions misc
template <class T> std::vector<T> auto_corr(const std::vector<T>& x) {
  int i, j;
  T d;
  long N = x.size();
  std::vector<T> autoc(N);
  for (j = 0; j < N; j++) {
    for (i = j, d = 0; i < N; i++) d += x[i] * x[i - j];
    autoc[j] = d;
  }
  return (autoc);
}
}  // namespace SPUC
