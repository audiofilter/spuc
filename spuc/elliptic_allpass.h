#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_functions
#include <spuc/spuc_types.h>
#include <spuc/spuc_defines.h>
#include <cmath>
#include <vector>
namespace SPUC {
//! \file
//! \brief Calculate Allpass coefficients for halfband bireciprocal wave filter
//
//! \brief Calculate Allpass coefficients for halfband bireciprocal wave filter
//
//! assuming elliptic frequency response
//! \author Tony Kirke
//! \ingroup functions iir
//!  \author Tony Kirke,  Copyright(c) 2001
void elliptic_allpass(std::vector<float_type>& a0, std::vector<float_type>& a1, float_type fp, int L);

}  // namespace SPUC
