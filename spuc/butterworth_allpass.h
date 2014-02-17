#ifndef SPUC_BUTTERWORTH_ALLPASS
#define SPUC_BUTTERWORTH_ALLPASS

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
#include <cmath>
#include <spuc/smart_array.h>
namespace SPUC {
//! \file
//! \brief Calculate Allpass coefficients for halfband bireciprocal wave filter
//
//! \brief Calculate Allpass coefficients for halfband bireciprocal wave filter
//
//! assuming butterworth frequency response
//! \author Tony Kirke
//! \ingroup functions iir
//!  \author Tony Kirke,  Copyright(c) 2001 
void butterworth_allpass(smart_array<float_type>& a0, 
						 smart_array<float_type>& a1, int L);

  
} // namespace SPUC
#endif
