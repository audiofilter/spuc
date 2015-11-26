#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_functions
#include <spuc/spuc_types.h>
#include <vector>
namespace SPUC {
//! \file
//! \brief inverse fourier transform
//

//! \brief inverse fast fourier transforms (IFFT)
//! \author Tony Kirke
//! \ingroup functions functions
void ifft(std::vector<std::complex<float_type> >& y, int n);
}  // namespace SPUC
