
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
#include <spuc/rv_stat.h>
#include <spuc/spuc_defines.h>
#include <cfloat>
namespace SPUC {
rv_stat::rv_stat() {
  count = 0;
  av = 0;
  sq = 0;
  min_abs = (float_type)(FLT_MAX);
  max_abs = 0;
}
void rv_stat::update(float_type x) {
  count += 1.0;
  av += x;
  sq += SQR(x);
  min_abs = MIN(ABS(min_abs),x);
  max_abs = MAX(ABS(max_abs),x);
}
} // namespace SPUC
