#ifndef SPUC_ELLIPTIC_IIR
#define SPUC_ELLIPTIC_IIR

// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_functions
#include <spuc/spuc_types.h>
#include <iostream>
#include <fstream>
#include <spuc/spuc_defines.h>
#include <cmath>
#include <spuc/iir_coeff.h>
namespace SPUC {
//! \file
//! \brief Calculate coefficients for IIR assuming elliptic frequency response
//
//! \brief Calculate coefficients for IIR assuming elliptic frequency response
//
//! \author Tony Kirke,  Copyright(c) 2001
//! \author Tony Kirke
//! \ingroup functions iir
void elliptic_iir(iir_coeff& filt, float_type fcd, bool lpf, float_type fstop, float_type stopattn, float_type ripple);
//! get roots in Lamda plane
float_type lamda_plane(float_type k, float_type m, int n, float_type eps);
//! calculate s plane poles and zeros
void s_plane(std::vector<complex<float_type> >& roots, std::vector<complex<float_type> >& zeros, bool lpf, int n,
             float_type u, float_type m, float_type k, float_type Kk, float_type wc);
float_type ellik(float_type phi, float_type k);
float_type ellpk(float_type k);
int ellpj(float_type u, float_type m, float_type& sn, float_type& cn, float_type& dn);
float_type msqrt(float_type u);
}  // namespace SPUC
#endif
