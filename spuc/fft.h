#ifndef SPUC_FFT
#define SPUC_FFT

// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_functions
#include <spuc/spuc_types.h>
#include <spuc/complex.h>
#include <vector>
namespace SPUC {
//! \file
//! \brief fast fourier transform
//

//! \brief fast fourier transforms (FFT)
//! \author Tony Kirke
//! \ingroup functions functions
void fft(std::vector<complex<float_type> > y, int n);
}  // namespace SPUC
#endif
