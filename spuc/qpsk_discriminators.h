#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_classes
#include <spuc/spuc_types.h>
#include <spuc/complex.h>
#include <spuc/delay.h>
namespace SPUC {
//! \file
//! \brief A Class incorporating several symbol and carrier discriminators for QPSK
//
//! \brief A Class incorporating several symbol and carrier discriminators for QPSK
//
//! \author Tony Kirke
//! \ingroup classes comm
class qpsk_discriminators {
 public:
  int bpsk_mode;
  complex<long> fmf;
  complex<long> prev_sam, prev_sym, data;
  complex<long> hard_decision_prev, decision;
  delay<complex<long> > hard_decision_delay, timing_disc_delay;

  void update(complex<long> data_in, complex<long> decision_in, int sym_pls);
  void sample(complex<long> fmf_in, complex<long> data_in, complex<long> decision_in, int sym_pls);
  qpsk_discriminators(int bpsk = 0) : hard_decision_delay(2), timing_disc_delay(3) { bpsk_mode = bpsk; }
  void set_mode(int bpsk = 0) { bpsk_mode = bpsk; }
  long cross_prod_afc(void);
  long quad(void);
  long rcfd(void);
  long dd_timing_disc(void);
  long nda_timing_disc(void);
  long symbol_lock_out(void);
  long pll_disc(void);
};
}  // namespace SPUC
