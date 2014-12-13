#ifndef SPUC_DVB_CONV_ENCODER
#define SPUC_DVB_CONV_ENCODER

/*
    Copyright (C) 2014 Tony Kirke

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
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
#endif
