#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_real_template_functions
#include <spuc/spuc_types.h>
#include <spuc/complex.h>
namespace SPUC {
//! \file
//! \brief Decision directed carrier phase discriminator for BPSK
//
//! \brief Decision directed carrier phase discriminator for BPSK
//
//!   Runs at the symbol rate
//!   Curr - current symbol
//!   Hard_data - Hard decision for current symbol
//! \author Tony Kirke
//!	  \ingroup real_template_functions comm
template <class T> T bpsk_dd_phase(complex<T> curr, complex<T> hard_data) { return (-imag(curr) * real(hard_data)); }
}  // namespace SPUC
