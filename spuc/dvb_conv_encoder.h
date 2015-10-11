#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_classes
#include <spuc/spuc_types.h>
#include <cmath>
#include <spuc/max_pn.h>
namespace SPUC {
//! \file
//! \brief DVB Convolution encode for rate 1/2
//
//! \brief DVB Convolution encode for rate 1/2
//
//! Convolutional Encoder for rate 1/2 encoding with DVB
//! Generators. Uses PN sequence for data generation
//! \author Tony Kirke
//!  \ingroup classes comm fec
class dvb_conv_encoder {
 public:
  max_pn test_pn;
  const long g1;
  const long g2;
  bool conv_enc_phase;
  int conv_enc_get_bit;
  long conv_enc_u;
  long conv_bit_number;
  bool raw_bit;

 public:
  //! Constructor
  dvb_conv_encoder() : g1(0x6d), g2(0x4f) { reset(); }
  void reset() {  // clear variables for next burst
    conv_enc_u = 0;
    conv_enc_phase = 1;
    conv_enc_get_bit = 1;
    conv_bit_number = 0;
    test_pn.reset();
  }
  ~dvb_conv_encoder() {}
  bool clock();
  bool get_data(void) {
    raw_bit = test_pn.get_bit();
    return (raw_bit);
  }
  bool reduce(long x, long y);
};
}  // namespace SPUC
