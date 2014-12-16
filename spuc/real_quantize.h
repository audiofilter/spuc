#ifndef SPUC_REAL_QUANTIZE
#define SPUC_REAL_QUANTIZE

// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_real_template_functions
#include <spuc/spuc_types.h>
#include <cmath>
namespace SPUC {
//! \file
//! \brief Templated quantize function
//
//! \brief Templated quantize function
//! \author Tony Kirke
//! \ingroup real_template_functions misc
template <class T> long real_quantize(T in) { return (SPUC_TOLONG(in)); }
}  // namespace SPUC
#endif
