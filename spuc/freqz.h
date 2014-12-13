#ifndef SPUC_FREQZ
#define SPUC_FREQZ

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
// from directory: spuc_real_template_array_functions
#include <spuc/spuc_types.h>
#include <cmath>
#include <spuc/spuc_defines.h>
#include <spuc/complex.h>
#include <spuc/spuc_math.h>
#include <vector>
namespace SPUC {
//! \file
//! \brief Various functions for getting frequency responses of filters
//
//
//! \brief frequency transfer function at freq with iir A and B equations
//! \author Tony Kirke
//! \ingroup real_template_array_functions misc
template <class T>
complex<float_type> freqz_point(std::vector<T> b, std::vector<T> a,
                                float_type freq, int N) {
  int i;
  complex<float_type> z(1, 0);
  complex<float_type> z_inc = complex<float_type>(cos(freq), sin(freq));
  complex<float_type> nom(0);
  complex<float_type> den(0);
  for (i = 0; i < N; i++) {
    nom += z * float_type(b[i]);
    den += z * float_type(a[i]);
    z *= z_inc;
  }
  nom = nom / den;
  return (nom);
}
//! \brief frequency magnitude function at freq with fir x
//! \author Tony Kirke
//! \ingroup real_template_array_functions misc
template <class T>
float_type freqz_mag_point(std::vector<T> x, float_type freq, int N) {
  int i;
  complex<float_type> z(1, 0);
  complex<float_type> z_inc = expj(freq);
  complex<float_type> sum(0);
  for (i = 0; i < N; i++) {
    sum += z * float_type(x[i]);
    z *= z_inc;
  }
  return (hypot(sum));
}
//! \brief frequency transfer function at freq for 1st order allpass
//! \author Tony Kirke
//! \ingroup real_template_array_functions misc
template <class T>
complex<float_type> freqz_point(T a, float_type freq) {
  complex<float_type> z(1, 0);
  complex<float_type> z_inc = complex<float_type>(cos(freq), sin(freq));
  complex<float_type> nom;
  nom = z + z_inc * float_type(a);
  nom = nom / normalized(nom);
  return (nom);
}
////
//! \brief frequency transfer function over "pts" points for IIR
//! \author Tony Kirke
//! \ingroup real_template_array_functions misc
template <class T>
std::vector<complex<float_type> > freqz(std::vector<T> b, std::vector<T> a,
                                        int pts) {
  int i, j;
  int N = b.len();
  complex<float_type> z;
  complex<float_type> z_inc;
  complex<float_type> nom;
  complex<float_type> den;
  std::vector<complex<float_type> > f(pts);

  float_type delta = PI / (float_type)pts;
  float_type freq = 0;
  for (j = 0; j < pts; j++) {
    freq += delta;
    z_inc = complex<float_type>(cos(freq), sin(freq));
    z = complex<float_type>(1.0, 0.0);
    nom = 0;
    den = 0;
    for (i = 0; i < N; i++) {
      nom += z * float_type(b[i]);
      den += z * float_type(a[i]);
      z *= z_inc;
    }
    f[j] = nom / den;
  }
  return (f);
}
//! \brief frequency magnitude function over "pts" points for IIR
//! \author Tony Kirke
//! \ingroup real_template_array_functions misc
template <class T>
std::vector<complex<float_type> > freqz_mag(std::vector<T> b, std::vector<T> a,
                                            int pts) {
  int i, j;
  int N = b.len();
  complex<float_type> z;
  complex<float_type> z_inc;
  complex<float_type> nom;
  complex<float_type> den;

  std::vector<complex<float_type> > f(pts);

  float_type delta = PI / (float_type)pts;
  float_type freq = 0;
  for (j = 0; j < pts; j++) {
    freq += delta;
    z_inc = complex<float_type>(cos(freq), sin(freq));
    z = complex<float_type>(1.0, 0.0);
    nom = 0;
    den = 0;
    for (i = 0; i < N; i++) {
      nom += z * float_type(b[i]);
      den += z * float_type(a[i]);
      z *= z_inc;
    }
    f[j] = magsq(nom / den);
  }
  return (f);
}
//! \brief frequency magnitude function over "pts" points for FIR
//! \author Tony Kirke
//! \ingroup real_template_array_functions misc
template <class T>
std::vector<complex<float_type> > freqz_fir(std::vector<T> x, int pts) {
  int i, j;
  int N = x.len();
  complex<float_type> z;
  complex<float_type> z_inc;
  complex<float_type> nom;
  float_type delta = PI / (float_type)pts;
  float_type freq = 0;

  std::vector<complex<float_type> > f(pts);
  for (j = 0; j < pts; j++) {
    freq += delta;
    z_inc = complex<float_type>(cos(freq), sin(freq));
    z = complex<float_type>(1.0, 0.0);
    nom = 0;
    for (i = 0; i < N; i++) {
      nom += z * float_type(x[i]);
      z *= z_inc;
    }
    f[j] = nom;
  }
  return (f);
}
}  // namespace SPUC
#endif
