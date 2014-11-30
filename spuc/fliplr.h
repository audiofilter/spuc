#ifndef SPUC_FLIPLR
#define SPUC_FLIPLR

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
// from directory: spuc_template_array_functions
#include <spuc/spuc_types.h>
#include <spuc/smart_array.h>
namespace SPUC {
//! \file
//! \brief fliplr - same as matlab function
//
//! \brief fliplr - same as matlab function
//! \author Tony Kirke
//! \ingroup template_array_functions misc
template <class T> smart_array<T> fliplr(const smart_array<T>& x) {
  int N=x.len();
  smart_array<T> c(N);
  for (int j=0;j<N;j++) c[N-j] = x[j];
  return(c);
}
} // namespace SPUC
#endif
