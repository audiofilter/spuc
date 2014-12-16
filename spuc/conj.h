#ifndef SPUC_CONJ
#define SPUC_CONJ

// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_template_functions
#include <spuc/spuc_types.h>
#include <cmath>
#include <spuc/base_type.h>
#include <spuc/conjr.h>
namespace SPUC {
//! \file
//! \brief Templated conjugate function
//
//! \brief Templated conjugate function
//! template function that uses a class to allow template specialization
//! \author Tony Kirke
//! \ingroup template_functions misc
template <typename T> T conj(T in) { return (conjr<T>::conjd(in)); }
}  // namespace SPUC
#endif
