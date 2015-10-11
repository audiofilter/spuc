#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_real_template_functions
#include <spuc/spuc_types.h>
#include <spuc/complex.h>
namespace SPUC {
//!
//! \file
//! \brief Cross-Product frequency discriminator
//
//! \brief Cross-Product frequency discriminator
//
//! Prev - previous symbol
//! Curr - current symbol
//! \author Tony Kirke
//!	  \ingroup real_template_functions comm
template <class T> T cp_afc(complex<T> prev, complex<T> curr) {
  complex<T> rot(real(prev) + imag(prev), imag(prev) - real(prev));
  T dot = real(curr) * real(rot) + imag(curr) * imag(rot);
  T cross = imag(curr) * real(rot) - real(curr) * imag(rot);
  T afc = ((dot >= 0) ? cross : -cross) - ((cross >= 0) ? dot : -dot);
  return (afc);
}
}  // namespace SPUC
