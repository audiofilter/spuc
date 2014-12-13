#ifndef SPUC_QUANTIZE
#define SPUC_QUANTIZE

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
// from directory: spuc_template_functions
#include <spuc/spuc_types.h>
#include <cmath>
#include <spuc/quantized_type.h>
#include <spuc/quantizer.h>
namespace SPUC {
//! \file
//! \brief Templated Quantize function
//
//! \brief Templated Quantize function
//! template function that uses a class to allow template specialization
//! \author Tony Kirke
//! \ingroup template_functions misc
template <typename T>
typename quantized_type<T>::dtype quantize(T in) {
  typename quantized_type<T>::dtype X = quantizer<T>::quantized(in);
  return (X);
}
template <typename T>
T quantize_scale(float_type x, float_type ox, T y) {
  //  typename quantized_type<T>::dtype X =
  //  quantizer<T>::quantized_scale(x,ox,y);
  return (quantizer<T>::quantized_scale(x, ox, y));
}
}  // namespace SPUC
#endif
