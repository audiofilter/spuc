#ifndef SPUC_CONVOLVE
#define SPUC_CONVOLVE

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
// \brief Convolve
//
// \brief Template convolve function
//! \author Tony Kirke,  Copyright(c) 2001 
//! \author Tony Kirke
//! \ingroup template_array_functions misc
template <class T> smart_array<T> convolve(smart_array<T> x, smart_array<T> y) {
  int i,j;
  int M = x.len();
  int N = y.len();
  int L=M+N-1;
  smart_array<T> c(L);
  for (i=0;i<L;i++) {
	c[i] = (T)0;
	for (j=0;j<N;j++) {
	  if ((i-j >= 0) & (i-j < M))
		c[i] += x[j] * y[i-j];
	}
  }
  return(c);
}
} // namespace SPUC
#endif
