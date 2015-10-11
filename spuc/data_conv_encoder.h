#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_classes
#include <spuc/spuc_types.h>
#include <cmath>
#include <spuc/complex.h>
#include <spuc/max_pn.h>
#include <vector>
namespace SPUC {
//! \file
//! \brief Convolutional encoder for punctured encoding
//
//! \brief Convolutional encoder for punctured encoding
//
//!   Convolutional Encoder for punctured encoding of various rates
//!   Uses common G1/G2 0x6d/0x4f generator polynomials
//!  Primarily designed for Encoder in an 802.11a system
//! \author Tony Kirke
//! \ingroup classes comm
class data_conv_encoder {
 public:
  max_pn test_pn;
  long g1;  // removed const for pyste
  long g2;  // removed const for pyste
  bool conv_enc_phase;
  int conv_enc_get_bit;
  long conv_enc_u;
  long conv_bit_number;
  long rate_index;
  long enc_rate;
  long total_bits;
  long number_symbols;
  long frame;
  long serial;
  long sample;
  long data_index;
  bool raw_bit;  // current input data bit
  std::vector<bool> raw_data;
  std::vector<long> pre_mod;

 public:
  int raw_bits_this_frame;
  bool no_conv;

  // Constructor (with default data rate)
  data_conv_encoder(int index, int T_fft) : test_pn(0x0013, 32767, -1), raw_data(16 * T_fft), pre_mod(T_fft) {
    g1 = 0x6d;
    g2 = 0x4f;
    rate_index = index;
    reset();
  }
  void reset() {  // clear variables for next burst
    conv_enc_u = 0;
    conv_enc_phase = 1;
    conv_enc_get_bit = 1;
    conv_bit_number = 0;
    serial = 0;
    sample = 0;
    frame = 0;
    raw_bit = 0;
    raw_bits_this_frame = 0;
    test_pn.reset();
    data_index = 0;
  }
  ~data_conv_encoder() {}
  void set_rate(int mod, int conv_rate) {
    if (conv_rate == 0)
      no_conv = 1;
    else
      no_conv = 0;
    enc_rate = conv_rate;
  }
  bool conv_encoder(const long enc_rate);
  //	bool get_data(void);
  void serial_to_word_input(bool in);
  long serial_to_word_output(void);
  bool get_data(void);
};

}  // namespace SPUC
