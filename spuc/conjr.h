#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_template_functors
#include <spuc/spuc_types.h>
#include <spuc/complex.h>
namespace SPUC {
template <typename T> class conjr {
 public:
  static T conjd(T x) { return (x); }
};
// partial specialization
template <typename T> class conjr<complex<T> > {
 public:
  static complex<T> conjd(complex<T> x) { return (complex<T>(real(x), -imag(x))); }
};
}  // namespace SPUC
