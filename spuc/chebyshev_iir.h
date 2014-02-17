#ifndef SPUC_CHEBYSHEV_IIR
#define SPUC_CHEBYSHEV_IIR

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
// from directory: spuc_functions
#include <spuc/spuc_types.h>
#include <spuc/spuc_defines.h>
#include <spuc/iir_coeff.h>
namespace SPUC {
//! \file
//! \brief Calculate coefficients for IIR assuming chebyshev frequency response
//
//! \brief Calculate coefficients for IIR assuming chebyshev frequency response
//
//! \author Tony Kirke,  Copyright(c) 2001 
//! \author Tony Kirke
//! \ingroup functions iir
void chebyshev_iir(iir_coeff& cheb, float_type fcd, bool lpf, float_type ripple);
void chebyshev_s(smart_array<complex<float_type> > poles,
		 smart_array<complex<float_type> > zeros, bool lpf, float_type wp, float_type epi, long n, long n2);
} // namespace SPUC
#endif
