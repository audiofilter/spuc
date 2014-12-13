#ifndef SPUC_TOEPLITZ
#define SPUC_TOEPLITZ

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
// from directory: spuc_template_functions
#include <spuc/spuc_types.h>
#include <spuc/vector.h>
#include <spuc/matrix.h>
namespace SPUC {
//! \file
//! \brief Get Symmetric Toeplitz matrix from vector
//
//! \brief Get Symmetric Toeplitz matrix from vector
//
// <font color="red"><i>Under construction!</i></font>
//!  \author Tony Kirke,  Copyright(c) 2001
//! \author Tony Kirke
//! \ingroup template_functions misc
template <class T>
void toeplitz(vector<T> x, matrix<T>& A) {
  int i, j;
  int k = 0;
  long N = x.size();
  for (j = 0; j < N; j++) {
    for (i = 0; i < N; i++) A(j, i) = x[(i + k) % N];
    k++;
  }
}
// function_instantiations: long, double, complex<long>, complex<double>
}  // namespace SPUC
#endif
