// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_src
#include <spuc/spuc_defines.h>
#include <cmath>
#include <spuc/complex.h>
#include "carrier_nco.h"
namespace SPUC {

complex<long> carrier_nco::clock(long loop_filter_out, int load) {
  if (load) new_fcw = fcw + loop_filter_out;
  acc += new_fcw;
  phase = acc >> 22;
  complex<long> cm_exp((long)(127.0 * cos(TWOPI * phase / 1024.0) + 0.5),
                       (long)(127.0 * sin(TWOPI * phase / 1024.0) + 0.5));
  return (cm_exp);
}
}  // namespace SPUC
