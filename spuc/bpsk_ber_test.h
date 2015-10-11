#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_classes
#include <spuc/spuc_types.h>
#include <ctime>          // For time functions
#include <spuc/max_pn.h>  // Maximal length PN generator
#include <iostream>
#include <fstream>
#include <iomanip>
namespace SPUC {
//! \file
//! \brief  A Class for simulating a BPSK system
//
//! \brief  A Class for simulating a BPSK system
//
//! \author Tony Kirke
//!  \ingroup classes sim
class bpsk_ber_test {
 public:
  long modc;
  time_t start_time;
  max_pn ref;
  long corr_sum;
  long errors;
  signed char synced;
  long interval;
  long prev_errors;

  bpsk_ber_test(void) : ref(0x006d, 63, -1) {
    start_time = time(NULL);
    reset();
  }
  void reset(void) {
    ref.reset();
    modc = 1;
    start_time = time(NULL);
    errors = 0;
    corr_sum = 0;
    synced = 0;
    interval = 0;
    prev_errors = 0;
  }

  signed char found_sync(void) { return (synced); }
  void ber_results(long received);
  long synchronize(long* received, long data);
  void final_results(long received);
  void correlate(long* received, long data) {
    synchronize(received, data);
    ber_results(*received);
  }
  float_type running_ber(void);
  float_type ber(long received) { return (errors / (float_type)received); }
};
}  // namespace SPUC
