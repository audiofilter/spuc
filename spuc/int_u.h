#ifndef SPUC_INT_U
#define SPUC_INT_U

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
#include <spuc/spuc_types.h>
#include <spuc/spuc_defines.h>
#include <cmath>
namespace SPUC {
//! \file
//! \brief Base class for unsigned integers (<33 bits).
//
//! \brief Base class for unsigned integers (<33 bits).
//
//!  similar to 32 bit integers with appropriate overflows and
//!  extra functions
//! \author Tony Kirke
//! \ingroup types base
#define CLIP(A,B,C) (A>B) ? B : ((A<C) ? C : A)
class int_u
{

	public:
	  long q;
	  long mask;
	  long bits;
	  long bitpos;
      bool oveflow;


//  protected:
	  int_u() { 
		  q = 0;
		  bits = 32;
		  mask = 0;
		  bitpos=0;
	  }
	  int_u(long y) { 
		  q = y;
		  bits = 32;
		  mask = 0;
		  bitpos=0;
	  }

  public:
  inline int_u operator =(const int_u& y) {   
    q = ~mask & y.q;
	return *this; 
  } 
  inline int_u operator =(const long& y) {   
    q = ~mask & y;
	return *this; 
  } 
  int_u operator ++() {
  q++;
  q &= ~mask;
  return *this;  
  }
  int_u operator ++(int) {
  q++;
  q &= ~mask;
  return *this;  
  }
  int_u operator --() {
  q--;
  q &= ~mask;
  return *this;  
  }
  int_u operator --(int) {
  q--;
  q &= ~mask;
  return *this;  
  }
  int_u operator +=(int_u r) {
  q += r.q;
  q &= ~mask;
  return *this;  
  }

  int_u operator -=(int_u r){
  q -= r.q;
  q &= ~mask;
//  if (  ((mask&q)!=mask) || ((mask&q)!=0) ) q &= ~mask;
  return *this;  
  }
  int_u operator *=(int_u r) {
  q *= r.q;
  q &= ~mask;
  return *this;  
  }
  int_u operator /=(int_u r){
  if (r.q != 0) q = q/r.q;
  else    q = 0;
  return *this;  
  }

  int_u operator <<=(const long shift)  {
	  q = q << shift;
	  q &= ~mask;
	  return *this;
  }
  int_u  operator >>=(const long shift) {
	  q = q >> shift;
	  return *this;
  }

  int_u operator ^=(int_u r) {
  q ^= r.q;
  q &= ~mask;
  return *this;  
  }
  int_u operator &=(int_u r) {
  q &= r.q;
  q &= ~mask;
  return *this;  
  }
  int_u operator |=(int_u r) {
  q |= r.q;
  q &= ~mask;
  return *this;  
  }

  inline long operator ~() {return(~q);}
  inline bool operator !() {return(!q);}
  inline bool operator ==(int_u r) {  return ((q == r.q));  }
  inline bool operator ==(long r) {  return ((q == r));  }
  inline bool operator !=(int_u r) {  return ((q != r.q));  }
  inline bool operator !=(long r) {  return ((q != r));  }
  inline bool operator >(int_u r) {  return ((q > r.q));  }
  inline bool operator >(long r) {  return ((q > r));  }
  inline bool operator <(int_u r) {  return ((q < r.q));  }
  inline bool operator <(long r) {  return ((q < r));  }
  operator long () const {	  return(q);  }
  operator double () const {	  return((double)q);  }
  //! Return i'th bit
  inline bool bit(long i) { return (q & MASK_BIT(i)) ? 1 : 0; }
};
// template_instantiations: long, complex<long>, double, complex<double>
//
#ifndef PYSTE
int_u magsq(int_u y);

int_u clip(int_u in, int_u min_clp, int_u max_clp);
bool or_bits(int_u r);
int_u operator %(int_u r, int_u l);
int_u operator %(int_u r, natural l);
int_u operator %(natural r, int_u l);
int_u operator +(int_u r, int_u l);
int_u operator +(int_u r, natural l);
int_u operator +(natural r, int_u l);
int_u operator -(int_u r, int_u l);
int_u operator -(int_u r, natural l);
int_u operator -(natural r, int_u l);
int_u operator &(int_u r, int_u l);
int_u operator &(int_u r, natural l);
int_u operator &(natural r, int_u l);
int_u operator ^(int_u r, int_u l);
int_u operator ^(int_u r, natural l);
int_u operator ^(natural r, int_u l);
int_u operator |(int_u r, int_u l);
int_u operator |(int_u r, natural l);
int_u operator |(natural r, int_u l);
int_u operator *(int_u r, int_u l);
int_u operator *(int_u r, natural l);
int_u operator *(natural r, int_u l);
int_u operator /(int_u r, int_u l);
int_u operator /(natural r, int_u l);
int_u operator /(int_u r, natural l);
int_u operator <<(int_u r, const natural shift) ;
int_u operator >>(int_u r, const natural shift) ;
int_u operator ,(int_u r, int_u l);
#endif
} // namespace SPUC
#endif
