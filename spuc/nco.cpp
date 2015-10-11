// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_src
#include <spuc/spuc_defines.h>
#include <spuc/nco.h>
namespace SPUC {

nco::nco(long bits) {
  acc = fcw = new_fcw = phase = 0;
  mask_bits = MASK_NEG_HI(bits);
}
long nco::clock() {
  acc += new_fcw;
  phase = acc & mask_bits;  // truncate
  return (phase);
}
long nco::clock(long loop_filter_out) {
  new_fcw = fcw + loop_filter_out;
  return (clock());
}
}  // namespace SPUC
