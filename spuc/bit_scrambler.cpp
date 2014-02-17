
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
//! \author Tony Kirke
// from directory: spuc_src
#include <spuc/bit_scrambler.h>
namespace SPUC {
bool bit_scrambler::scramble(bool data_in) {
  bool res = xor_bits(u&g);
  u <<= 1;
  u += res;
  return(data_in ^ res);
}
//! Exclusive or reduction
bool bit_scrambler::xor_bits(long x) {
  bool c=0;
  for (int i =0;i<span;i++) {
	c ^= (x & 0x01);
	x >>= 1;
  }
  return(c);
}
} // namespace SPUC
