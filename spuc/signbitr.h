#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_template_functors
#include <spuc/spuc_types.h>
#include <spuc/complex.h>
namespace SPUC {
template <typename T> class signbitr {
 public:
  static T signbitd(T x) { return (((float_type)x < (float_type)0) ? (T)-1 : (T)1); }
};
// partial specialization
template <typename T> class signbitr<complex<T> > {
 public:
  static complex<T> signbitd(complex<T> x) {
    return (complex<T>(signbitr<T>::signbitd(real(x)), signbitr<T>::signbitd(imag(x))));
  }
};
}  // namespace SPUC
