#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_real_template_functions
#include <spuc/spuc_types.h>
#include <cmath>
namespace SPUC {
//! \file
//! \brief Templated saturation functions
//
//! \brief Templated saturation functions
//! \author Tony Kirke
//! \ingroup real_template_functions misc
template <class T> T real_saturate(T in, long bits);
//! \file
//! \brief Templated saturation functions
//
//! \brief Templated saturation functions
//! \author Tony Kirke
//! \ingroup real_template_functions misc
template <> inline long real_saturate(long in, long bits) {
  long low_mask = ((1 << (bits - 1)) - 1);
  if (ABS(in) > low_mask)
    return ((in > 0) ? low_mask : ~low_mask);
  else
    return (in);
}
template <> inline int real_saturate(int in, long bits) {
  int low_mask = ((1 << (bits - 1)) - 1);
  if (ABS(in) > low_mask)
    return ((in > 0) ? low_mask : ~low_mask);
  else
    return (in);
}
template <> inline double real_saturate(double in, long bits) {
  int low_mask = ((1 << (bits - 1)) - 1);
  if (ABS(in) > (double)low_mask) {
    int lm = (in < 0) ? ~low_mask : low_mask;
    return (double(lm));
  } else
    return (in);
}
template <> inline float real_saturate(float in, long bits) {
  int low_mask = ((1 << (bits - 1)) - 1);
  if (ABS(in) > (float)low_mask) {
    int lm = (in < 0) ? ~low_mask : low_mask;
    return (float(lm));
  } else
    return (in);
}
}  // namespace SPUC
