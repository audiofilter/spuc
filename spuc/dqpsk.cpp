// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_src
#include <spuc/dqpsk.h>
namespace SPUC {
//! \file
//! \brief Differential QPSK encoder/decoder
//! \author Tony Kirke,  Copyright(c) 2001
//
//! Differential encoding/decoding of QPSK
//! Encode/Decode the input bits into quaternary qpsk format
dqpsk::dqpsk() {
  //  Initialize previous symbol to zero
  //  Set up encoding data base as a two element array with arguments of
  //   i) current input symbol, and ii) previous encoded symbol
  //	static int datbase[4][4] = {0,1,2,3,1,3,0,2,2,0,3,1,3,2,1,0};
  int(*datbase)[4] = new int[4][4];
  datbase[0][0] = 0;
  datbase[0][1] = 1;
  datbase[0][2] = 2;
  datbase[0][3] = 3;

  datbase[1][0] = 1;
  datbase[1][1] = 3;
  datbase[1][2] = 0;
  datbase[1][3] = 2;

  datbase[2][0] = 2;
  datbase[2][1] = 0;
  datbase[2][2] = 3;
  datbase[2][3] = 1;

  datbase[3][0] = 3;
  datbase[3][1] = 2;
  datbase[3][2] = 1;
  datbase[3][3] = 0;
  previous_encoded_symbol = 0;
  previous_decoded_symbol = 0;
}
//!  Call qpsk_sym to get equivalent symbol value (0-3) of current
//!   input bit pair
//!   Get current output symbol (0-3) from encoding
//!    data base[curr symbol][prev encoded symbol]
//!   Call convbits to convert current encoded symbol to bit pair
//!   Previous encoded symbol = current encoded symbol
complex<long> dqpsk::encode(complex<long> c) {
  int insym, outsym;
  insym = qpsk_sym(c);
  outsym = datbase[insym][previous_encoded_symbol];
  previous_encoded_symbol = outsym;
  return (convbits(outsym));
}
//!
//! Differential decoder
complex<long> dqpsk::decode(complex<long> c) {
  int insym, outsym;
  insym = qpsk_sym(c);
  outsym = datbase[insym][previous_decoded_symbol];
  previous_decoded_symbol = insym;
  return (convbits(outsym));
}
//!
//! Convert integer symbol (0-3) back to binary pair
complex<long> dqpsk::convbits(int sym) {
  if (sym == 0)
    return (complex<long>(-1, -1));
  else if (sym == 1)
    return (complex<long>(-1, 1));
  else if (sym == 2)
    return (complex<long>(1, -1));
  else
    return (complex<long>(1, 1));
}
//!
//! Encode bit pair into integer value from 0 to 3 and return symbol
int dqpsk::qpsk_sym(complex<long> c) {
  int insym;
  if (real(c) == -1.) {
    if (imag(c) == -1)
      insym = 0;
    else
      insym = 1;
  } else {
    if (imag(c) == -1)
      insym = 2;
    else
      insym = 3;
  }
  return (insym);
}
}  // namespace SPUC
