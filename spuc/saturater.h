#ifndef SPUC_SATURATER
#define SPUC_SATURATER

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
// from directory: spuc_template_functors
#include <spuc/spuc_types.h>
#include <cmath>
#include <spuc/complex.h>
#include <spuc/real_saturate.h>
namespace SPUC {
template <class Numeric> class saturater
{
public:
  static Numeric saturated(Numeric x, long bits) {
	return(real_saturate(x,bits));
  }
};
// partial specialization
template <typename T> class saturater<complex<T> > {
public:
  static complex<T> saturated(complex<T> x, long bits) {
	return(complex<T>(real_saturate(real(x),bits),real_saturate(imag(x),bits)));
  }
};
} // namespace SPUC
#endif
