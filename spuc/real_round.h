#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_real_template_functions
#include <spuc/spuc_types.h>
#include <cmath>
namespace SPUC {
//! \file
//! \brief Templated round function
//
//! \brief Templated round function
//! \author Tony Kirke
//! \ingroup real_template_functions misc
template <class T> T real_round(T in, long bits);
template <> inline long real_round(long in, long bits) {
  float scale = 1.0 / (float)(1 << bits);
  return (SPUC_TOLONG(scale * in));
}
template <> inline float real_round(float in, long bits) {
  float scale = 1.0 / (float)(1 << bits);
  return (scale * in);
}
template <> inline int real_round(int in, long bits) {
  double scale = 1.0 / (double)(1 << bits);
  return (SPUC_TOLONG(scale * in));
}
template <> inline double real_round(double in, long bits) {
  double scale = 1.0 / (double)(1 << bits);
  return (scale * in);
}
}  // namespace SPUC
