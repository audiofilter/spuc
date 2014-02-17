#ifndef SPUC_VFIXED
#define SPUC_VFIXED

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
// from directory: spuc_types
#include <iostream>
#include <spuc/spuc_defines.h>
#include <cmath>
namespace SPUC {
//! \file
//! \brief Base class for fixed-point integers (<33 bits).
//
//! \brief Base class for fixed-point integers (<33 bits).
//!
//! \author Tony Kirke
//! \ingroup types base
class vfixed
{
  
public:
  typedef vfixed self;
  long q;
  long mask;
  long bits;
  long xbits;
  long sign;
  long frac_bits;
  long int_bits;
  long Fixed;
  
  // protected:
  vfixed() { 
	q = 0;
	bits=32;
	xbits=0;
	mask = 0;
	sign = 0;
	frac_bits=0;
	int_bits=32;
	Fixed = 0;
  }
  vfixed(int y) { 
	q = y;
	bits=32;
	xbits=0;
	mask = 0;
	sign = 0;
	int_bits=32;
	frac_bits=0;
	Fixed = 0;
  }
  vfixed(long y) { 
	q = y;
	bits=32;
	xbits=0;
	mask = 0;
	sign = 0;
	int_bits=32;
	frac_bits=0;
	Fixed = 0;
  }
  vfixed(double y) { 
	// Default assume 16 fractional bits
	q = SPUC_TOLONG(65536*y);
	bits=32;
	xbits=0;
	mask = 0;
	sign = 0;
	int_bits=15;
	frac_bits=16;
	Fixed = 0;
  }
  vfixed(float y) { 
	// Default assume 16 fractional bits
	q = SPUC_TOLONG(65536*y);
	bits=32;
	xbits=0;
	mask = 0;
	sign = 0;
	int_bits=15;
	frac_bits=16;
	Fixed = 0;
  }

public:
  inline self& operator =(const self& y) {   
	xbits = y.bits;
	if (!Fixed) bits = xbits;
	if (frac_bits >= y.frac_bits) {
	  q = (y.q << (frac_bits - y.frac_bits));
	} else {
	  frac_bits = y.frac_bits;
	  q = y.q;
	}
	sign = (y.q & MASK_BIT(bits));
	if (  ((mask&q)!=mask) || ((mask&q)!=0) ) {
		q &= ~mask;
		if (sign) q |= mask;
	}
	return *this; 
  } 
  inline self& operator =(const long& y) {   
    q = (y << frac_bits);
	sign = (y & MASK_BIT(bits));
	if (  ((mask&q)!=mask) || ((mask&q)!=0) ) {
		q &= ~mask;
		if (sign) q |= mask;
	}
	return *this; 
  } 
  inline self& operator =(const int& y) {   
    q = (y << frac_bits);
	sign = (y & MASK_BIT(bits));
	if (  ((mask&q)!=mask) || ((mask&q)!=0) ) {
		q &= ~mask;
		if (sign) q |= mask;
	}
	return *this; 
  } 
  inline self& operator =(const float& y) {   
	q = SPUC_TOLONG(y * (1 << frac_bits));
	return *this; 
  } 
  inline self& operator =(const double& y) {   
	q = SPUC_TOLONG(y * (1 << frac_bits));
	return *this; 
  } 
  inline self& operator +=(const self& y) {
	int tmp_frac_bits = MAX(frac_bits,y.frac_bits);
	int_bits = MAX(int_bits,y.int_bits)+1;
	q = (y.q << (tmp_frac_bits - y.frac_bits)) + (q << (tmp_frac_bits - frac_bits));
	frac_bits = tmp_frac_bits;
	return *this;  
  }
  inline self& operator -=(const self& y) {
	int tmp_frac_bits = MAX(frac_bits,y.frac_bits);
	int_bits = MAX(int_bits,y.int_bits)+1;
	q = (-y.q << (tmp_frac_bits - y.frac_bits)) + (q << (tmp_frac_bits - frac_bits));
	frac_bits = tmp_frac_bits;
	return *this;  
  }
  // Force y to float_type and re-quantize!
  inline self& operator *=(const self& y) {
	q = SPUC_TOLONG((float_type)q*(float_type)y);
	return *this;  
  }
  // Force y to float_type and re-quantize!
  inline self& operator /=(const self& y) {
	q = SPUC_TOLONG((float_type)q/(float_type)y);
	return *this;  
  }

  inline long operator ~() {return(~q);}
  inline bool operator !() {return(!q);}
  inline bool operator ==(const self& r) {  return ((q == r.q));  }
  inline bool operator ==(long r) {  return ((q == (r<<frac_bits)));  }
  inline bool operator !=(const self& r) {  return ((q != r.q));  }
  inline bool operator !=(long r) {  return ((q != (r<<frac_bits)));  }

  inline bool operator >(const self& r) {  return ((q > r.q));  }
  inline bool operator >(float r) {  return (((float)q > r));  }
  inline bool operator >(double r) {  return (((double)q > r));  }
  inline bool operator >(int r) {  return ((q > r));  }
  inline bool operator >(long r) {  return ((q > r));  }

  inline bool operator <(const self& r) {  return ((q < r.q));  }
  inline bool operator <(float r) {  return (((float)q < r));  }
  inline bool operator <(double r) {  return (((double)q < r));  }
  inline bool operator <(int r) {  return ((q < r));  }
  inline bool operator <(long r) {  return ((q < r));  }

  inline bool operator >=(const self& r) {  return ((q >= r.q));  }
  inline bool operator >=(float r) {  return (((float)q >= r));  }
  inline bool operator >=(double r) {  return (((double)q >= r));  }
  inline bool operator >=(int r) {  return ((q >= r));  }
  inline bool operator >=(long r) {  return ((q >= r));  }

  inline bool operator <=(const self& r) {  return ((q <= r.q));  }
  inline bool operator <=(float r) {  return (((float)q <= r));  }
  inline bool operator <=(double r) {  return (((double)q <= r));  }
  inline bool operator <=(int r) {  return ((q <= r));  }
  inline bool operator <=(long r) {  return ((q <= r));  }

  operator int() const {	return((q + (1 << (frac_bits-1)))>> frac_bits);   }
  operator long () const {return((q + (1 << (frac_bits-1)))>> frac_bits);   }
  operator float () const {	return((float)q/(1 << frac_bits));    }
  operator double () const {	return((double)q/(1 << frac_bits));    }
  inline bool bit(long i) { return (q & MASK_BIT(i)) ? 1 : 0; }
};
// IO functions
#ifndef PYSTE
std::ostream& operator <<(std::ostream& os, vfixed r);
std::istream& operator >>(std::istream& is, vfixed r); 

vfixed operator %(const vfixed& r, const vfixed& l);
vfixed operator +(const vfixed& r, const vfixed& l);
vfixed operator -(const vfixed& r, const vfixed& l);
vfixed operator -(const vfixed& r);
vfixed operator *(const vfixed& r, const vfixed& l);
vfixed operator <<(const vfixed& r, const long shift);
vfixed operator >>(const vfixed& r, const long shift);

float_type operator /(const vfixed& r, const vfixed& l);

#define INTFP_OPS( T1, T2, RESULT) \
  RESULT inline operator *(T1 r, T2 l) { return((RESULT)r*(RESULT)l); }	\
  RESULT inline operator *(T2 r, T1 l) { return((RESULT)l*(RESULT)r); } \
  RESULT inline operator +(T1 r, T2 l) { return((RESULT)r+(RESULT)l); }	\
  RESULT inline operator +(T2 r, T1 l) { return((RESULT)l+(RESULT)r); } \
  RESULT inline operator -(T1 r, T2 l) { return((RESULT)r-(RESULT)l); }	\
  RESULT inline operator -(T2 r, T1 l) { return((RESULT)l-(RESULT)r); } \
  RESULT inline operator /(T1 r, T2 l) { return((RESULT)r/(RESULT)l); }	\
  RESULT inline operator /(T2 r, T1 l) { return((RESULT)l/(RESULT)r); } 


INTFP_OPS(float,vfixed,float)
INTFP_OPS(double,vfixed,double)
INTFP_OPS(int,vfixed,int)

vfixed operator *(long r, const vfixed& l);
vfixed operator *(const vfixed& r, long l);


#endif
} // namespace SPUC
#endif
