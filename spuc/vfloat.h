#ifndef SPUC_VFLOAT
#define SPUC_VFLOAT

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
#ifndef NO_INT_S
#include <spuc/int_s.h>
#endif
namespace SPUC {

#define FLP_FRAC_BITS 9
#define MAX_FRAC_BITS 24
//! \file
//! \brief Floating point number class
//
//! \brief Floating point number class
//
//! \author Tony Kirke
//! \ingroup types base
class vfloat
{

  
public:

  typedef vfloat self;
  long mantissa;
  long exp;
  long frac_bits;
  
  void reset() {
	mantissa = 0;
	frac_bits = FLP_FRAC_BITS;
	exp = frac_bits;
  }
  vfloat() { reset(); }
#ifndef NO_INT_S
  vfloat(const int_s& y) { 
	reset();
	mantissa = (long)y;
  }
#endif
  vfloat(const int& y) { 
	reset();
	from_double((double)y);
  }
  vfloat(const long& y) { 
	reset();
	from_double((double)y);
  }
  void from_double(const double& y) {
	double x = log2(ABS(y));
	int z = (int)floor(x) - frac_bits;
	if (z>0) {
	  mantissa = SPUC_TOLONG(y/(1<<z));
	} else {
	  mantissa = SPUC_TOLONG(y*(1<<-z));
	}
	exp = z;
  }
  double to_double(const self& y) {
	if (y.exp < 0) {
	  return((double)y.mantissa/(1 << -y.exp));  
	} else {
	  return((double)y.mantissa*(1 << y.exp));  
	}
  }
#ifndef FWAY
  vfloat(const double& y) { 
	reset();
	from_double(y);
  }
#else
  vfloat(const double& y) { 
	reset();
	mantissa = SPUC_TOLONG(y/(1<<frac_bits));
	exp = frac_bits;
  }
#endif

public:
  inline self& operator =(const self& y) {   
    mantissa = y.mantissa;
    exp = y.exp;
	return *this; 
  } 
  inline self& operator =(const long& y) {   
    mantissa = (y << exp);
	return *this; 
  } 
  inline self& operator =(const int& y) {   
    mantissa = (y << exp);
	return *this; 
  } 
  inline self& operator =(const double& y) {   
	from_double(y);
	return *this; 
  } 
  inline self& operator +=(const self& r) {
	self z;
	*this = to_double(*this) + to_double(r);
	return *this;
  }
  inline self& operator -=(const self& r) {
	self z;
	*this = to_double(*this) - to_double(r);
	return *this;
  }
  inline self& operator *=(const self& r) {
	self z;
	*this = to_double(*this) * to_double(r);
	return *this;
  }
  inline self& operator /=(const self& r) {
	self z;
	*this = to_double(*this) / to_double(r);
	return *this;
  }

  inline long operator ~() {return(~mantissa);}
  inline bool operator !=(long r) {  return ((mantissa != (r<<exp)));  }
  inline bool operator ==(const self& r) {  
	return ((mantissa == r.mantissa) && (exp = r.exp) &&
			(frac_bits = r.frac_bits));
  }

  inline bool operator <(const self& r) {  
	return((exp < r.exp) || ((exp == r.exp) && (mantissa < r.mantissa))); 
  }
  inline bool operator >(const self& r) {  
	return((exp > r.exp) || ((exp == r.exp) && (mantissa > r.mantissa))); 
  }
  inline bool operator <=(const self& r) {  
	return((exp < r.exp) || ((exp == r.exp) && (mantissa <= r.mantissa))); 
  }
  inline bool operator >=(const self& r) {  
	return((exp > r.exp) || ((exp == r.exp) && (mantissa >= r.mantissa))); 
  }

  inline bool operator <(double r) {  return (((double)*this < r));  }
  inline bool operator <(float r) {  return (((float)*this < r));  }
  inline bool operator <(int r) {  return (((float)*this < (float)r));  }
  inline bool operator <(long r) {  return ((double)*this < (double)r);  }
  inline bool operator >(double r) {  return (((double)*this > r));  }
  inline bool operator >(float r) {  return (((float)*this > r));  }
  inline bool operator >(int r) {  return (((float)*this > (float)r));  }
  inline bool operator >(long r) {  return ((double)*this > (double)r);  }

  inline bool operator <=(double r) {  return (((double)*this <= r));  }
  inline bool operator <=(float r) {  return (((float)*this <= r));  }
  inline bool operator <=(int r) {  return (((float)*this <= (float)r));  }
  inline bool operator <=(long r) {  return ((double)*this <= (double)r);  }
  inline bool operator >=(double r) {  return (((double)*this >= r));  }
  inline bool operator >=(float r) {  return (((float)*this >= r));  }
  inline bool operator >=(int r) {  return (((float)*this >= (float)r));  }
  inline bool operator >=(long r) {  return ((double)*this >= (double)r);  }


  operator int() const {	  
	return((int)floor((double)mantissa/(1 << exp)+0.5));
  }
  operator long () const {
	return((long)floor((double)mantissa/(1 << exp)+0.5));
  }
  operator double () const {	
	if (exp < 0) {
	  return((double)mantissa/(1 << -exp));  
	} else {
	  return((double)mantissa*(1 << exp));  
	}
  }
  operator float () const {	
	if (exp < 0) {
	  return((float)mantissa/(1 << -exp));  
	} else {
	  return((float)mantissa*(1 << exp));  
	}
  }
};
// IO functions
#ifndef PYSTE
std::ostream& operator <<(std::ostream& os, const vfloat& r);
std::istream& operator >>(std::istream& is, vfloat r); 


// ODD CASE.............
inline double operator /(const vfloat& r, const vfloat& l) {
  double x,y;
  x = (double)r;
  y = (double)l;
  if (y != 0) {
	return(x/y);
  }
  return(0.0);  
}
//.........end
inline vfloat operator -(const vfloat& r) {
  vfloat x;
  x = r;
  x.mantissa = -x.mantissa;
  return(x);
}

inline vfloat operator +(const vfloat& r, const vfloat& l) {
  vfloat z;
  double x,y;
  x = (double)r;
  y = (double)l;
  z = (x+y);
  return(z);
}

inline vfloat operator -(const vfloat& r, const vfloat& l) {
  vfloat z;
  double x,y;
  x = (double)r;
  y = (double)l;
  z = (x-y);
  return(z);
}

inline vfloat operator *(const vfloat& r, const vfloat& l) {
  vfloat z;
  double x,y;
  x = (double)r;
  y = (double)l;
  z = (x*y);
  return(z);
}

#define FLP_MULTOP( T1, T2, RESULT) \
  RESULT inline operator +(T1 r, T2 l) { return(r+(RESULT)l); }	\
  RESULT inline operator +(T2 r, T1 l) { return(l+(RESULT)r); }	\
  RESULT inline operator -(T1 r, T2 l) { return(r-(RESULT)l); }	\
  RESULT inline operator -(T2 r, T1 l) { return((RESULT)r-l); }	\
  RESULT inline operator /(T1 r, T2 l) { return(r/(RESULT)l); }	\
  RESULT inline operator /(T2 r, T1 l) { return(l/(RESULT)r); } \
  RESULT inline operator *(T1 r, T2 l) { return(r*(RESULT)l); }	\
  RESULT inline operator *(T2 r, T1 l) { return(l*(RESULT)r); } 

FLP_MULTOP(float,vfloat,float)
FLP_MULTOP(long,vfloat,long)
FLP_MULTOP(double,vfloat,double)
FLP_MULTOP(int,vfloat,int)

vfloat operator <<(vfloat r, const long shift);
vfloat operator >>(vfloat r, const long shift);


#endif
} // namespace SPUC
#endif
