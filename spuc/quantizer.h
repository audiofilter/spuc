#ifndef SPUC_QUANTIZER
#define SPUC_QUANTIZER

/*
    Copyright (C) 2014 Tony Kirke

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
// from directory: spuc_template_functors
#include <spuc/spuc_types.h>
#include <cmath>
#include <spuc/complex.h>
#include <spuc/real_quantize.h>
namespace SPUC {
template <class Numeric> class quantizer
{
public:
  static long quantized(Numeric x) {
	return(real_quantize(x));
  }
  static long quantized_scale(float_type x, float_type ox, Numeric y) {
	return((long)(ox*real_quantize(x*y)));
  }
};
// partial specialization
template <typename T> class quantizer<complex<T> > {
public:
  static complex<long> quantized(complex<T> x) {
	return(complex<long>(real_quantize(real(x)),real_quantize(imag(x))));
  }
  static complex<long> quantized_scale(float_type x, 
									   float_type ox,
									   complex<T> y) {
	return(complex<long>((long)(ox*real_quantize(real(x*y))),
						 (long)(ox*real_quantize(imag(x*y)))));
  }
};
} // namespace SPUC
#endif
