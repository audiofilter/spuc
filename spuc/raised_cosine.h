#ifndef SPUC_RAISED_COSINE
#define SPUC_RAISED_COSINE

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
#include <spuc/fir_coeff.h>
#include <cmath>
#include <spuc/complex.h>
#include <spuc/fir_coeff.h>
#include <spuc/raised_cosine_imp.h>
namespace SPUC {
//! \file
//! \brief  Raised Cosine functions
//
//! \brief  Raised Cosine functions
//! \author Tony Kirke
//! \ingroup template_functions comm
template <class T> void raised_cosine(fir_coeff<T>& rcfir, float_type alpha, float_type rate) {
  int i;
  int num_taps = rcfir.num_taps;
  double gain = 1.0/rate;
  for (i=0;i<num_taps;i++) {
	rcfir.coeff[i] = (T)raised_cosine_imp(alpha,float_type(i), rate, num_taps);
	rcfir.coeff[i] = gain*rcfir.coeff[i];
  } 
}

} // namespace SPUC
#endif
