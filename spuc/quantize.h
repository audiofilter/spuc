#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
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
template <typename T> typename quantized_type<T>::dtype quantize(T in) {
  typename quantized_type<T>::dtype X = quantizer<T>::quantized(in);
  return (X);
}
template <typename T> T quantize_scale(float_type x, float_type ox, T y) {
  //  typename quantized_type<T>::dtype X = quantizer<T>::quantized_scale(x,ox,y);
  return (quantizer<T>::quantized_scale(x, ox, y));
}
}  // namespace SPUC
