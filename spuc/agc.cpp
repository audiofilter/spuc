// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_src
#include <spuc/spuc_defines.h>
#include <spuc/agc.h>
namespace SPUC {
//! \brief This is a simple sigma-delta type AGC for the variable rate QPSK example
//! \ingroup examples
//! \author Tony Kirke, Copyright(c) 1993-1996
//!
agc::agc(long thres) : agc_thres(thres) {
  agc_acc = 0;
  agc_bit = 0;
}
long agc::run(complex<long> adc) {
  long abs_level = ABS(real(adc)) + ABS(imag(adc));
  long agc_diff = abs_level - agc_thres + 32;
  if (agc_diff > 64) agc_diff = 64;
  if (agc_diff < 0) agc_diff = 0;
  agc_acc += agc_diff;
  agc_bit = (agc_acc & 0x40) ? 0 : 1;
  agc_acc &= 0x3f;  // Clear overflow bit
  return (agc_bit);
}
}  // namespace SPUC
