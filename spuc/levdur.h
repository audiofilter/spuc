#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_template_array_functions
#include <spuc/spuc_types.h>
#include <vector>
namespace SPUC {
//! \file
//! \brief Template class for Levinson-Durbin algorithm
//
//! \brief Template class for Levinson-Durbin algorithm
//
//! <font color="red"><i>Under construction!</i></font>
//! \author Tony Kirke
//! \ingroup template_array_functions misc
template <class T> std::vector<T> levdur(const std::vector<T>& R) {
  long N = R.size();
  std::vector<T> a(N);
  T Pe;
  T q, at;
  int j, k, l;

  // copy array
  for (j = 0; j < N; j++) a[j] = R[j];

  a[0] = (T)1.0;
  a[1] = -R[1] / R[0];
  Pe = R[0] - a[1] * a[1] * R[0];
  for (j = 2; j <= N; j++) {
    for (q = R[j], l = 1; l <= j - 1; l++) q += a[l] * R[j - 1];
    q = -q / Pe;
    for (k = 1; k <= j / 2; k++) {
      at = a[k] + q * a[j - k];
      a[j - k] += q * a[k];
      a[k] = at;
    }
    a[j] = q;
    Pe = Pe - q * q * Pe;
  }
  return (a);
}
}  // namespace SPUC
