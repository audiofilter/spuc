#ifndef SPUC_QPSK_DISCRIMINATORS
#define SPUC_QPSK_DISCRIMINATORS

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
#include <spuc/delay.h>
namespace SPUC {
//! \file
//! \brief A Class incorporating several symbol and carrier discriminators for QPSK
//  
//! \brief A Class incorporating several symbol and carrier discriminators for QPSK
//  
//! \author Tony Kirke
//! \ingroup classes comm
class qpsk_discriminators
{
public:
	int bpsk_mode;
	complex<long> fmf;
	complex<long> prev_sam,prev_sym,data;
	complex<long> hard_decision_prev,decision;
	delay< complex<long> > hard_decision_delay,timing_disc_delay;

	void update(complex<long> data_in, complex<long> decision_in, int sym_pls);
	void sample(complex<long> fmf_in, complex<long> data_in, complex<long> decision_in, int sym_pls);
	qpsk_discriminators(int bpsk=0) : hard_decision_delay(2), timing_disc_delay(3)
		{ bpsk_mode = bpsk;}
	void set_mode(int bpsk=0) { bpsk_mode = bpsk;}
	long cross_prod_afc(void);
	long quad(void);
	long rcfd(void);
	long dd_timing_disc(void);
	long nda_timing_disc(void);
	long symbol_lock_out(void);
	long pll_disc(void);
};
} // namespace SPUC
#endif
