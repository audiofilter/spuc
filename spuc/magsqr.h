#ifndef SPUC_MAGSQR
#define SPUC_MAGSQR

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
template <typename T> class magsqr
{
public:
  static T magsqd(T x) { return(x*x); }
};
// partial specialization
template <typename T> class magsqr<complex<T> > {
public:
  static T magsqd(complex<T> x) {
	return(real(x)*real(x) + imag(x)*imag(x));
  }
};
} // namespace SPUC
#endif
