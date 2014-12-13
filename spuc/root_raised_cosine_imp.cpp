
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
#include <spuc/root_raised_cosine_imp.h>
namespace SPUC {
float_type root_raised_cosine_imp(float_type alpha, float_type xin,
                                  float_type rate, long num_taps)
//-----------------------------------------------------------------------
//       Calculates the square root raised cosine pulse shape given the
//		excess bandwidth value beta and the index.
//-----------------------------------------------------------------------
{
  float_type x1, x2, x3;
  float_type nom, denom;

  float_type xindx = xin - num_taps / 2;
  x1 = PI * xindx / rate;
  x2 = 4 * alpha * xindx / rate;
  x3 = x2 * x2 - 1;
  if (x3 != 0) {
    if (x1 != 0) {
      nom = cos((1 + alpha) * x1);
      nom += sin((1 - alpha) * x1) / (4 * alpha * xindx / rate);
    } else {
      nom = cos((1 + alpha) * x1);
      nom += (1 - alpha) * PI / (4 * alpha);
    }
    denom = x3 * PI;
  } else {
    if (alpha == 1) return (-1);
    x3 = (1 - alpha) * x1;
    x2 = (1 + alpha) * x1;
    nom = sin(x2) * (1 + alpha) * PI -
          cos(x3) * ((1 - alpha) * PI * rate) / (4 * alpha * xindx) +
          sin(x3) * rate * rate / (4 * alpha * xindx * xindx);
    denom = -32 * PI * alpha * alpha * xindx / rate;
  }
  return (4 * alpha * nom / denom);
}

}  // namespace SPUC
