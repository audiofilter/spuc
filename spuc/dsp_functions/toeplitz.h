#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_template_functions
#include <spuc/spuc_types.h>
namespace SPUC {
//! \file
//! \brief Get Symmetric Toeplitz matrix from vector
//
// <font color="red"><i>Under construction!</i></font>
//!  \author Tony Kirke,  Copyright(c) 2001
//! \author Tony Kirke
//! \ingroup template_functions misc
template <class T> void toeplitz(vector<T> x, matrix<T>& A) {
  int i, j;
  int k = 0;
  long N = x.size();
  for (j = 0; j < N; j++) {
    for (i = 0; i < N; i++) A(j, i) = x[(i + k) % N];
    k++;
  }
}
// function_instantiations: long, double, complex<long>, complex<double>
}  // namespace SPUC
