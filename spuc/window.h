#ifndef SPUC_WINDOW
#define SPUC_WINDOW

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
#include <vector>
namespace SPUC {
//! \file
//! \brief Various FIR window functions: hamming,hanning,blackman,kaiser, chebyshev
//
//! \brief bessel function for kaiser window
//! \author Tony Kirke
//! \ingroup functions fir
float_type io(float_type x);
//! \brief hamming window \f$ w(n) = alpha + beta*cos( 2*\pi*(n-1)/(nf-1) )\f$
//! \author Tony Kirke
//!  \ingroup functions fir
std::vector<float_type> hamming(long nf,float_type alpha, float_type beta);
//! \brief hanning window \f$ w(n) = 0.5( 1 - cos( 2*\pi*n/(nf-1) )\f$
//! \author Tony Kirke
//!  \ingroup functions fir
std::vector<float_type> hanning(long nf);
//! \brief Blackman Window	\f$ w[x] = 0.42 - 0.5*cos(2*\pi*x/nf) + 0.08*cos(2*\pi*x/nf)\f$
//! \author Tony Kirke
//!  \ingroup functions fir
std::vector<float_type> blackman(long nf);
//! \brief kaiser window
//! \author Tony Kirke
//!  \ingroup functions fir
std::vector<float_type> kaiser(long nf, float_type beta);
//!  \brief dolph chebyshev window design
//! \author Tony Kirke
//!  \ingroup functions fir
std::vector<float_type> cheby(long nf, long n, long ieo, float_type dp, float_type df, float_type x0);
//! \brief chebyshev window
//
//! subroutine to generate chebyshev window parameters when
//! one of the three parameters nf,dp and df is unspecified
//! \author Tony Kirke
//!  \ingroup functions fir
void chebc(float_type nf, float_type dp, float_type df, float_type n,float_type x0);
} // namespace SPUC
#endif
