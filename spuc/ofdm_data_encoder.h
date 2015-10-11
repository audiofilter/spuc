#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_classes
#include <spuc/spuc_types.h>
#include <cmath>
#include <spuc/complex.h>
#include <spuc/bit_scrambler.h>
#include <spuc/data_conv_encoder.h>
#include <spuc/qam_mod.h>
#include <vector>
namespace SPUC {
//! \file
//! \brief  OFDM/802.11A/G Data Encoder
//
//! \brief  OFDM/802.11A/G Data Encoder
//
//!   Uses data_conv_encoder and qam_mod classes
//! \author Tony Kirke
//! \ingroup classes comm
class ofdm_data_encoder {
 public:
  data_conv_encoder CONV;
  qam_mod QAM;
  long rate_index;  // 0 BPSK, Max for highest QAM, etc
  long enc_rate;
  long tx_bits_per_symbol;
  long total_bits;
  long number_symbols;
  long frame;
  long serial;
  long sample;
  long data_index;
  bool raw_bit;  // current input data bit
  const long Carriers;
  std::vector<bool> raw_data;
  std::vector<bool> interleaver_in;
  std::vector<bool> interleaved;
  std::vector<bool> interleaver_out;
  std::vector<long> pre_mod;

 private:
  void interleave(const std::vector<bool>& data_in);

 public:
  int coded_bits_per_frame;
  int raw_bits_this_frame;
  bool no_conv;

  // Constructor (with default data rate)
  ofdm_data_encoder(int index, int T_fft, int D_carriers, int max_range)
      : CONV(index, T_fft),
        QAM(index),
        Carriers(D_carriers),
        raw_data(16 * T_fft),
        interleaver_in(max_range * T_fft),
        interleaved(max_range * T_fft),
        pre_mod(Carriers) {
    rate_index = index;
  }
  // Determine number of OFDM symbol (must be called AFTER set_rate())
  long tx_burst_size(long bytes) {
    number_symbols = (8 * bytes + 6 + coded_bits_per_frame + 1) / coded_bits_per_frame;
    total_bits = number_symbols * coded_bits_per_frame;
    return (total_bits);
  }
  void reset() {  // clear variables for next burst
    serial = 0;
    sample = 0;
    frame = 0;
    raw_bit = 0;
    coded_bits_per_frame = 0;
    raw_bits_this_frame = 0;
    tx_bits_per_symbol = 0;
    data_index = 0;
  }
  ~ofdm_data_encoder() {}
  void set_rate(int mod, int conv_rate) {
    if (conv_rate == 0)
      no_conv = 1;
    else
      no_conv = 0;
    enc_rate = conv_rate;
    if (mod > 0)
      tx_bits_per_symbol = 2 * mod;
    else
      tx_bits_per_symbol = 1;
  }
  complex<long> data_map(long rate);

  void get_data_frame();
  void serial_to_word_input(bool in);
  long serial_to_word_output(void);
};
}  // namespace SPUC
