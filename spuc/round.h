#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_template_functions
#include <spuc/spuc_types.h>
#include <cmath>
#include <spuc/rounder.h>
namespace SPUC {
//! \file
//! \brief Templated round function
//
//! \brief Templated round function
//! template function that uses a class to allow template specialization
//! \author Tony Kirke
//! \ingroup template_functions misc
template <class T> T round(T in, long bits) { return (rounder<T>::rounded(in, bits)); }
}  // namespace SPUC
