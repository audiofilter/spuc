#ifndef SPUC_SIGNBITR
#define SPUC_SIGNBITR

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
#include <spuc/complex.h>
namespace SPUC {
template <typename T> class signbitr
{
public:
  static T signbitd(T x) { return(((float_type)x < (float_type)0) ? (T)-1: (T)1); }
};
// partial specialization
template <typename T> class signbitr<complex<T> > {
public:
  static complex<T> signbitd(complex<T> x) {
	return(complex<T>(signbitr<T>::signbitd(real(x)),
					  signbitr<T>::signbitd(imag(x)))
		   );
  }
};
} // namespace SPUC
#endif
