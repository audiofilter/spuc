#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_template_functors
#include <spuc/spuc_types.h>
#include <cmath>
#include <spuc/complex.h>
#include <spuc/real_quantize.h>
namespace SPUC {
template <class Numeric> class quantizer {
 public:
  static long quantized(Numeric x) { return (real_quantize(x)); }
  static long quantized_scale(float_type x, float_type ox, Numeric y) { return ((long)(ox * real_quantize(x * y))); }
};
// partial specialization
template <typename T> class quantizer<complex<T> > {
 public:
  static complex<long> quantized(complex<T> x) {
    return (complex<long>(real_quantize(real(x)), real_quantize(imag(x))));
  }
  static complex<long> quantized_scale(float_type x, float_type ox, complex<T> y) {
    return (complex<long>((long)(ox * real_quantize(real(x * y))), (long)(ox * real_quantize(imag(x * y)))));
  }
};
}  // namespace SPUC
