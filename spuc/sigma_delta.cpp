// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_src
#include <spuc/sigma_delta.h>
namespace SPUC {

sigma_delta::sigma_delta(char nin, char nout) {
  nbit_in = 31 - nin;
  nbit_out = 32 - nout;
  acc = 0;
  mask = (0xffffffff >> nout);
}
signed char sigma_delta::single(signed long in) {
  signed long tmp = (in << nbit_in);
  acc += tmp;
  tmp = acc & (~mask);
  signed char out = (char)(tmp >> nbit_out);
  acc -= tmp;
  return (out);
}
}  // namespace SPUC
