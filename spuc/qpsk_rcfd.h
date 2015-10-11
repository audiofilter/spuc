#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_real_template_functions
#include <spuc/spuc_types.h>
#include <spuc/complex.h>
namespace SPUC {
//! \file
//! \brief   QPSK Reduced complexity frequency discriminator
//! \author Tony Kirke,  Copyright(c) 2001
//!
//! \brief   QPSK Reduced complexity frequency discriminator
//
//!  using the
//!   "frequency matched filter" approach derived from the
//!   Maximum likelihood principle. see<p>
//!   A Reduced-complexity frequency discriminator derived from
//!   the maximum likelihood principle<p>  IEEE Transactions on
//!   Communications Oct. 1995<p>.
//!   FMF - output from frequency matched filter (must be
//!   done externally)
//!   Curr - current sample
//! \author Tony Kirke
//!	\ingroup real_template_functions comm
template <class T> T qpsk_rcfd(complex<T> fmf, complex<T> curr) {
  return (imag(curr) * real(fmf) - imag(fmf) * real(curr));
}
}  // namespace SPUC
