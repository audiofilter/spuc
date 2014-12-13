#ifndef SPUC_DQPSK
#define SPUC_DQPSK

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
#endif
