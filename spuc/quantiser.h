#ifndef SPUC_QUANTISER
#define SPUC_QUANTISER

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
#include <spuc/spuc_types.h>
#include <cmath>
#include <spuc/complex.h>
#include <spuc/quantize.h>
#include <typeinfo>
namespace SPUC {
//! \file
//!   \brief ........
//
//!   \brief ........
//
//!   Class for .........
//!   Bit width is specified in constructor. Default is 8 bits.
//!   Output type is specified as template parameter.
//!   Handles real and complex samples
//! \author Tony Kirke
//! \author Tony Kirke
//!  \ingroup template_functors template_functors misc sim
template <class Numeric>
class quantiser {
 protected:
  char size;  //! Number of bits <= 8
  float_type scale;
  float_type iscale;

 public:
  //! Constructor
  quantiser(char h = 0) { set_bits(h); }
  void set_bits(char h) {
    size = h;
    iscale = 1.0;  // (float_type)((1<<size));
    scale = 1.0 / (float_type)((1 << size));
  }
  template <typename T>
  T operator()(T x) {
#ifndef ADD_QUANT
    return (x);
#else
    return (quantize_scale(scale, iscale, x));
#endif
  }
};
template <>
inline void quantiser<long>::set_bits(char h) {
  size = h;
  iscale = 1.0;
  scale = 1.0 / (float_type)((1 << size));
}
template <>
inline void quantiser<float_type>::set_bits(char h) {
  size = h;
  iscale = (float_type)((1 << size));
  scale = 1.0 / (float_type)((1 << size));
}

}  // namespace SPUC
#endif
