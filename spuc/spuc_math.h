#ifndef SPUC_SPUC_MATH
#define SPUC_SPUC_MATH

// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_functions
#include <spuc/spuc_types.h>
#include <spuc/complex.h>
namespace SPUC {
//! \file
//! \author Tony Kirke,  Copyright(c) 2001
//! \brief Various standard math functions not available elsewhere
//
//! \brief sqrt
//! \author Tony Kirke
//! \ingroup functions functions
float_type sqrt(float_type x);
//! \brief sqrt
//! \author Tony Kirke
//! \ingroup functions functions
complex<float_type> sqrt(complex<float_type> x);
//! \brief sqrt
//! \author Tony Kirke
//! \ingroup functions functions
complex<float_type> sqrt(complex<long> x);
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
float_type cos(float_type cos);
//! cos function with various overloads
//! \author Tony Kirke
//! \ingroup functions functions
complex<float_type> cos(complex<float_type> x);
//! exp function with various overloads
//! \author Tony Kirke
//! \ingroup functions functions
complex<float_type> exp(complex<float_type> x);
//! magnitude of a complex number
//! \author Tony Kirke
//! \ingroup functions functions
inline float_type hypot(complex<float_type> z) { return sqrt(magsq(z)); }
//! convert from polar to cartesian
//! \author Tony Kirke
//! \ingroup functions functions
complex<float_type> polar(float_type amp, float_type arg);
//! complex exponential
inline complex<float> expj(float x) { return (complex<float>(std::cos(x), std::sin(x))); }
inline complex<double> expj(double x) { return (complex<double>(std::cos(x), std::sin(x))); }
}  // namespace SPUC
#endif
