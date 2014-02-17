#ifndef SPUC_INT_S
#define SPUC_INT_S

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
//! \brief Base class for signed integers (<33 bits).
//
//! \brief Base class for signed integers (<33 bits).
//
//!   Base class for signed integers with less than 33 bits
//!  similar to 32 bit integers with appropriate overflows and
//!  extra functions
//! \author Tony Kirke
//! \ingroup types base
typedef long natural;
class int_s
{

  
public:
  typedef int_s self;
  long q;
  long mask;
  long bits;
  long xbits;
  long sign;
  long Fixed;
  
  // protected:
  int_s() { 
	q = 0;
	bits=32;
	xbits=0;
	mask = 0;
	sign = 0;
	Fixed = 0;
  }
  int_s(const int& y) { 
	q = y;
	bits=32;
	xbits=0;
	mask = 0;
	sign = 0;
	Fixed = 0;
  }
  int_s(const long& y) { 
	q = y;
	bits=32;
	xbits=0;
	mask = 0;
	sign = 0;
	Fixed = 0;
  }
  int_s(const float& y) {
	q = SPUC_TOLONG(y);
	bits=32;
	xbits=0;
	mask = 0;
	sign = 0;
	Fixed = 0;
  }
  int_s(const double& y) {
	q = SPUC_TOLONG(y);
	bits=32;
	xbits=0;
	mask = 0;
	sign = 0;
	Fixed = 0;
  }

public:
 inline self& operator =(const self& y) {   
    q = y.q;
	xbits = y.bits;
	if (!Fixed) bits = xbits;
	sign = (y.q & MASK_BIT(bits));
	if (  ((mask&q)!=mask) || ((mask&q)!=0) ) {
		q &= ~mask;
		if (sign) q |= mask;
	}
	return *this; 
  } 
  inline self& operator =(const long& y) {   
    q = y;
	sign = (y & MASK_BIT(bits));
	if (  ((mask&q)!=mask) || ((mask&q)!=0) ) {
		q &= ~mask;
		if (sign) q |= mask;
	}
	return *this; 
  } 
  self operator ++() {
	if (q==~mask) q=mask;
	else q++;
	return *this;  
  }

  inline self& operator --() {
	if (q==mask) q=~mask;
	else q--;
	return *this;  
  }
  
  inline self& operator ++(int) {
	if (q==~mask) q=mask;
	else q++;
	return *this;  
  }
  
  inline self& operator --(int) {
	if (q==mask) q=~mask;
	else q--;
	return *this;  
  }
  
  inline self& operator +=(const self& r) {
	q += r.q;
	if (  ((mask&q)!=mask) || ((mask&q)!=0) ) q &= ~mask;
	return *this;  
  }

  inline self& operator +=(const double& r) {
	q += SPUC_TOLONG(r);
	if (  ((mask&q)!=mask) || ((mask&q)!=0) ) q &= ~mask;
	return *this;  
  }

  inline self& operator +=(const float& r) {
	q += SPUC_TOLONG(r);
	if (  ((mask&q)!=mask) || ((mask&q)!=0) ) q &= ~mask;
	return *this;  
  }

  inline self& operator +=(const long& r) {
	  q += r;
	  if (  ((mask&q)!=mask) || ((mask&q)!=0) ) q &= ~mask;
	  return *this;  
  }
  
  inline self& operator -=(const self& r){
	q -= r.q;
	if (  ((mask&q)!=mask) || ((mask&q)!=0) ) q &= ~mask;
	return *this;  
  }
  
  inline self& operator *=(const self& r) {
	q *= r.q;
	if (  ((mask&q)!=mask) || ((mask&q)!=0) ) q &= ~mask;
	return *this;  
  }

  inline self& operator *=(long r) {
	q *= r;
	if (  ((mask&q)!=mask) || ((mask&q)!=0) ) q &= ~mask;
	return *this;  
  }
  
  inline self& operator /=(const self& r){
	if (r.q != 0) q = q/r.q;
	else    q = 0;
	return *this;  
  }
  
  inline self& operator <<=(const long& shift)  {
	q = q << shift;
	return *this;
  }
  
  inline self&  operator >>=(const long& shift) {
	q = q >> shift;
	return *this;
  }
  
  
  inline self& operator ^=(const self& r) {
	q ^= r.q;
	return *this;  
  }
  
  inline self& operator &=(const self& r) {
	q &= r.q;
	return *this;  
  }
  
  inline self& operator |=(const self& r) {
	if (r.q<0) q |= r.q;
	else q |= (r.q & ~mask);
	return *this;  
  }

  inline long operator ~() {return(~q);}
  inline bool operator !() {return(!q);}
  inline bool operator ==(const self& r) {  return ((q == r.q));  }
  inline bool operator ==(long r) {  return ((q == r));  }
  inline bool operator !=(const self& r) {  return ((q != r.q));  }
  inline bool operator !=(long r) {  return ((q != r));  }

  //  inline bool operator >(self& r) {  return ((q > r.q));  }
  //  inline bool operator >(double r) {  return (((double)q > r));  }
  //  inline bool operator >(float r) {  return (((float)q > r));  }
  //  inline bool operator >(int r) {  return ((q > r));  }
  //  inline bool operator >(long r) {  return ((q > r));  }

  //  inline bool operator <(self& r) {  return ((q < r.q));  }
  //  inline bool operator <(double r) {  return (((double)q < r));  }
  //  inline bool operator <(float r) {  return (((float)q < r));  }
  //  inline bool operator <(int r) {  return ((q < r));  }
  //  inline bool operator <(long r) {  return ((q < r));  }

  //  inline bool operator >=(const self& r) {  return ((q >= r.q));  }
  //  inline bool operator >=(double r) {  return (((double)q >= r));  }
  //  inline bool operator >=(float r) {  return (((float)q >= r));  }
  //  inline bool operator >=(int r) {  return ((q >= r));  }
  //  inline bool operator >=(long r) {  return ((q >= r));  }

  //  inline bool operator <=(const self& r) {  return ((q <= r.q));  }
  //  inline bool operator <=(double r) {  return (((double)q <= r));  }
  //  inline bool operator <=(float r) {  return (((float)q <= r));  }
  //  inline bool operator <=(int r) {  return ((q <= r));  }
  //  inline bool operator <=(long r) {  return ((q <= r));  }

  operator int() const {	  return(q);  }
  operator long () const {	  return(q);  }
  operator float () const {	  return((float)q);  }
  operator double () const {	  return((double)q);  }
  inline bool bit(long i) { return (q & MASK_BIT(i)) ? 1 : 0; }
};
// IO functions
#ifndef PYSTE
std::ostream& operator <<(std::ostream& os, int_s r);
std::istream& operator >>(std::istream& is, int_s r); 

bool  operator >(const int_s& r, const int_s&l);
bool  operator <(const int_s& r, const int_s&l);
int_s operator %(const int_s& r, const int_s& l);
int_s operator +(const int_s& r, const int_s& l);
int_s operator -(const int_s& r, const int_s& l);
int_s operator -(const int_s& r);
int_s operator &(const int_s& r, const int_s& l);
int_s operator ^(const int_s& r, const int_s& l);
int_s operator |(const int_s& r, const int_s& l);

int_s operator /(const int_s& r, const int_s& l);
int_s operator <<(const int_s& r, const long shift);
int_s operator >>(const int_s& r, const long shift);
int_s operator ,(const int_s& r, const int_s& l);

int_s clip(int_s in, int_s min_clp,int_s max_clp);
bool or_bits(const int_s& r);

int_s operator *(const int_s& r, const int_s& l);


#define INTS_MULTOP( T1, T2, RESULT) \
  RESULT inline operator +(T1 r, T2 l) { return(r+(RESULT)l); }	\
  RESULT inline operator +(T2 r, T1 l) { return(l+(RESULT)r); }	\
  RESULT inline operator -(T1 r, T2 l) { return(r-(RESULT)l); }	\
  RESULT inline operator -(T2 r, T1 l) { return((RESULT)r-l); }	\
  RESULT inline operator /(T1 r, T2 l) { return(r/(RESULT)l); }	\
  RESULT inline operator /(T2 r, T1 l) { return(l/(RESULT)r); } \
  RESULT inline operator *(T1 r, T2 l) { return(r*(RESULT)l); }	\
  RESULT inline operator *(T2 r, T1 l) { return(l*(RESULT)r); } 

#define LOG_INTS_MULTOP( T1, T2, RESULT) \
  RESULT inline operator &(T1 r, T2 l) { return(r&(RESULT)l); }	\
  RESULT inline operator &(T2 r, T1 l) { return(l&(RESULT)r); }	\
  RESULT inline operator %(T1 r, T2 l) { return(r%(RESULT)l); }	\
  RESULT inline operator %(T2 r, T1 l) { return(l%(RESULT)r); }	\
  RESULT inline operator ^(T1 r, T2 l) { return(r^(RESULT)l); }	\
  RESULT inline operator ^(T2 r, T1 l) { return(l^(RESULT)r); }	\
  RESULT inline operator |(T1 r, T2 l) { return(r|(RESULT)l); }	\
  RESULT inline operator |(T2 r, T1 l) { return(l|(RESULT)r); }	

INTS_MULTOP(float,int_s,float)
INTS_MULTOP(long,int_s,long)
INTS_MULTOP(double,int_s,double)
INTS_MULTOP(int,int_s,int)

LOG_INTS_MULTOP(long,int_s,long)
LOG_INTS_MULTOP(int,int_s,int)

#define INTS_COMPAREOP(T1, T2) \
  bool inline operator >(T1 r, T2 l) { return(r>(T1)l); }	\
  bool inline operator >(T2 r, T1 l) { return(l>(T1)r); }	\
  bool inline operator <(T1 r, T2 l) { return(r<(T1)l); }	\
  bool inline operator <(T2 r, T1 l) { return((T1)r<l); }	\
  bool inline operator >=(T1 r, T2 l) { return(r>=(T1)l); }	\
  bool inline operator >=(T2 r, T1 l) { return(l>=(T1)r); }	\
  bool inline operator <=(T1 r, T2 l) { return(r<=(T1)l); }	\
  bool inline operator <=(T2 r, T1 l) { return((T1)r<=l); }	

INTS_COMPAREOP(float,int_s)
INTS_COMPAREOP(long,int_s)
INTS_COMPAREOP(double,int_s)
INTS_COMPAREOP(int,int_s)

#endif
} // namespace SPUC
#endif
