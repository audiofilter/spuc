#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_real_template_functions
#include <spuc/spuc_types.h>
#include <spuc/complex.h>
namespace SPUC {
//! \file
//! \brief   BPSK Quadricorrelator frequency discriminator
//
//! \brief   BPSK Quadricorrelator frequency discriminator
//
//!   Hard_data - Hard decision (complex) data for current symbol
//!   Prev - Previous symbol (prior to hard decision)
//! \author Tony Kirke
//!	  \ingroup real_template_functions comm
template <class T> T bpsk_quadricorrelator(complex<T> hard_data, complex<T> prev) {
  return (-real(hard_data) * imag(prev));
}
}  // namespace SPUC
