#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_template_functions
#include <spuc/spuc_types.h>
#include <cmath>
#include <spuc/signbitr.h>
namespace SPUC {
//! \file
//! \brief Templated signbit function
//
//! \brief Templated signbit function
//! template function that uses a class to allow template specialization
//! \author Tony Kirke
//! \ingroup template_functions misc
template <typename T> T signbit(T in) { return (signbitr<T>::signbitd(in)); }
}  // namespace SPUC
