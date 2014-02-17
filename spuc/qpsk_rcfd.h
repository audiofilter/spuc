#ifndef SPUC_QPSK_RCFD
#define SPUC_QPSK_RCFD

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
//! \brief   QPSK Reduced complexity frequency discriminator
//! \author Tony Kirke,  Copyright(c) 2001 
//! 
//! \brief   QPSK Reduced complexity frequency discriminator
//
//!  using the
//!   "frequency matched filter" approach derived from the 
//!   Maximum likelihood principle. see<p>
//!   A Reduced-complexity frequency discriminator derived from
//!   the maximum likelihood principle<p>  IEEE Transactions on
//!   Communications Oct. 1995<p>.
//!   FMF - output from frequency matched filter (must be
//!   done externally)
//!   Curr - current sample
//! \author Tony Kirke
//!	\ingroup real_template_functions comm
template <class T> T qpsk_rcfd(complex<T> fmf, complex<T> curr) 
{
  return(imag(curr)*real(fmf) - imag(fmf)*real(curr));
}
} // namespace SPUC
#endif
