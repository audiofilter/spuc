#ifndef SPUC_MAX_PN
#define SPUC_MAX_PN

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
namespace SPUC {
//! 
//! \file
//! \brief Maximal Length Pseudorandom sequence generator
//
//! \brief Maximal Length Pseudorandom sequence generator
//
//!    Simple implementation of a maximal length pseudorandom sequence
//!    used for spread spectrum PN generation, BER testing etc.
//!    G is the generator
//!    Len is the PN length (must be 2^N - 1)
//!    Init is an initialization seed
//!    Two methods supported 
//!    out : exclusive or (XOR) shift register with Generator
//!    out1 : feedback with XOR reduction
//!    Note: G, LEN must be correct (need to get from book).
//! \author Tony Kirke
//! \ingroup classes misc
class max_pn
{
	protected:
		int lenp1;
		int gen;                                          
		int u;

	public:
		//! Constructor
		//! Constructor
		max_pn(int g=0x006d, int len=63, int init=-1) {
			gen = g;
			lenp1 = len+1;
			u = init;
		}
		//		max_pn(int g=0x074d, int len=1023, int init=-1) : gen(g), lenp1(len+1), u(init) {;}
		//! Reset
		void reset() { u = -1; }
		//! Get output (fast method)
		signed char out(); //! Fast method
		bool get_bit(); //! returns {0,1} instead of {-1,1}
		//! Get output (alternative method)
		signed char out1();
		int state() { return(u); }
} ; 
} // namespace SPUC
#endif
