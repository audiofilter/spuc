#ifndef SPUC_PTR_FREQZ
#define SPUC_PTR_FREQZ
// Copyright (c) 1993-2007 Tony Kirke
// from directory: spuc_real_template_array_functions
#include <spuc/spuc_types.h>
#include <cmath>
#include <spuc/spuc_defines.h>
#include <spuc/complex.h>
#include <spuc/spuc_math.h>
namespace SPUC {
//! \file
//! \brief Various functions for getting frequency responses of filters
//
//
//! \brief frequency transfer function at freq with iir A and B equations
//! \author Tony Kirke
//! \ingroup real_template_array_functions misc
template <class T> complex<float_type> ptr_freqz_point(T* b, T* a, float_type freq, int N) {
  int i;
  complex<float_type> z(1,0);
  complex<float_type> z_inc = complex<float_type>(cos(freq),sin(freq));
  complex<float_type> nom(0);
  complex<float_type> den(0);
  for (i=0;i<N;i++) {
	nom += z*float_type(b[i]);
	den += z*float_type(a[i]);
	z *= z_inc;
  }
  nom = nom/den;
  return(nom);  
}
//! \brief frequency magnitude function at freq with fir x
//! \author Tony Kirke
//! \ingroup real_template_array_functions misc
template <class T> float_type ptr_freqz_mag_point(T* x, float_type freq, int N) {

  int i;
  complex<float_type> z(1,0);
  complex<float_type> z_inc = expj(freq);
  complex<float_type> sum(0);
  for (i=0;i<N;i++) {
	sum += z*float_type(x[i]);
	z *= z_inc;
  }
  return(hypot(sum));  
}
//! \brief frequency transfer function at freq for 1st order allpass
//! \author Tony Kirke
//! \ingroup real_template_array_functions misc
template <class T> complex<float_type> ptr_freqz_point(T a, float_type freq) {
  complex<float_type> z(1,0);
  complex<float_type> z_inc = complex<float_type>(cos(freq),sin(freq));
  complex<float_type> nom;
  nom   = z + z_inc*float_type(a);
  nom   = nom/normalized(nom);
  return(nom);  
}
////
//! \brief frequency transfer function over "pts" points for IIR
//! \author Tony Kirke
//! \ingroup real_template_array_functions misc
template <class T> void freqz(complex<float_type>* f, T* b, T* a, int N, int pts) {
  int i,j;
  complex<float_type> z;
  complex<float_type> z_inc;
  complex<float_type> nom;
  complex<float_type> den;
  
  float_type delta = PI/(float_type)pts;
  float_type freq = 0;
  for (j=0;j<pts;j++) {
	freq += delta;
	z_inc = complex<float_type>(cos(freq),sin(freq));
	z     = complex<float_type>(1.0,0.0);
	nom = 0;
	den = 0;
	for (i=0;i<N;i++) {
	  nom += z*float_type(b[i]);
	  den += z*float_type(a[i]);
	  z *= z_inc;
	}
	f[j] = nom/den;
  }
}
//! \brief frequency magnitude function over "pts" points for IIR
//! \author Tony Kirke
//! \ingroup real_template_array_functions misc
template <class T> void ptr_freqz_mag(float_type* f, T* b, T* a, int N, int pts) {
  int i,j;
  complex<float_type> z;
  complex<float_type> z_inc;
  complex<float_type> nom;
  complex<float_type> den;
  
  float_type delta = PI/(float_type)pts;
  float_type freq = 0;
  for (j=0;j<pts;j++) {
	freq += delta;
	z_inc = complex<float_type>(cos(freq),sin(freq));
	z     = complex<float_type>(1.0,0.0);
	nom = 0;
	den = 0;
	for (i=0;i<N;i++) {
	  nom += z*float_type(b[i]);
	  den += z*float_type(a[i]);
	  z *= z_inc;
	}
	f[j] = magsq(nom/den);
  }
}
//! \brief frequency magnitude function over "pts" points for FIR
//! \author Tony Kirke
//! \ingroup real_template_array_functions misc
template <class T> void ptr_freqz_fir(complex<float_type>* f, T* x, int N, int pts) {
  int i,j;
  complex<float_type> z;
  complex<float_type> z_inc;
  complex<float_type> nom;
  float_type delta = PI/(float_type)pts;
  float_type freq = 0;
  for (j=0;j<pts;j++) {
	freq += delta;
	z_inc = complex<float_type>(cos(freq),sin(freq));
	z     = complex<float_type>(1.0,0.0);
	nom = 0;
	for (i=0;i<N;i++) {
	  nom += z*float_type(x[i]);
	  z *= z_inc;
	}
	f[j] = nom;
  }
}
} // namespace SPUC
#endif
