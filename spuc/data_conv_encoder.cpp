// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_src
#include <spuc/spuc_defines.h>
#include <spuc/misc.h>
#include <spuc/data_conv_encoder.h>
namespace SPUC {

//--------------------------------------------------------------------------
// Convolutional encoding
//--------------------------------------------------------------------------
bool data_conv_encoder::conv_encoder(const long steal) {
  bool a;

  if (steal > 1) {  // ! rate 1/2
    if (conv_enc_get_bit) {
      conv_enc_u <<= 1;
      conv_enc_u |= (long)get_data();
      if (conv_bit_number++ % steal == 0)
        conv_enc_get_bit = 0;
      else
        conv_enc_get_bit = 1;
    } else {
      conv_enc_get_bit = 1;
    }
    if (conv_enc_phase)
      a = reduce(conv_enc_u & g1, 7);
    else
      a = reduce(conv_enc_u & g2, 7);
  } else {
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
  }
  conv_enc_phase = !conv_enc_phase;
  if (conv_enc_get_bit && steal == 2) conv_enc_phase = 1;
  return (a);
}
//--------------------------------------------------------------------------
void data_conv_encoder::serial_to_word_input(bool in) {
  serial <<= 1;
  serial += in;
}
//--------------------------------------------------------------------------
long data_conv_encoder::serial_to_word_output(void) {
  long x = serial;
  serial = 0;
  return (x);
}
//--------------------------------------------------------------------------
// Get data for transmission
//--------------------------------------------------------------------------
bool data_conv_encoder::get_data(void) {
  raw_bit = test_pn.get_bit();
  raw_data[raw_bits_this_frame++] = raw_bit;
  return (raw_bit);
}
}  // namespace SPUC
