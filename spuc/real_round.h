#ifndef SPUC_REAL_ROUND
#define SPUC_REAL_ROUND

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
template <class T>
T real_round(T in, long bits);
template <>
inline long real_round(long in, long bits) {
  float scale = 1.0 / (float)(1 << bits);
  return (SPUC_TOLONG(scale * in));
}
template <>
inline float real_round(float in, long bits) {
  float scale = 1.0 / (float)(1 << bits);
  return (scale * in);
}
template <>
inline int real_round(int in, long bits) {
  double scale = 1.0 / (double)(1 << bits);
  return (SPUC_TOLONG(scale * in));
}
template <>
inline double real_round(double in, long bits) {
  double scale = 1.0 / (double)(1 << bits);
  return (scale * in);
}
}  // namespace SPUC
#endif
