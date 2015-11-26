#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_functions
#include <spuc/spuc_types.h>
#include <spuc/complex.h>
namespace SPUC {
//! \file
//! \author Tony Kirke,  Copyright(c) 2001
//! \brief Various standard math functions not available elsewhere
//
//! function for hyperbolic inverse cosine of x
//! \author Tony Kirke
//! \ingroup functions functions
float_type coshin(float_type x);
//! function for inverse cosine of x
//! \author Tony Kirke
//! \ingroup functions functions
float_type arccos(float_type x);
//! function for hyperbolic cosine of x
//! \author Tony Kirke
//! \ingroup functions functions
float_type cosh(float_type x);
//! function for hyperbolic sine of x
//! \author Tony Kirke
//! \ingroup functions functions
float_type sinh(float_type x);
//! cos function with various overloads
//! \author Tony Kirke
//! \ingroup functions functions
complex<float_type> cos(complex<float_type> x);
//! exp function with various overloads
//! \author Tony Kirke
//! \ingroup functions functions
complex<float_type> exp(complex<float_type> x);
//! convert from polar to cartesian
//! \author Tony Kirke
//! \ingroup functions functions
complex<float_type> polar(float_type amp, float_type arg);
//! complex exponential
inline complex<float> expj(float x) { return (complex<float>(std::cos(x), std::sin(x))); }
inline complex<double> expj(double x) { return (complex<double>(std::cos(x), std::sin(x))); }
}  // namespace SPUC
