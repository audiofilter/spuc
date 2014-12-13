#ifndef SPUC_QNOISE
#define SPUC_QNOISE

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
#include <spuc/complex.h>
namespace SPUC {
//! \file
//! \brief class to add quantization noise to signal
//
//! \brief class to add quantization noise to signal
//
//!   Bit width is specified in constructor. Default is 8 bits.
//!   add quantization noise but does not change underlying type of input
//!   for fundamental types
//!   Handles real and complex samples
//! \author Tony Kirke
//!  \ingroup template_functors misc sim
template <class Numeric>
class qnoise {
 protected:
  char size;  //! Number of bits <= 255
  float_type scale;
  float_type iscale;

 public:
  //! Quantize and limit signal to size bits
  //! Constructor
  qnoise(char h) : size(h) {
    scale = (float_type)((1 << (size - 1)));
    iscale = 1.0 / scale;
  }
  Numeric quant(Numeric x) {
    return ((Numeric)(iscale * floor(scale * (double)x + 0.5)));
  }
  Numeric operator()(Numeric x) { return (quant(x)); }
  complex<Numeric> operator()(complex<Numeric> x) {
    return (complex<Numeric>(quant(real(x)), quant(imag(x))));
  }
};
template <class T>
class qnoise<complex<T> > {
 protected:
  char size;  //! Number of bits <= 255
  float_type scale;
  float_type iscale;

 public:
  //! Quantize and limit signal to size bits
  //! Constructor
  qnoise(char h) : size(h) {
    scale = (float_type)((1 << (size - 1)));
    iscale = 1.0 / scale;
  }
  T quant(T x) { return ((T)(iscale * floor(scale * (double)x + 0.5))); }
  complex<T> operator()(complex<T> x) {
    return (complex<T>(quant(real(x)), quant(imag(x))));
  }
};

}  // namespace SPUC
#endif
