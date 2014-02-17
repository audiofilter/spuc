
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
#include <spuc/spuc_defines.h>
#include <cstdlib>
#include "dvb_conv_encoder.h"
namespace SPUC {

//--------------------------------------------------------------------------
// Convolutional encoding
//--------------------------------------------------------------------------
// only handles rate 1/2 encoding
bool dvb_conv_encoder::clock()
{
  bool a;
  if (conv_enc_phase) {
	conv_enc_u <<= 1;
	//OR u with the next new bit to get the contents of the encoder
	conv_enc_u |= (long)get_data();
	conv_bit_number++;
	//XOR the masked register contents to get output data A
	a = reduce(conv_enc_u&g1,7);
  } else {
	a = reduce(conv_enc_u&g2,7);
  }
  conv_enc_phase = !conv_enc_phase;
  return(a);
}
bool dvb_conv_encoder::reduce(long x, long n)
{
	bool c=0;
	for (int i =0;i<n;i++) {
		c ^= (x & 0x01);
		x >>= 1;
	}
	return(c);
}

} // namespace SPUC
