#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_real_template_functions
#include <spuc/spuc_types.h>
#include <spuc/complex.h>
namespace SPUC {
//! \file
//!  \brief Decision directed timing discriminator (QPSK)
//
//!  \brief Decision directed timing discriminator (QPSK)
//
//!   Runs at the symbol rate
//!   Curr - current symbol
//!   Hard_data - Hard decision for current symbol
//!   Prev - Previous symbol
//!   Prev_Hard_data - Hard decision for previous symbol
//! \author Tony Kirke
//! \image html dd_symbol.png
//!	  \ingroup real_template_functions comm
template <class T> T dd_symbol(complex<T> prev, complex<T> curr, complex<T> prev_hard_data, complex<T> hard_data) {
  return (real(curr * conj(prev_hard_data) - prev * conj(hard_data)));
}
// function_instantiations: long, double
}  // namespace SPUC
