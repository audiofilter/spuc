#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_template_functions
#include <spuc/spuc_types.h>
#include <cmath>
#include <spuc/saturater.h>
namespace SPUC {
//! \file
//! \brief Templated saturate function
//
//! \brief Templated saturate function
//! template function that uses a class to allow template specialization
//! \author Tony Kirke
//! \ingroup template_functions misc
template <class T> T saturate(T in, long bits) { return (saturater<T>::saturated(in, bits)); }
}  // namespace SPUC
