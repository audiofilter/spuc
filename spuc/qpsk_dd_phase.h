#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_real_template_functions
#include <spuc/spuc_types.h>
#include <spuc/complex.h>
namespace SPUC {
//! \file
//! \brief   Decision directed carrier phase discriminator for QPSK
//
//! \brief   Decision directed carrier phase discriminator for QPSK
//
//!   Runs at the symbol rate
//!   Curr - current symbol
//!   Hard_data - Hard decision for current symbol
//! \author Tony Kirke
//! \image html qpsk_dd_phase.png
//!	\ingroup real_template_functions comm
//! \image html qpsk_dd_phase.gif
//! \image latex qpsk_dd_phase.eps
template <class T> T qpsk_dd_phase(complex<T> curr, complex<T> hard_data) { return (-imag(curr * conj(hard_data))); }
}  // namespace SPUC
