#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
#include <spuc/spuc_types.h>
#include <complex>
#include <vector>
namespace SPUC {
//! \file
//! \brief discrete fourier transforms (IDFT and DFT)

//! \brief inverse discrete fourier transforms (IDFT)
//! \author Tony Kirke
//! \ingroup functions functions
  void idft(std::vector<std::complex<float_type> >& y, int n);
//! \brief discrete fourier transforms (DFT)
//! \author Tony Kirke
//! \ingroup functions functions
  void dft(std::vector<std::complex<float_type> >& y, int n);
}  // namespace SPUC
