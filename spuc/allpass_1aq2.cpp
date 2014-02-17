
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
#include <spuc/allpass_1aq2.h>
namespace SPUC {
long allpass_1aq2::clock(long input) {
  // Shift inputs by one time sample and place new sample into array
  long adder1,next_adder2,mult,out;
  
  // Adder1 needs 1 more bit than input	
  adder1 = adder2 - input;
  
  //	mult = -(3*adder1)/4; // Multiplier = 3/4
  mult = -adder1 + ((adder1+2)>>2); // Multiplier = 3/4
  
  // Next adder2 needs 1 more bit than input
  next_adder2 = mult + input;
  
  // output adder needs 1 more bit than input
  out = adder2 + mult;
  adder2 = next_adder2;
  return(out);
}
} // namespace SPUC
