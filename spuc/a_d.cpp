
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
#include <cmath>
#include <spuc/complex.h>
#include <spuc/a_d.h>
namespace SPUC {
//! Constructor
a_d::a_d(char h) : size(h) {
  max = ((1 << (size - 1)) - 1);
  min = ~max;
}
complex<long> a_d::clock(complex<float_type> x) {
  return (complex<long>(clock(real(x)), clock(imag(x))));
}
//! Quantize and limit signal to size bits
long a_d::clock(float_type x) {
  long quant;
  quant = (long)floor(x + 0.5);
  if (quant > max) quant = max;
  if (quant < min) quant = min;
  return (quant);
}

}  // namespace SPUC
