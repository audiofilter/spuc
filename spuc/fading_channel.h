#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_classes
#include <spuc/spuc_types.h>
#include <spuc/complex.h>
#include <spuce/filters/fir.h>
#include <spuc/noise.h>
namespace SPUC {
//! \file
//! \brief  A Class for simulating a FIR channel model
//!
//!  \brief  A Class for simulating a FIR channel model
//
//!  FIR Channel Model.
//!  Exponential decay delay line channel model
//!  Mean channel power is normalized
//!  Profiles are generated using gaussian pdf
//! \author Tony Kirke,  Copyright(c) 2001
//! \author Tony Kirke
//!  \ingroup classes sim comm
class fading_channel {
 public:
  spuce::fir<complex<float_type>, complex<float_type> > exp_decay;
  long taps;
  float_type delay_spread;
  noise tap_gain;

  // constructor
  fading_channel(long paths = 1, float_type norm_delay_spread = 1) {
    taps = paths;
    delay_spread = norm_delay_spread;
    exp_decay.set_size(taps);
    generate_channel();
  }
  void setup(float_type norm_delay_spread);
  void generate_channel();
  complex<float_type> update(const complex<float_type> s);
};
}  // namespace SPUC
