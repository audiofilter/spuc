#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_template_functors
#include <spuc/spuc_types.h>
#include <cmath>
#include <spuc/complex.h>
#include <spuc/real_round.h>
namespace SPUC {
template <class Numeric> class rounder {
 public:
  static Numeric rounded(Numeric x, long bits) { return (real_round(x, bits)); }
};
// partial specialization
template <typename T> class rounder<complex<T> > {
 public:
  static complex<T> rounded(complex<T> x, long bits) {
    return (complex<T>(real_round(real(x), bits), real_round(imag(x), bits)));
  }
};
}  // namespace SPUC
