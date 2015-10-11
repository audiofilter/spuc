// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_src
#include <spuc/rv_stat.h>
#include <spuc/spuc_defines.h>
#include <cfloat>
namespace SPUC {
rv_stat::rv_stat() {
  count = 0;
  av = 0;
  sq = 0;
  min_abs = (float_type)(FLT_MAX);
  max_abs = 0;
}
void rv_stat::update(float_type x) {
  count += 1.0;
  av += x;
  sq += SQR(x);
  min_abs = MIN(ABS(min_abs), x);
  max_abs = MAX(ABS(max_abs), x);
}
}  // namespace SPUC
