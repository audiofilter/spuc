#ifndef SPUC_FPINT
#define SPUC_FPINT

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
// from directory: spuc_n_templates
#include <spuc/spuc_types.h>
#include <spuc/vfixed.h>
#ifndef NO_INT_S
#include <spuc/int_s.h>
#endif
#include <iostream>
//#define STOP_CSTR_OVR 1
namespace SPUC {
//! \file
//! \brief Template class for fixed-point integers (<33 bits).
//
//! \brief Template class for fixed-point integers (<33 bits).
//
//!    The template parameter is the number of bits in the fractional part
//!	(default 0).  Derived from base class vfixed.  
//! \author Tony Kirke
//! \ingroup n_templates base
template <long Int_Bits, long Frac_Bits=0> class fpint : public vfixed
{
public:
  fpint<Int_Bits,Frac_Bits> () { 
	int_bits = Int_Bits;
	frac_bits = Frac_Bits;
	bits=int_bits+frac_bits;
	mask = -1 << bits; 
  }
  fpint<Int_Bits,Frac_Bits>(int y) {
	int_bits = Int_Bits;
	frac_bits = Frac_Bits;
	bits=int_bits+frac_bits;
	mask = -1 << bits;
	q = y << Frac_Bits;
	if (((mask&q)==mask) || ((mask&q)==0)) {
	  //	  std::cout << "Init with (int) y = " << y << " " << q << "\n";
	} else {
	  std::cout << "Overflow in fpint<> constructor, ";
	  std::cout << "in " << __FILE__ << " on line " << __LINE__ << " ";
	  std::cout << "Input = " << y << " Max value = " << (~mask)/(1<<Frac_Bits) << "\n";
#ifdef STOP_CSTR_OVR
	  abort();
#endif
	  q &= ~mask;
	  if (y>0) q = ~q;
	}
  }
  fpint<Int_Bits,Frac_Bits>(long y) { 
	int_bits = Int_Bits;
	frac_bits = Frac_Bits;
	bits=int_bits+frac_bits;
	mask = -1 << bits;
	q = y << Frac_Bits;
	if (((mask&q)==mask) || ((mask&q)==0)) {
	  //	  std::cout << "Init with (long) y = " << y << " " << q << "\n";
	} else {
	  std::cout << "Overflow in fpint<> constructor, ";
	  std::cout << "in " << __FILE__ << " on line " << __LINE__ << " ";
	  std::cout << "Input = " << (double)y << " Max value = " << ~mask << "\n";
#ifdef STOP_CSTR_OVR
	  abort();
#endif
	  q &= ~mask;
	  if (y>0) q = ~q;
	}
  }
  fpint<Int_Bits,Frac_Bits>(double y) { 
	int_bits = Int_Bits;
	frac_bits = Frac_Bits;
	bits=int_bits+frac_bits;
	mask = -1 << bits;
	q = SPUC_TOLONG(y * (1 << frac_bits));
	if (((mask&q)==mask) || ((mask&q)==0)) {
	  //		std::cout << "Init with (double) y = " << y << " " << q << "\n";
	} else {
	  std::cout << "Overflow in fpint<> constructor, ";
	  std::cout << "in " << __FILE__ << " on line " << __LINE__ << " ";
	  //	  std::cout << "Input = " << q << " Max value = " << (~mask) << "\n";
	  std::cout << "Input = " << (double)y << " Max value = " << (~mask)/(1<<frac_bits) << "\n";
#ifdef STOP_CSTR_OVR
	  abort();
#endif
	  q &= ~mask;
	  if (y>0) q = ~q;
	}
  }//?
  // New......for promotion purposes
  // Check this for functionality........!!!!
#ifndef NO_INT_S
  fpint<Int_Bits,Frac_Bits>(int_s x) {
	long y = (long)x;
	  int_bits = Int_Bits;
	  frac_bits = Frac_Bits;
	  bits=int_bits+frac_bits;
	  mask = -1 << bits;
	  q = y << Frac_Bits;
	  if (((mask&q)==mask) || ((mask&q)==0)) {
		  //	  std::cout << "Init with (long) y = " << y << " " << q << "\n";
	  } else {
		  std::cout << "Overflow in fpint<> constructor, ";
		  std::cout << "in " << __FILE__ << " on line " << __LINE__ << " ";
		  std::cout << "Input = " << (double)y << " Max value = " << ~mask << "\n";
#ifdef STOP_CSTR_OVR
		  abort();
#endif
		  q &= ~mask;
		  if (y>0) q = ~q;
	  }
  }
#endif 
  // New......for promotion purposes
  // Check this for functionality........!!!!
  fpint<Int_Bits,Frac_Bits>(vfixed y) { 
	int_bits = Int_Bits;
	frac_bits = Frac_Bits;
	bits=int_bits+frac_bits;
	mask = -1 << bits;
	q = y.q << (Frac_Bits - y.frac_bits);
	if (((mask&q)==mask) || ((mask&q)==0)) {
	  //		std::cout << "Init with (double) y = " << y << " " << q << "\n";
	} else {
	  std::cout << "Overflow in fpint<> constructor, ";
	  std::cout << "in " << __FILE__ << " on line " << __LINE__ << " ";
	  std::cout << "Input = " << (double)y << " Max value = " << ~mask << "\n";
#ifdef STOP_CSTR_OVR
	  abort();
#endif
	  q &= ~mask;
	  if (y>0) q = ~q;
	}
  }//?
  inline fpint<Int_Bits,Frac_Bits> operator =(const vfixed& y) {   
	q = y.q << (Frac_Bits - y.frac_bits);
	xbits = y.bits;
	sign = (y.q & (1 << bits));
	if (  ((mask&q)!=mask) || ((mask&q)!=0) ) {
	  q &= ~mask;
	  if (sign) q |= mask;
	}
	return *this; 
  } 
  inline fpint<Int_Bits,Frac_Bits> operator =(const double& y) {   
	q = SPUC_TOLONG(y * (1 << frac_bits));
	if (((mask&q)==mask) || ((mask&q)==0) ) {
	} else {
	  std::cout << "Overflow in fpint<> assignment, ";
	  std::cout << "in " << __FILE__ << " on line " << __LINE__ << " ";
	  //	  std::cout << "Input = " << q << " Max value = " << (~mask) << "\n";
	  std::cout << "Input = " << (double)y << " Max value = " << (~mask)/(1<<frac_bits) << "\n";
#ifdef STOP_CSTR_OVR
	  abort();
#endif
	  q &= ~mask;
	  if (y>0) q = ~q;
	}
	return *this; 
  } 
  inline fpint<Int_Bits,Frac_Bits> operator =(const long& y) { 
	q = (y << Frac_Bits);	
	sign = (y & (1 << bits));
	if (  ((mask&q)!=mask) || ((mask&q)!=0) ) {
	  q &= ~mask;
	  if (sign) q |= mask;
	}
	return *this; 
  } 
};
// template_instantiations: 5,6
} // namespace SPUC
#endif
