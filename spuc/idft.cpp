
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
#include <spuc/complex.h>
#include <spuc/spuc_math.h>
#include <iostream>
#include <fstream>
#include <spuc/idft.h>
#include <spuc/smart_array.h>
namespace SPUC {
void idft(smart_array<complex<float_type> > y, int n)
{
  int j,l;

  /*  n inverse dft length */
  smart_array<complex<float_type> > x(n+1);
  complex<float_type> mult;

  /*  calculate the w values recursively */
  //  complex<float_type> w_inc = expj(TWOPI/n);
  //  complex<float_type> w_x = complex<float_type>(1,0);
  for (j=0; j<n; j++) {
	x[j] = y[j];
  }

  /*  start inverse fft */
  for (l=0; l<n; l++) {
	y[l] = 0;
    for (j=0; j<n ; j++) {
	  mult  = x[j]*expj(TWOPI*l*j/(n));
	  y[l] += mult;
	} 
  }

#define SCALEFFT
#ifdef SCALEFFT
  int i;
  /*  scale all results by 1/n */
  float_type scale = (float_type)(1.0/n);
  for (i=0; i<n; i++) y[i] = scale*y[i];
#endif
}
void dft(smart_array<complex<float_type> > y, int n)
{
  int j,l;

  /*  n inverse dft length */
  smart_array<complex<float_type> > x(n+1);

  for (j=0; j<n; j++) x[j] = y[j];

  /*  start inverse fft */
  for (l=0; l<n; l++) {
	y[l] = 0;
    for (j=0; j<n ; j++) {
	  y[l] += x[j]*expj(-TWOPI*j*l/n);
	} 
  }
}
} // namespace SPUC
