// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_src
#include <spuc/spuc_defines.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "ofdm_data_encoder.h"
namespace SPUC {

//--------------------------------------------------------------------------
// Interleave the coded bits
//--------------------------------------------------------------------------
void ofdm_data_encoder::interleave(const std::vector<bool>& data_in) {
  int k;
  for (int i = 0; i < coded_bits_per_frame; i++) {
    k = 16 * i - (coded_bits_per_frame - 1) * (long)floor(16.0 * i / coded_bits_per_frame);
#ifdef NO_INT
    interleaver_out[i] = data_in[i];
#else
    interleaver_out[i] = data_in[k];
#endif
  }
}
//--------------------------------------------------------------------------
complex<long> ofdm_data_encoder::data_map(long rate) {
  if (data_index == Carriers) data_index = 0;  // re-wrap
  if (data_index == 0) get_data_frame();
  return (QAM.data_map(rate, data_index++));
}
//--------------------------------------------------------------------------
void ofdm_data_encoder::get_data_frame() {
  bool data_enc;
  int i, j;
  coded_bits_per_frame = Carriers * tx_bits_per_symbol;

  raw_bits_this_frame = 0;
  for (j = 0; j < coded_bits_per_frame; j++) {
    if (no_conv) {
      data_enc = CONV.get_data();
    } else {
      data_enc = CONV.conv_encoder(enc_rate);
    }
    interleaver_in[j] = data_enc;
  }

  // interleave the block!
  interleave(interleaver_in);

  int bitc = 0;
  for (j = 0; j < Carriers; j++) {
    for (i = 0; i < tx_bits_per_symbol; i++) { serial_to_word_input(interleaver_out[bitc++]); }
    pre_mod[j] = serial_to_word_output();
  }
}
void ofdm_data_encoder::serial_to_word_input(bool in) { serial = (serial << 1) | (long)in; }
long ofdm_data_encoder::serial_to_word_output(void) { return (serial); }
}  // namespace SPUC
