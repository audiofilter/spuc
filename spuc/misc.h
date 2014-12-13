#ifndef SPUC_MISC
#define SPUC_MISC

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
#include <cmath>
#include <spuc/spuc_defines.h>
namespace SPUC {
//! \author Tony Kirke,  Copyright(c) 2001
//! \file
//! \brief Various basic math functions, reduce,erfc,swap, quicksort
//
//! \brief Exclusive or the bits in x together.
//! \author Tony Kirke
//! \ingroup functions functions
bool reduce(long x, long n);
//! \brief Standard erfc1 function
//! \author Tony Kirke
//! \ingroup functions functions
float_type erfc1(float_type x);
//! \brief Standard erf1 function
//! \author Tony Kirke
//! \ingroup functions functions
float_type erf1(float_type x);
//! \brief Swap two integers
//! \author Tony Kirke
//! \ingroup functions functions
void swap(int *a, int *b);
//! \brief Quicksort routine for array of integers
//! \author Tony Kirke
//! \ingroup functions functions
void quicksort(int *v, unsigned n);
}  // namespace SPUC
#endif
