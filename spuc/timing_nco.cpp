// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_src
#include "timing_nco.h"
namespace SPUC {

// Update and return Phase word
long timing_nco::run(long loop_filter_out, int load) {
  signed long new_phase2, new_phase1;
  signed long prev_phase1 = phase1;

  if (load) new_fcw = fcw + loop_filter_out;
  new_phase1 = acc + new_fcw;
  resid1 = residual_phase(new_phase1 % MASK_LO);
  new_phase2 = new_phase1;
  if (new_phase1 > MASK_HI) new_phase1 -= MASK_LO;

  if (sample2 == 0) {
    phase1 = phase2;
  } else {
    // begin (Previous Sample2 == 1)
    new_phase2 = new_phase1 + fcw;  // use new_phase1 instead of acc!
    if ((new_phase1 > MASK_HIx) && (prev_phase1 == 0) && (fcw < 40000)) {
      phase1 = 0;
      if (new_phase2 > MASK_HI) new_phase2 -= MASK_LO;
    } else {
      phase1 = resid1;
    }
    // end (Previous Sample2 == 1)
  }
  if (((phase1 == 0) || (new_phase2 > MASK_LOd2)) && (new_phase2 < (MASK_LO))) {
    sample2 = 1;
  } else {
    if (new_phase2 > MASK_HI) new_phase2 -= MASK_LO;
    sample2 = 0;
  }

  acc = new_phase2;
  phase2 = residual_phase(acc);

  return (sample2);
}
signed long timing_nco::residual_phase(signed long acc_value) {
  long resid;
  resid = (acc_value + (1 << (BITS_USED - STEP_BITS - 1)));
  resid = resid >> (BITS_USED - STEP_BITS);
  return (resid);
}
}  // namespace SPUC
