#ifndef SPUC_QPSK_QUADRICORRELATOR
#define SPUC_QPSK_QUADRICORRELATOR

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
//! \brief  QPSK Quadricorrelator frequency discriminator
//!  \author Tony Kirke,  Copyright(c) 2001
//!
//! \brief  QPSK Quadricorrelator frequency discriminator
//
//!   Hard_data - Hard decision (complex) data for current symbol
//!   Prev - Previous symbol (prior to hard decision)
//! \author Tony Kirke
//! \image html qpsk_quadricorrelator.png
//!	  \ingroup real_template_functions comm
//! \image html qpsk_quadricorrelator.gif
//! \image latex qpsk_quadricorrelator.eps
template <class T>
T qpsk_quadricorrelator(complex<T> hard_data, complex<T> prev) {
  return (real(hard_data) * imag(prev) - imag(hard_data) * real(prev));
}
}  // namespace SPUC
#endif
