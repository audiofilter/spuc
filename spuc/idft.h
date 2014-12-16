#ifndef SPUC_IDFT
#define SPUC_IDFT

// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
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
}  // namespace SPUC
#endif
