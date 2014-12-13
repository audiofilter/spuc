#ifndef SPUC_IDFT
#define SPUC_IDFT

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
#include <spuc/complex.h>
#include <vector>
namespace SPUC {
//! \file
//! \brief discrete fourier transforms (IDFT and DFT)
//

//! \brief inverse discrete fourier transforms (IDFT)
//! \author Tony Kirke
//! \ingroup functions functions
void idft(std::vector<complex<float_type> > y, int n);
//! \brief discrete fourier transforms (DFT)
//! \author Tony Kirke
//! \ingroup functions functions
void dft(std::vector<complex<float_type> > y, int n);
} // namespace SPUC
#endif
