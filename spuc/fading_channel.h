#ifndef SPUC_FADING_CHANNEL
#define SPUC_FADING_CHANNEL

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
#include <spuc/fir.h>
#include <spuc/noise.h>
namespace SPUC {
//! \file
//! \brief  A Class for simulating a FIR channel model
//!
//!  \brief  A Class for simulating a FIR channel model
//
//!  FIR Channel Model.
//!  Exponential decay delay line channel model
//!  Mean channel power is normalized
//!  Profiles are generated using gaussian pdf
//! \author Tony Kirke,  Copyright(c) 2001 
//! \author Tony Kirke
//!  \ingroup classes sim comm
class fading_channel 
{
 public:
  fir<complex<float_type>,complex<float_type> >  exp_decay;
	long taps;
	float_type delay_spread;
	noise tap_gain;

	// constructor
	fading_channel(long paths=1, float_type norm_delay_spread=1) {
		taps=paths;
		delay_spread = norm_delay_spread;
		exp_decay.set_size(taps);
		generate_channel();
	}
	void setup(float_type norm_delay_spread);
	void generate_channel();
	complex<float_type> update(const complex<float_type> s);
};
} // namespace SPUC
#endif
