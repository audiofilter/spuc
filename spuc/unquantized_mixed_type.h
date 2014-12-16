#ifndef SPUC_UNQUANTIZED_MIXED_TYPE
#define SPUC_UNQUANTIZED_MIXED_TYPE

// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_traits
#include <spuc/spuc_types.h>
namespace SPUC {
//! \file
//! \brief Determine type to use when mixing two types
//
//! \brief Determine type to use when mixing two types
//! \author Tony Kirke,  Copyright(c) 2005
//! \author Tony Kirke
//! \ingroup traits traits
// This template is used to look at two types used together
// in some mathematical expression
// and then figure out the floating point type
// input types                       Result type
// double + double                   = double
// double + long                     = double
// long   + long                     = double
// complex<Anything> + Anything      = complex<double>
template <typename T, typename D = double> class unquantized_mixed_type {
 public:
  typedef double dtype;
};
template <typename T, typename D> class unquantized_mixed_type<complex<T>, D> {
 public:
  typedef complex<double> dtype;
};
template <typename T, typename D> class unquantized_mixed_type<T, complex<D> > {
 public:
  typedef complex<double> dtype;
};
// template_instantiations: double,long
}  // namespace SPUC
#endif
