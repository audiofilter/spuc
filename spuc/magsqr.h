#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_template_functors
#include <spuc/spuc_types.h>
#include <spuc/complex.h>
namespace SPUC {
template <typename T> class magsqr {
 public:
  static T magsqd(T x) { return (x * x); }
};
// partial specialization
template <typename T> class magsqr<complex<T> > {
 public:
  static T magsqd(complex<T> x) { return (real(x) * real(x) + imag(x) * imag(x)); }
};
}  // namespace SPUC
