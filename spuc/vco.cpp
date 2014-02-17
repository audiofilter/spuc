
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
#include <spuc/complex.h>
namespace SPUC {
template <> float vco<float>::get_phase(void) { return(acc);}
template <> double vco<double>::get_phase(void) { return(acc);}
template <> int vco<int>::get_phase(void) { return(phase);}
template <> long vco<long>::get_phase(void) { return(phase);}

template <> complex<float> vco<float>::clock() {
		acc += new_fcw;
		if (acc > TWOPI) acc -= TWOPI;
		if (acc < -TWOPI) acc += TWOPI;
		return(expj(acc));
}
template <> complex<float> vco<float>::clock(float loop_filter_out) {
	load(loop_filter_out);
	return(clock());
}
template <> complex<long> vco<long>::clock() {
  acc += new_fcw;
  phase = acc >> (32-phase_bits); // truncate
  float arg = TWOPI*phase/phase_bits;
  complex<float> x = ((float)amp)*expj(arg);
  return(complex<long>(SPUC_TOLONG(real(x)),SPUC_TOLONG(imag(x))));
}
template <> complex<long> vco<long>::clock(long loop_filter_out) {
  new_fcw = fcw + loop_filter_out;
  return(clock());
}
/////////////////
template <> complex<double> vco<double>::clock() {
		acc += new_fcw;
		if (acc > TWOPI) acc -= TWOPI;
		if (acc < -TWOPI) acc += TWOPI;
		return(expj(acc));
}
template <> complex<double> vco<double>::clock(double loop_filter_out) {
	load(loop_filter_out);
	return(clock());
}
template <> complex<int> vco<int>::clock() {
  acc += new_fcw;
  phase = acc >> (32-phase_bits); // truncate
  double arg = TWOPI*phase/phase_bits;
  complex<double> x = ((double)amp)*expj(arg);
  return(complex<int>(SPUC_TOLONG(real(x)),SPUC_TOLONG(imag(x))));
}
template <> complex<int> vco<int>::clock(int loop_filter_out) {
  new_fcw = fcw + loop_filter_out;
  return(clock());
}
} // namespace SPUC
