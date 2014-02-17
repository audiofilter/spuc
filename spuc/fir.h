#ifndef SPUC_FIR
#define SPUC_FIR

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
// from directory: spuc_double_templates
#include <spuc/spuc_types.h>
#include <spuc/base_type.h>
#include <typeinfo>
#include <spuc/quantiser.h>
#include <spuc/smart_array.h>
#include <spuc/fir_coeff.h>
#include <spuc/mixed_type.h>
namespace SPUC {
//! \file
//! \brief  Template Class for Modeling a Finite Impulse Response filter. 
//
//! \brief  Template Class for Modeling a Finite Impulse Response filter. 
//
//!  Template works for float_type, long, complex, etc
//!  Taps initialized to zeros.
//! \author Tony Kirke
//! \image html fir.png
//! \ingroup double_templates fir
//! \image html fir.gif
//! \image latex fir.eps
template <class Numeric,class Coeff = float_type> class fir
{
 public: 
  smart_array<Coeff> coeff;
  //      protected:
  smart_array<Numeric> z; 
  Numeric output;
  quantiser<Numeric> Q;
  typedef typename base_type<Numeric>::btype Numeric_base;
  typedef typename mixed_type<Numeric,Coeff>::dtype sum_type;
  
 public: 
  long num_taps;
  //! Set tap weights
  void settap(long i, Coeff tap) { coeff[i] = tap; }
  void settaps(fir_coeff<Coeff>& c) {
	for (int i=0;i<num_taps;i++) coeff[i] = c.coeff[i];  
  }
  long number_of_taps() { return(num_taps); }
  Coeff gettap(long i) { return(coeff[i]); }
  //! Reset
  void reset() { 	
	for (int i=0;i<num_taps;i++) z[i] = (Numeric)0;  
	output = (Numeric)0;
  }
  //! Get sum of coefficients
  Coeff coeff_sum() { 
	  int i;
	  Coeff s;
	  for (s=0,i=0;i<num_taps;i++) s += coeff[i];
	  return(s);
  }
	void normalize_gain() {
		float_type c = 1.0/coeff_sum();
		for (int i=0;i<num_taps;i++) coeff[i] *= c; 
	}  
	void make_hpf() {
		bool inv=true;
		for (int i=0;i<num_taps;i++) {
			if (inv) coeff[i] *= -1;
			inv = !inv;
		}
	}  

  //! Get current output
  Numeric out() { return(output); }
  //! Clock in new sample & compute current output
  Numeric check(long i) { return(z[i]); }
  void set_round_bits(long x) {	Q.set_bits(x);  }
  ~fir(void) {  }
  //! Constructor
  fir(void) { ;}
  //! Constructor
  fir(long n, long rb=0) : coeff(n), z(n), Q(rb), num_taps(n)
	{
	  SPUC_ASSERT(n<0);
	  int i;
	  if (n>0) {
		for (i=0;i<n;i++) z[i] = (Numeric)0;
		for (i=0;i<n;i++) coeff[i] = (Coeff)0;  
	  }
	}
  //! Constructor
  fir(fir_coeff<Coeff> C) : coeff(C.num_taps), z(C.num_taps)  {
	  int i;
	  int n = num_taps = C.num_taps;
	  if (n>0) {
		coeff.resize(n);
		z.resize(n);
		for (i=0;i<n;i++) z[i] = (Numeric)0;
		for (i=0;i<n;i++) coeff[i] = C.coeff[i];  
	  }
	}
  //! Set size of Filter 
  void set_size(long n) 
	{
	  int i;
	  num_taps = n;
	  if (n>0) {
		coeff.resize(n);
		z.resize(n);
		for (i=0;i<n;i++) z[i] = (Numeric)0;
		for (i=0;i<n;i++) coeff[i] = (Coeff)0;  
	  } else {
	    coeff.resize(0);
	    z.resize(0);
	  }

	}
  long get_size(void) { return(num_taps); }
  //!  Constructor that gets coefficients from file (requires fir.cpp) 
  fir(const char* file) { read_taps(file); }
  // Assign fir of one type to another
  //  template <class T1> fir<T> operator= (fir<T1> const&);
  //! Update filter by inputting 1 sample and returning convolved output sample.
  Numeric clock(Numeric in) { return(update(in)); }
  Numeric update(Numeric in) {
	int i;  
	sum_type sum(0);
	// Update history of inputs
	for (i=num_taps-1;i>0;i--) z[i] = z[i-1];  
	// Add new input
	z[0] = in;   
	// Perform FIR
	for (i=0;i<num_taps;i++) sum = sum + coeff[i]*z[i];
 
	output = Q(sum);
	return(output);
  }
  // Tapped delay line uses previous outputs (to behave like an IIR)
  Numeric iir(Numeric in) {
	typename mixed_type<Numeric,Coeff>::dtype sum;
	int i;
	for (sum=0,i=0;i<num_taps;i++) sum = sum + coeff[i]*z[i];
	// Update history of outputs
	for (i=num_taps-1;i>0;i--) z[i] = z[i-1];  
 
	output = Q(sum+in);
	// Add new output to delay line
	z[0] = output;   
	return(output);
  }
  int read_taps(const char* file) {
	fir_coeff<Coeff> c(num_taps);
	int r = c.read_taps(file);
	for (int i=0;i<num_taps;i++) coeff[i] = c.coeff[i];
	return(r);
  }
  //  int read_complex_taps(const char* file);
  void print(void) {
	fir_coeff<Coeff> c(num_taps);
	for (int i=0;i<num_taps;i++) c.coeff[i] = coeff[i];
	c.print();
  }

  template <class N,class C>   friend smart_array<C> get_taps(fir<N,C> x);
  template <class N,class C>   friend smart_array<N> get_input(fir<N,C> y);
  void settap(smart_array<Coeff> z) {
	  for (int i=0;i<num_taps;i++) coeff[i] = z[i]; 
  }  
};    

template <class Numeric, class Coeff> smart_array<Coeff> get_taps(fir<Numeric,Coeff> f) {
	long N = f.num_taps;
	smart_array<Coeff> V(N);
	for (int i=0;i<N;i++) V[i] = f.coeff[i];
	return(V);
}
template <class Numeric, class Coeff> smart_array<Numeric> get_input(fir<Numeric,Coeff> f) {
	long N = f.num_taps;
	smart_array<Numeric> V(N);
	for (int i=0;i<N;i++) V[i] = f.z[i];
	return(V);
}
} // namespace SPUC
#endif
