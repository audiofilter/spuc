#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
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
