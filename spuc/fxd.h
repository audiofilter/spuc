#ifndef SPUC_FXD
#define SPUC_FXD

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
//! \brief base class for fxd-point integer with 16 bits fractional,
//
//! \brief base class for fxd-point integer with 16 bits fractional,
//
//! 16 bits integer (including sign)
//! \author Tony Kirke
//! \ingroup types base
class fxd {

public:
  typedef fxd self;
  static const long frac_bits;
  long q;
  
  // protected :
  fxd()   { ;}
  fxd(const int& y)   { 
	q = (long)y << frac_bits;
  }
  fxd(const long& y)   { 
	q = y << frac_bits;
  }
  fxd(const double& y)   { 
	// Default assume 16 fractional bits
	q = SPUC_TOLONG(65536*y);
  }

public:
  /*  inline self operator =(const self& y) {   
    q = y.q;
	return *this; 
  } 
  */
  inline self& operator =(const long& y) {   
    q = (y << frac_bits);
	return *this; 
  } 
  inline self& operator =(const int& y) {   
    q = (y << frac_bits);
	return *this; 
  } 
  inline self& operator =(const double& y) {   
	q = SPUC_TOLONG(y * (1 << frac_bits));
	return *this; 
  } 
  inline self& operator +=(const self& y) {   
    q = q + y.q;
	return *this; 
  } 
  inline self& operator -=(const self& y) {   
    q = q - y.q;
	return *this; 
  } 
  inline self& operator *=(self r) {
	q = (q * r.q) >> frac_bits;
	return *this;
  }
  inline self& operator /=(self r) {
	q = q / r.q;
	return *this;
  }

  inline long operator ~() {return(~q);}
  inline bool operator !() {return(!q);}
  inline bool operator ==(self r) {  return ((q == r.q));  }
  inline bool operator ==(long r) {  return ((q == (r<<frac_bits)));  }
  inline bool operator !=(self r) {  return ((q != r.q));  }
  inline bool operator !=(long r) {  return ((q != (r<<frac_bits)));  }

  inline bool operator >(self r) {  return ((q > r.q));  }
  inline bool operator >(double r) {  return (((double)q > r));  }
  inline bool operator >(int r) {  return ((q > r));  }
  inline bool operator >(long r) {  return ((q > r));  }

  inline bool operator <(self r) {  return ((q < r.q));  }
  inline bool operator <(double r) {  return (((double)q < r));  }
  inline bool operator <(int r) {  return ((q < r));  }
  inline bool operator <(long r) {  return ((q < r));  }

  inline bool operator >=(self r) {  return ((q >= r.q));  }
  inline bool operator >=(double r) {  return (((double)q >= r));  }
  inline bool operator >=(int r) {  return ((q >= r));  }
  inline bool operator >=(long r) {  return ((q >= r));  }

  inline bool operator <=(self r) {  return ((q <= r.q));  }
  inline bool operator <=(double r) {  return (((double)q <= r));  }
  inline bool operator <=(int r) {  return ((q <= r));  }
  inline bool operator <=(long r) {  return ((q <= r));  }

  operator int() const {	  
	return((q + (1 << (frac_bits-1)))>> frac_bits); 
  }
  operator long () const {
	return((q + (1 << (frac_bits-1)))>> frac_bits); 
  }
  operator double () const {	  
	return((double)q/(1 << frac_bits));  
  }
  operator float () const {	  
	return((float)q/(1 << frac_bits));  
  }
  inline bool bit(long i) { return (q & MASK_BIT(i)) ? 1 : 0; }
};
// IO functions
#ifndef PYSTE

inline fxd operator *(const fxd& r, const fxd& l) {
  fxd x;
  x.q = (long)(((long long)r.q*(long long)l.q + ((long long)1 << (r.frac_bits-1))) >> r.frac_bits);
  return(x);  
}



inline fxd operator %(const fxd& r, const fxd& l) {
  fxd x;
  x.q = r.q % l.q;
  return(x);
}
inline fxd operator +(const fxd& r, const fxd& l) {
  fxd x;
  x.q = r.q + l.q;
  return(x);
}
inline fxd operator -(const fxd& r, const fxd& l) {
  fxd x;
  x.q = r.q - l.q;
  return(x);
}
inline fxd operator -(const fxd& r) {
  fxd x;
  x.q = -r.q;
  return(x);
}

inline fxd operator /(const fxd& r, const fxd& l) {
  fxd x(r);
  x /= l;
  return(x);
}

inline fxd operator <<(const fxd& r, const long shift)  {
  fxd x;
  x.q = r.q << shift;
  return(x);
}

inline fxd operator >>(const fxd& r, const long shift)  {
  fxd x;
  x.q = r.q >> shift;
  return(x);
}



#define FP_MULTOP( T1, T2, RESULT) \
  RESULT inline operator +(T1 r, T2 l) { return(r+(RESULT)l); }	\
  RESULT inline operator +(T2 r, T1 l) { return(l+(RESULT)r); }	\
  RESULT inline operator -(T1 r, T2 l) { return(r-(RESULT)l); }	\
  RESULT inline operator -(T2 r, T1 l) { return((RESULT)r-l); }	\
  RESULT inline operator /(T1 r, T2 l) { return(r/(RESULT)l); }	\
  RESULT inline operator /(T2 r, T1 l) { return(l/(RESULT)r); } \
  RESULT inline operator *(T1 r, T2 l) { return(r*(RESULT)l); }	\
  RESULT inline operator *(T2 r, T1 l) { return(l*(RESULT)r); } 

FP_MULTOP(float,fxd,float)
FP_MULTOP(long,fxd,long)
FP_MULTOP(double,fxd,double)
FP_MULTOP(int,fxd,int)

// IO functions
std::ostream& operator <<(std::ostream& os, const fxd& r);
std::istream& operator >>(std::istream& is, fxd r);

#endif
} // namespace SPUC
#endif
