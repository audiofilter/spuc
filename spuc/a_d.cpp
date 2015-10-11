// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_src
#include <cmath>
#include <spuc/complex.h>
#include <spuc/a_d.h>
namespace SPUC {
//! Constructor
a_d::a_d(char h) : size(h) {
  max = ((1 << (size - 1)) - 1);
  min = ~max;
}
complex<long> a_d::clock(complex<float_type> x) { return (complex<long>(clock(real(x)), clock(imag(x)))); }
//! Quantize and limit signal to size bits
long a_d::clock(float_type x) {
  long quant;
  quant = (long)floor(x + 0.5);
  if (quant > max) quant = max;
  if (quant < min) quant = min;
  return (quant);
}

}  // namespace SPUC
