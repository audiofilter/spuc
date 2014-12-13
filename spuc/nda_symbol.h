#ifndef SPUC_NDA_SYMBOL
#define SPUC_NDA_SYMBOL

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
//! \brief   Non-decision aided timing discriminator (Gardiner's algorithm)
//
//! \brief   Non-decision aided timing discriminator (Gardiner's algorithm)
//
//!   Runs at twice the symbol rate
//!   Curr - current sample
//!   Prev - Previous sample
//! \image html nda_timing.gif
//! \image latex nda_timing.eps
//! \author Tony Kirke
//!	  \ingroup real_template_functions comm
template <class T>
T nda_symbol(complex<T> prev, complex<T> curr) {
  return (real(prev) * (real(prev) - real(curr)) +
          imag(prev) * (imag(prev) - imag(curr)));
}
}  // namespace SPUC
#endif
