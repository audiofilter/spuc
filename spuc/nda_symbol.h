#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_real_template_functions
#include <spuc/spuc_types.h>
#include <spuc/complex.h>
namespace SPUC {
//! \file
//! \brief   Non-decision aided timing discriminator (Gardiner's algorithm)
//
//! \brief   Non-decision aided timing discriminator (Gardiner's algorithm)
//
//!   Runs at twice the symbol rate
//!   Curr - current sample
//!   Prev - Previous sample
//! \image html nda_timing.gif
//! \image latex nda_timing.eps
//! \author Tony Kirke
//!	  \ingroup real_template_functions comm
template <class T> T nda_symbol(complex<T> prev, complex<T> curr) {
  return (real(prev) * (real(prev) - real(curr)) + imag(prev) * (imag(prev) - imag(curr)));
}
}  // namespace SPUC
