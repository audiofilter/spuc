#ifndef SPUC_MAGSQ
#define SPUC_MAGSQ

// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_template_functions
#include <spuc/spuc_types.h>
#include <cmath>
#include <spuc/base_type.h>
#include <spuc/magsqr.h>
namespace SPUC {
//! \file
//! \brief Templated Magnitude Squared function
//
//! \brief Templated Magnitude Squared function
//! template function that uses a class to allow template specialization
//! \author Tony Kirke
//! \ingroup template_functions misc
template <typename T> typename base_type<T>::btype magsq(T in) {
  typename base_type<T>::btype X = magsqr<T>::magsqd(in);
  return (X);
}
}  // namespace SPUC
#endif
