#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_classes
#include <spuc/spuc_types.h>
#include <spuc/complex.h>
namespace SPUC {
//! \file
//! \brief A specialization example of a sin/cosine look-up NCO
//
//! \brief A specialization example of a sin/cosine look-up NCO
//
//! with fixed quantizations
//! \author Tony Kirke
//! \author Tony Kirke
//! \image html carrier_nco.png
//! \ingroup classes comm
class carrier_nco {
 protected:
  unsigned long acc;
  unsigned long fcw;
  unsigned long new_fcw;
  unsigned long phase;

 public:
  inline carrier_nco(void) { acc = fcw = new_fcw = phase = 0; }
  inline void set_frequency(unsigned long freq) { fcw = freq; }
  inline void reset_frequency(unsigned long freq) { new_fcw = fcw = freq; }
  inline long get_phase(void) { return (phase); }
  complex<long> clock(long loop_filter_out = 0, int load = 1);
};
}  // namespace SPUC
