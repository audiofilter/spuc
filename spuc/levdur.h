#ifndef SPUC_LEVDUR
#define SPUC_LEVDUR

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
//! \brief Template class for Levinson-Durbin algorithm
//
//! \brief Template class for Levinson-Durbin algorithm
//
//! <font color="red"><i>Under construction!</i></font>
//! \author Tony Kirke
//! \ingroup template_array_functions misc
template <class T> smart_array<T> levdur(smart_array<T> R)
{
  long N = R.len();
  smart_array<T> a(N);
  T Pe;
  T q, at;
  int j,k,l;
 
  // copy array
  for (j=0;j<N;j++) a[j] = R[j];

  a[0]=(T)1.0;
  a[1]=-R[1]/R[0];
  Pe=R[0]-a[1]*a[1]*R[0];
  for (j=2;j<=N;j++){
    for (q=R[j],l=1;l<=j-1;l++) q += a[l]*R[j-1];
    q=-q/Pe;
    for (k=1;k<=j/2;k++){
      at=a[k]+q*a[j-k];
      a[j-k]+=q*a[k];
      a[k]=at;
    }
    a[j]=q;
    Pe= Pe-q*q*Pe;
  }
  return(a);
}
} // namespace SPUC
#endif
