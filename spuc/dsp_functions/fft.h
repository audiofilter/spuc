#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_functions
#include <spuc/spuc_types.h>
#include <complex>
#include <vector>
namespace SPUC {
//! \file
//! \brief fast fourier transform
//

//! \brief fast fourier transforms (FFT)
//! \author Tony Kirke
//! \ingroup functions functions
void fft(std::vector<std::complex<float_type> >& y, int n);
}  // namespace SPUC
