#ifndef SPUC_IFFT
#define SPUC_IFFT

// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_functions
#include <spuc/spuc_types.h>
#include <spuc/complex.h>
#include <vector>
namespace SPUC {
//! \file
//! \brief inverse fourier transform
//

//! \brief inverse fast fourier transforms (IFFT)
//! \author Tony Kirke
//! \ingroup functions functions
void ifft(std::vector<complex<float_type> > y, int n);
}  // namespace SPUC
#endif
