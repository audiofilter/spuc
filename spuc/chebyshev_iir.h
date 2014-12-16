#ifndef SPUC_CHEBYSHEV_IIR
#define SPUC_CHEBYSHEV_IIR

// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_functions
#include <spuc/spuc_types.h>
#include <spuc/spuc_defines.h>
#include <spuc/iir_coeff.h>
namespace SPUC {
//! \file
//! \brief Calculate coefficients for IIR assuming chebyshev frequency response
//
//! \brief Calculate coefficients for IIR assuming chebyshev frequency response
//
//! \author Tony Kirke,  Copyright(c) 2001
//! \author Tony Kirke
//! \ingroup functions iir
void chebyshev_iir(iir_coeff& cheb, float_type fcd, bool lpf, float_type ripple);
void chebyshev_s(std::vector<complex<float_type> >& poles, std::vector<complex<float_type> >& zeros, bool lpf,
                 float_type wp, float_type epi, long n, long n2);
}  // namespace SPUC
#endif
