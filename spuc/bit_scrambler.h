#ifndef SPUC_BIT_SCRAMBLER
#define SPUC_BIT_SCRAMBLER

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
namespace SPUC {
//! \file
//! \brief Data scrambler
//
//! \brief Data scrambler
//
//! Does scrambling function on input bits
//! \author Tony Kirke
//! \ingroup classes comm
class bit_scrambler {
 public:
  unsigned long g;
  long span;

 public:
  unsigned long u;
  bit_scrambler(long gen = 0x48, long bits = 7, long uinit = -1)
      : g(gen), span(bits), u(uinit) {
    ;
  }
  void reset() { u = ~0; }
  bool scramble(bool data_in);
  //! Exclusive or reduction
  bool xor_bits(long x);
};
}  // namespace SPUC
#endif
