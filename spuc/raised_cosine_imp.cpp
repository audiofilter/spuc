
/*
    Copyright (C) 2014 Tony Kirke

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
//! \author Tony Kirke
// from directory: spuc_src
#include <cmath>
#include <spuc/spuc_defines.h>
#include <spuc/raised_cosine_imp.h>
namespace SPUC {
float_type raised_cosine_imp(float_type alpha, float_type xin, float_type rate,
                             long num_taps)
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
  } else {
    rc1 = (sin(x1) * cos(alpha * x1)) / (x1 * x2);
  }
  return (rc1);
}
}  // namespace SPUC
