
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
#include <spuc/farrow_upsampler.h>
namespace SPUC {
farrow_upsampler::farrow_upsampler(int order) : INTERP(order) {
  time_offset = 0;
}
int farrow_upsampler::need_sample(float_type t_inc, float_type x) {
  if (time_offset + t_inc >= 1.0) {
	INTERP.input(x);
	return(1);
  } else {
	return(0);
  }
}
float_type farrow_upsampler::output(float_type t_inc) {
  time_offset += t_inc;
  if (time_offset >= 1.0) {
	time_offset -= 1.0;
  }
  return(INTERP.rephase(time_offset));
}
} // namespace SPUC
