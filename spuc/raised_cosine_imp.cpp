
// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_src
#include <cmath>
#include <spuc/spuc_defines.h>
#include <spuc/raised_cosine_imp.h>
namespace SPUC {
float_type raised_cosine_imp(float_type alpha, float_type xin, float_type rate, long num_taps)
//-----------------------------------------------------------------------
//       Calculates the raised cosine pulse shape given the excess
//       bandwidth value beta and the index.
//-----------------------------------------------------------------------
{
  float_type x1, x2, rc1;

  float_type xindx = xin - num_taps / 2;
  x1 = PI * xindx / rate;
  x2 = 1 - (4 * alpha * alpha * (xindx / rate) * (xindx / rate));
  if (x1 == 0) return (1);
  if (x2 == 0) {
    x2 = 8 * alpha * (xindx / rate) * (xindx / rate);
    rc1 = sin(x1) * sin(alpha * x1) / x2;
  } else { rc1 = (sin(x1) * cos(alpha * x1)) / (x1 * x2); }
  return (rc1);
}
}  // namespace SPUC
