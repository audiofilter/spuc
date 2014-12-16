#ifndef SPUC_UNQUANTIZED_TYPE
#define SPUC_UNQUANTIZED_TYPE

// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_traits
#include <spuc/spuc_types.h>
namespace SPUC {
//! \file
//! \brief Determine unquantized version of particular type, i.e complex<long>
//-> complex<double>, etc
//
//! \brief Determine unquantized version of particular type, i.e complex<long>
//-> complex<double>, etc
//! \author Tony Kirke,  Copyright(c) 2005
//! \author Tony Kirke
//! \ingroup traits traits
template <typename T> class unquantized_type {
 public:
  typedef double dtype;
};
template <typename T> class unquantized_type<complex<T> > {
 public:
  typedef complex<double> dtype;
};
// template_instantiations: double, long, int_s
}  // namespace SPUC
#endif
