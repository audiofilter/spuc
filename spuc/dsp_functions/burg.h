#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_template_array_functions
#include <spuc/spuc_types.h>
#include <vector>
#include <spuc/magsq.h>
#include <cmath>
namespace SPUC {
//! \file
//! \brief AR model coefficients calculation using Burg algorithm
//
//! \author Tony Kirke,  Copyright(c) 2001
//! \author Tony Kirke
//! \ingroup template_array_functions misc
template <class T> std::vector<T> burg(const std::vector<T>& x, int P) {
  long N = x.size();
  const double EPS = 1e-30;
  std::vector<T> a(P);
  std::vector<T> ef(N);
  std::vector<T> ef_prev(N);
  std::vector<T> eb(N);
  std::vector<T> eb_prev(N);
  std::vector<T> aa(P);
  std::vector<T> rc(N);

  T gamma;
  T num, den;
  int t, p;
  int i;

  for (i = 0; i < N; i++) { ef[i] = eb[i] = x[i]; }

  for (p = 0; p < P; p++) {
    num = (T)0;
    den = (T)0;

    for (t = p + 1; t < N; t++) {
      den += ef[t] * ef[t] + eb[t - 1] * eb[t - 1];
      num += ef[t] * eb[t - 1];
    }

    if (magsq(den) > EPS)
      gamma = ((T)2) * num / den;
    else
      gamma = (T)0;

    a[p] = gamma;
    rc[p] = -a[p];

    for (i = 0; i < N; i++) {
      ef_prev[i] = ef[i];
      eb_prev[i] = eb[i];
    }

    for (t = 1; t < N; t++) {
      ef[t] += -(conj(gamma) * eb_prev[t - 1]);
      eb[t] = eb_prev[t - 1] - (gamma * ef_prev[t]);
    }

    if (p > 0)
      for (t = 0; t < p; t++) a[t] = aa[t] + rc[p] * aa[p - t - 1];
    for (i = 0; i < p + 1; i++) aa[i] = a[i];
  }
  return (a);
}
}  // namespace SPUC
