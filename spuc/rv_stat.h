#ifndef SPUC_RV_STAT
#define SPUC_RV_STAT

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
// from directory: spuc_classes
#include <spuc/spuc_types.h>
#include <spuc/spuc_math.h>
namespace SPUC {
//! \file
//! \brief a basic random Variable Statistics Class
//
//! \brief a basic random Variable Statistics Class
//
//! \author Tony Kirke
//! \ingroup classes misc
class rv_stat {
 protected:
  float_type count;
  float_type av;
  float_type sq;
  float_type min_abs;
  float_type max_abs;

 public:
  // Constructor
  rv_stat();
  void update(float_type x);
  inline float_type average() {
    if (count > 0)
      return (av / count);
    else
      return (0);
  }
  inline float_type mean_sq() {
    if (count > 0)
      return (sq / count);
    else
      return (0);
  }
  inline float_type rms() { return (sqrt(sq / count)); }
  inline float_type var() {
    if (count > 0)
      return (sq / count - (av * av / (count * count)));
    else
      return (0);
  }
  inline float_type std() { return (sqrt(var())); }
  inline float_type minimum() { return (min_abs); }
  inline float_type maximum() { return (max_abs); }
};
}  // namespace SPUC
#endif
