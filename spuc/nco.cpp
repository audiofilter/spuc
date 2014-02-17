
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
#include <spuc/spuc_defines.h>
#include <spuc/nco.h>
namespace SPUC {

nco::nco(long bits) {
			acc = fcw = new_fcw = phase = 0;
			mask_bits = MASK_NEG_HI(bits);
}
long nco::clock() {
		acc += new_fcw;
		phase = acc & mask_bits; // truncate 
		return(phase);
}
long nco::clock(long loop_filter_out) {
		new_fcw = fcw + loop_filter_out;
		return(clock());
}
} // namespace SPUC
