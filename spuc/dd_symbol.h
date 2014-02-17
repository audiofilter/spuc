#ifndef SPUC_DD_SYMBOL
#define SPUC_DD_SYMBOL

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
// from directory: spuc_real_template_functions
#include <spuc/spuc_types.h>
#include <spuc/complex.h>
namespace SPUC {
//! \file
//!  \brief Decision directed timing discriminator (QPSK)
//
//!  \brief Decision directed timing discriminator (QPSK)
//
//!   Runs at the symbol rate
//!   Curr - current symbol
//!   Hard_data - Hard decision for current symbol
//!   Prev - Previous symbol
//!   Prev_Hard_data - Hard decision for previous symbol
//! \author Tony Kirke
//! \image html dd_symbol.png
//!	  \ingroup real_template_functions comm
template <class T> T dd_symbol(complex<T> prev, complex<T> curr,
							   complex<T> prev_hard_data, complex<T> hard_data) 
{
	return(real(curr*conj(prev_hard_data) - prev*conj(hard_data)));
}
// function_instantiations: long, double
} // namespace SPUC
#endif
