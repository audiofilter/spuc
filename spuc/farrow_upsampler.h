#ifndef SPUC_FARROW_UPSAMPLER
#define SPUC_FARROW_UPSAMPLER

// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_classes
#include <spuc/spuc_types.h>
#include <spuc/farrow.h>
namespace SPUC {
//! \file
//! \brief Upsampler/interpolator using farrow structure
//
//! \brief Upsampler/interpolator using farrow structure
//
//! Essentially a wrapper around farrow to allow one to
//! upsample by specifing a fractional time increment
//! input should always be available, need_sample returns
//! 1 when the input needs to be update for next call
//! \author Tony Kirke
//! \ingroup classes examples interpolators
class farrow_upsampler {
 public:
  float_type time_offset;
  farrow<float_type> INTERP;

  int need_sample(float_type t_inc, float_type x);
  float_type output(float_type t_inc);
  farrow_upsampler(int order = 4);
};
}  // namespace SPUC
#endif
