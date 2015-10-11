#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
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
template <class Numeric> class qnoise {
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
  Numeric quant(Numeric x) { return ((Numeric)(iscale * floor(scale * (double)x + 0.5))); }
  Numeric operator()(Numeric x) { return (quant(x)); }
  complex<Numeric> operator()(complex<Numeric> x) { return (complex<Numeric>(quant(real(x)), quant(imag(x)))); }
};
template <class T> class qnoise<complex<T> > {
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
  complex<T> operator()(complex<T> x) { return (complex<T>(quant(real(x)), quant(imag(x)))); }
};

}  // namespace SPUC
