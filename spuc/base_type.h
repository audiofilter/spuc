#ifndef SPUC_BASE_TYPE
#define SPUC_BASE_TYPE

// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_traits
#include <spuc/spuc_typedefs.h>
#ifdef USE_STD_COMPLEX
#include <complex>
using std::complex;
#endif
namespace SPUC {
//! Trait classes for type transformations/conversions
//! \author Tony Kirke,  Copyright(c) 2005
//
//! \file
//! \brief Determine base class for complex, builtin, sint, etc, classes
//
//! \brief Determine base class for complex, builtin, sint, etc, classes
//! \author Tony Kirke
//! \ingroup traits traits
template <typename T> class base_type {
 public:
  typedef T btype;
};
template <typename T> class base_type<complex<T> > {
 public:
  typedef T btype;
};
#ifndef NO_BUILTIN
template <typename T> class base_type<builtin<T> > {
 public:
  typedef T btype;
};
#endif
}  // namespace SPUC
#endif
