#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_traits
#include <spuc/spuc_types.h>
#include <spuc/spuc_typedefs.h>
namespace SPUC {
//! \file
//! \brief Determine quantized version of particular type, i.e complex<double> -> complex<long>, etc
//
//! \brief Determine quantized version of particular type, i.e complex<double> -> complex<long>, etc
//! \author Tony Kirke,  Copyright(c) 2005
//! \author Tony Kirke
//! \ingroup traits traits
template <typename T> class quantized_type {
 public:
  typedef long dtype;
};
template <typename T> class quantized_type<complex<T> > {
 public:
  typedef complex<long> dtype;
};
// template_instantiations: double, long, int_s
}  // namespace SPUC
