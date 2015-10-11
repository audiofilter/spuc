// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_src
#include <spuc/bit_scrambler.h>
namespace SPUC {
bool bit_scrambler::scramble(bool data_in) {
  bool res = xor_bits(u & g);
  u <<= 1;
  u += res;
  return (data_in ^ res);
}
//! Exclusive or reduction
bool bit_scrambler::xor_bits(long x) {
  bool c = 0;
  for (int i = 0; i < span; i++) {
    c ^= (x & 0x01);
    x >>= 1;
  }
  return (c);
}
}  // namespace SPUC
