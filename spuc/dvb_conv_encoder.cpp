// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_src
#include <spuc/spuc_defines.h>
#include <cstdlib>
#include "dvb_conv_encoder.h"
namespace SPUC {

//--------------------------------------------------------------------------
// Convolutional encoding
//--------------------------------------------------------------------------
// only handles rate 1/2 encoding
bool dvb_conv_encoder::clock() {
  bool a;
  if (conv_enc_phase) {
    conv_enc_u <<= 1;
    // OR u with the next new bit to get the contents of the encoder
    conv_enc_u |= (long)get_data();
    conv_bit_number++;
    // XOR the masked register contents to get output data A
    a = reduce(conv_enc_u & g1, 7);
  } else {
    a = reduce(conv_enc_u & g2, 7);
  }
  conv_enc_phase = !conv_enc_phase;
  return (a);
}
bool dvb_conv_encoder::reduce(long x, long n) {
  bool c = 0;
  for (int i = 0; i < n; i++) {
    c ^= (x & 0x01);
    x >>= 1;
  }
  return (c);
}

}  // namespace SPUC
