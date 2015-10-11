#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_classes
#include <spuc/spuc_types.h>
#include <spuc/complex.h>
namespace SPUC {
//! \file
//! \brief Differential QPSK encoder/decoder
//
//! \brief Differential QPSK encoder/decoder
//
//! Encode/Decode the input bits into quaternary qpsk format
//! \author Tony Kirke
//! \ingroup classes comm
class dqpsk {
 public:
  int** datbase;
  int previous_encoded_symbol;
  int previous_decoded_symbol;

  dqpsk();
  //!  Call qpsk_sym to get equivalent symbol value (0-3) of current
  //!   input bit pair
  //!   Get current output symbol (0-3) from encoding
  //!    data base[curr symbol][prev encoded symbol]
  //!   Call convbits to convert current encoded symbol to bit pair
  //!   Previous encoded symbol = current encoded symbol
  complex<long> encode(complex<long> c);
  //!
  //! Differential decoder
  complex<long> decode(complex<long> c);
  //!
  //! Convert integer symbol (0-3) back to binary pair
  complex<long> convbits(int sym);
  //!
  //! Encode bit pair into integer value from 0 to 3 and return symbol
  int qpsk_sym(complex<long> c);
};
}  // namespace SPUC
