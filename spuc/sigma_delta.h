#ifndef SPUC_SIGMA_DELTA
#define SPUC_SIGMA_DELTA

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
//! \brief Simple 1st order All-digital Sigma Delta converter
//
//! \brief Simple 1st order All-digital Sigma Delta converter
//
//!    All-digital sigma delta converter
//!    Performs Sigma Delta function in digital domain
//!    for use when output will go to a (nbit_out) D/A converter.
//!    Default is 8 bits in, 1 bit out.
//!    After construction, call single() to get output.
//!    Multirate performed by calling single() with same input
//!    at the higher sampling rate.
//! \author Tony Kirke
//! \ingroup classes misc
class sigma_delta
{
	protected:
		signed long in;
		signed long acc;
		unsigned long mask;
	public:                         
		unsigned char nbit_out; 
		unsigned char nbit_in;
		
	//! Constructor
	sigma_delta(char nin=8, char nout=1);
	//! Output <= 8 bits
	signed char single(signed long in);
} ;
} // namespace SPUC
#endif
