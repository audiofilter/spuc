// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_src
#include <cmath>
#include <spuc/max_pn.h>
namespace SPUC {

signed char max_pn::out() {
  u <<= 1;
  if ((u & lenp1) == 0)
    return (-1);
  else {
    u ^= gen;
    return (1);
  }
}
bool max_pn::get_bit() {
  u <<= 1;
  if ((u & lenp1) == 0)
    return (0);
  else {
    u ^= gen;
    return (1);
  }
}

signed char max_pn::out1() {
  int i, ii, is;
  char data;
  char n = (char)(log((double)lenp1) / log(2.0));

  u <<= 1;
  if ((u & lenp1) != 0)
    data = 1;
  else
    data = -1;
  i = u & gen;
  for (ii = is = 0; ii < n; ii++) { is = (is + ((i >> ii) & 1)) % 2; }
  u += is;
  return (data);
}
}  // namespace SPUC
