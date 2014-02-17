
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
// from directory: spuc_templates
#include <spuc/vco.h>
#include <spuc/spuc_math.h>
#include <spuc/int_s.h>
#include <spuc/complex.h>
namespace SPUC {
template <> int_s vco<int_s>::get_phase(void) { return(phase);}
template <> complex<int_s> vco<int_s>::clock() {
  acc += new_fcw;
  phase = acc >> (long)(32-phase_bits); // truncate
  float arg = TWOPI*((float)phase)/phase_bits;
  complex<float> x = ((float)amp)*expj(arg);
  return(complex<int_s>(SPUC_TOLONG(real(x)),SPUC_TOLONG(imag(x))));
}
template <> complex<int_s> vco<int_s>::clock(int_s loop_filter_out) {
  new_fcw = fcw + loop_filter_out;
  return(clock());
}
} // namespace SPUC
