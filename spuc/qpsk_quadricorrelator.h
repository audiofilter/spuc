#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_real_template_functions
#include <spuc/spuc_types.h>
#include <spuc/complex.h>
namespace SPUC {
//! \file
//! \brief  QPSK Quadricorrelator frequency discriminator
//!  \author Tony Kirke,  Copyright(c) 2001
//!
//! \brief  QPSK Quadricorrelator frequency discriminator
//
//!   Hard_data - Hard decision (complex) data for current symbol
//!   Prev - Previous symbol (prior to hard decision)
//! \author Tony Kirke
//! \image html qpsk_quadricorrelator.png
//!	  \ingroup real_template_functions comm
//! \image html qpsk_quadricorrelator.gif
//! \image latex qpsk_quadricorrelator.eps
template <class T> T qpsk_quadricorrelator(complex<T> hard_data, complex<T> prev) {
  return (real(hard_data) * imag(prev) - imag(hard_data) * real(prev));
}
}  // namespace SPUC
