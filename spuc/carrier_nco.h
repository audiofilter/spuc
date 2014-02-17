#ifndef SPUC_CARRIER_NCO
#define SPUC_CARRIER_NCO

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
#include <spuc/complex.h>
namespace SPUC {
//! \file
//! \brief A specialization example of a sin/cosine look-up NCO
//
//! \brief A specialization example of a sin/cosine look-up NCO
//
//! with fixed quantizations
//! \author Tony Kirke
//! \author Tony Kirke
//! \image html carrier_nco.png
//! \ingroup classes comm
class carrier_nco
{
protected:
	unsigned long acc;
	unsigned long fcw;
	unsigned long new_fcw;
	unsigned long phase;
public:
	inline carrier_nco(void) {acc = fcw = new_fcw = phase = 0;}
	inline void set_frequency(unsigned long freq) { fcw = freq; }
	inline void reset_frequency(unsigned long freq) { new_fcw = fcw = freq; }
	inline long get_phase(void) { return(phase);}
	complex<long> clock(long loop_filter_out=0, int load=1);
};
} // namespace SPUC
#endif
