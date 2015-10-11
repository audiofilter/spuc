#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_classes
#include <spuc/spuc_types.h>
#include <ctime>          // For time functions
#include <spuc/max_pn.h>  // Maximal length PN generator
#include <spuc/complex.h>
#include <iostream>
#include <iomanip>
namespace SPUC {
//! \file
//! \brief  A Class for doing BER test on QPSK
//
//! \brief  A Class for doing BER test on QPSK
//
//!  \author Tony Kirke,  Copyright(c) 2001
//! \author Tony Kirke
//!  \ingroup classes sim
class qpsk_ber_test {
 public:
  long modc;
  time_t start_time;
  max_pn ref;
  complex<long> corr_sum;
  long errors;
  complex<long> rotate;
  bool sync;
  long interval;
  long prev_errors;

  qpsk_ber_test(void) : ref(0x006d, 63, -1) { reset(); }
  void reset(void) {
    ref.reset();
    modc = 1;
    start_time = time(NULL);
    errors = 0;
    corr_sum = 0;
    sync = 0;
    rotate = complex<long>(0, 0);
    interval = 0;
    prev_errors = 0;
  }
  void init_delay(int c) {
    for (int i = 0; i < c; i++) ref.out();
  }
  bool found_sync(void) { return (sync); }
  void ber_results(long received);
  long synchronize(long* received, complex<long> data);
  long synchronise(long received, complex<double> data);
  void final_results(long received);
  void correlate(long* received, complex<long> data) {
    synchronize(received, data);
    ber_results(*received);
  }
  void print_running_ber(void);
  float_type running_ber(void);
  float_type ber(long received) { return (errors / (float_type)received); }
};
}  // namespace SPUC
