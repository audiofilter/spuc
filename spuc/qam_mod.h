#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_classes
#include <spuc/spuc_types.h>
#include <cmath>
#include <spuc/complex.h>
namespace SPUC {
//! \file
//! \brief   QAM Modulator for BPSK - 64 QAM for 802.11A Data modulation
//
//! \brief   QAM Modulator for BPSK - 64 QAM for 802.11A Data modulation
//! \author Tony Kirke
//! \image html qam_mod.png
//! \ingroup classes comm modulators
class qam_mod {
 public:
  long rate_index;  // 0 BPSK, Max for highest QAM, etc

 public:
  // Constructor (with default data rate)
  qam_mod(int index) { rate_index = index; }
  ~qam_mod() {}
  complex<long> data_map(long r_ind, long data_in);
  complex<long> bpsk_map(long data_in);
  complex<long> qpsk_map(long data_in);
  complex<long> qam16_map(long data_in);
  complex<long> qam64_map(long data_in);
};
}  // namespace SPUC
