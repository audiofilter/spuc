#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_classes
#include <spuc/spuc_types.h>
#include <spuc/spuc_defines.h>
namespace SPUC {
//
#define MAX_STEP 4
#define STEP_BITS 3
#define MASK_HI 65535
#define MASK_HIx 63535
#define MASK_LO 65536
#define MASK_LOd2 32768
#define BITS_USED 16
//! \file
//! \brief A NCO for symbol recovery in a variable rate QPSK receiver
//
//! \brief A NCO for symbol recovery in a variable rate QPSK receiver
//!
//! Since interpolation is being done, either one or two
//! samples must be calculated on each update.
//! When sample2 is true, there are 2 samples available.
//! \author Tony Kirke,  Copyright(c) 2001
//! \author Tony Kirke
//! \ingroup classes sim examples
class timing_nco {
 protected:
  signed long resid1;
  signed long acc;
  unsigned long fcw;
  unsigned long new_fcw;
  signed long phase1;
  signed long phase2;
  signed long new_phase;
  long sample2;

 public:
  inline timing_nco(void) {
    resid1 = 0;
    acc = MASK_LOd2;
    fcw = new_fcw = phase1 = phase2 = 0;
    sample2 = 1;
  }
  inline void set_frequency(unsigned long freq) { fcw = freq; }
  inline void reset_frequency(unsigned long freq) { new_fcw = fcw = freq; }
  inline float_type get_off1(void) { return ((float_type)phase1 / MASK_LO); }
  inline float_type get_off2(void) { return ((float_type)phase2 / MASK_LO); }
  inline long get_phase1(void) { return (-MAX_STEP + phase1); }
  inline long get_phase2(void) { return (-MAX_STEP + phase2); }
  long run(long loop_filter_out = 0, int load = 1);
  signed long residual_phase(signed long acc_value);
};
}  // namespace SPUC
