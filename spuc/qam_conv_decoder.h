#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_classes
#include <spuc/spuc_types.h>
#include <cmath>
#include <spuc/complex.h>
#include <spuc/viterbi.h>
#include <spuc/delay.h>
#include <vector>
namespace SPUC {
//! \file
//! \brief QAM convolutional decoder
//
//! \brief QAM convolutional decoder
//
// uses qam_data_deamp for soft decisions then inputs these into
// viterbi decoding using puncturing if necessary
// if output of data_decode is true, use get_bit for data bit output
//! \author Tony Kirke, Copyright(c) 2004
//! \author Tony Kirke
//! \ingroup classes comm
class qam_conv_decoder {
 public:
  const long Max_bits_per_symbol;
  const long soft_decision_level;
  viterbi viterbi_decoder;
  std::vector<long> viterbi_input;

  long enc_rate;
  long rate_index;
  long soft_bit_counter;
  long rx_bits_per_symbol;
  long raw_bits_this_frame;
  long coded_bits_per_frame;
  long raw_bits_out;
  long sample;
  long serial;

  bool frame_ready;
  bool viterbi_ready;
  bool viterbi_data;
  bool output_buffer_empty;
  bool no_conv;  // Bypass Viterbi when true

 public:
  qam_conv_decoder(int index) : Max_bits_per_symbol(8), soft_decision_level(64), viterbi_input(Max_bits_per_symbol) {
    no_conv = 0;
    rate_index = index;
    reset();
    set_rate(0, 1);
  }
  ~qam_conv_decoder() {}
  void reset() {
    sample = 0;  // 16;
    raw_bits_this_frame = 0;
    coded_bits_per_frame = 0;
    soft_bit_counter = 0;
    raw_bits_out = 0;
    output_buffer_empty = 1;
    viterbi_ready = 0;
    viterbi_data = 0;
    viterbi_decoder.reset();
    frame_ready = 0;
  }
  //! set modulation and punctured coding rate
  void set_rate(int mod, int conv_rate) {
    if (conv_rate == 0)
      no_conv = 1;
    else
      no_conv = 0;
    enc_rate = conv_rate;
    if (mod > 0)
      rx_bits_per_symbol = 2 * mod;
    else
      rx_bits_per_symbol = 1;
    rate_index = mod;
  }
  //! return true when output is available
  bool data_decode(complex<long> data_in);
  //! call when viterbi_ready is true
  bool get_bit(void) { return (viterbi_data); }
  //! clear soft decision array
  void clear_soft_decision(long rate);
};
}  // namespace SPUC
