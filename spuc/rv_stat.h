#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_classes
#include <spuc/spuc_types.h>
#include <spuc/dsp_functions/spuc_math.h>
namespace SPUC {
//! \file
//! \brief a basic random Variable Statistics Class
//
//! \author Tony Kirke
//! \ingroup classes misc
class rv_stat {
 protected:
  float_type count;
  float_type av;
  float_type sq;
  float_type min_abs;
  float_type max_abs;

 public:
  // Constructor
  rv_stat();
  void update(float_type x);
  inline float_type average() {
    if (count > 0)
      return (av / count);
    else
      return (0);
  }
  inline float_type mean_sq() {
    if (count > 0)
      return (sq / count);
    else
      return (0);
  }
  inline float_type rms() { return (std::sqrt(sq / count)); }
  inline float_type var() {
    if (count > 0)
      return (sq / count - (av * av / (count * count)));
    else
      return (0);
  }
  inline float_type std() { return (std::sqrt(var())); }
  inline float_type minimum() { return (min_abs); }
  inline float_type maximum() { return (max_abs); }
};
}  // namespace SPUC
