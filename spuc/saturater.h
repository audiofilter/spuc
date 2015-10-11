#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_template_functors
#include <spuc/spuc_types.h>
#include <cmath>
#include <spuc/complex.h>
#include <spuc/real_saturate.h>
namespace SPUC {
template <class Numeric> class saturater {
 public:
  static Numeric saturated(Numeric x, long bits) { return (real_saturate(x, bits)); }
};
// partial specialization
template <typename T> class saturater<complex<T> > {
 public:
  static complex<T> saturated(complex<T> x, long bits) {
    return (complex<T>(real_saturate(real(x), bits), real_saturate(imag(x), bits)));
  }
};
}  // namespace SPUC
