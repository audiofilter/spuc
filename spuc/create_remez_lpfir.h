#ifndef SPUC_CREATE_REMEZ_LPFIR
#define SPUC_CREATE_REMEZ_LPFIR

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
#include <spuc/fir_coeff.h>
namespace SPUC {
//! \file
//! \brief Calculate coefficients for lowpass FIR assuming equiripple frequency response
//
//! \brief Calculate coefficients for lowpass FIR assuming equiripple frequency response
//
//! \author Tony Kirke,  Copyright(c) 2001 
//! \author Tony Kirke
//! \ingroup functions fir
void create_remez_lpfir(fir_coeff<float_type>& remezfir, float_type edge, float_type fx, float_type wtx);
} // namespace SPUC
#endif
