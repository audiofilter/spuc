#ifndef SPUC_CP_AFC
#define SPUC_CP_AFC

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
//!
//! \file
//! \brief Cross-Product frequency discriminator
//
//! \brief Cross-Product frequency discriminator
//
//! Prev - previous symbol
//! Curr - current symbol
//! \author Tony Kirke
//!	  \ingroup real_template_functions comm
template <class T> T cp_afc(complex<T> prev, complex<T> curr) 
{ 
  complex<T> rot(real(prev)+imag(prev),imag(prev)-real(prev));
  T dot = real(curr)*real(rot) + imag(curr)*imag(rot);
  T cross = imag(curr)*real(rot) - real(curr)*imag(rot);
  T afc = ((dot>=0) ? cross : -cross) - ((cross>=0) ? dot : -dot);
  return(afc);
}
} // namespace SPUC
#endif
