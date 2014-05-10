#ifndef SPUC_BUILTIN
#define SPUC_BUILTIN

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
#include <iostream>
#include <spuc/spuc_defines.h>
namespace SPUC {

//! \file 
//! \brief Wrapper around built-in types to allow custom manipulations
//
//! \brief Wrapper around built-in types to allow custom manipulations
//
//! \author Tony Kirke
//! \ingroup types base
template <class T> class builtin {
public:
  // use template
  builtin();
  // explicit initializations - allows type conversion without
  // warning messages
  builtin(double new_value);
  builtin(long new_value);
  builtin(int new_value);
  builtin(float new_value);
  builtin(const builtin<T> & other);
  ~builtin(void);
  
  builtin<T> & operator  =(const builtin<T> & other);
  builtin<T> & operator +=(const builtin<T> & other);
  builtin<T> & operator -=(const builtin<T> & other);
  builtin<T> & operator *=(const builtin<T> & other);
  builtin<T> & operator /=(const builtin<T> & other);
  //  builtin<T> & operator %=(const builtin<T> & other);
  //  builtin<T> & operator<<=(const builtin<T> & other);
  //  builtin<T> & operator>>=(const builtin<T> & other);
  //  builtin<T> & operator &=(const builtin<T> & other);
  //  builtin<T> & operator |=(const builtin<T> & other);
  //  builtin<T> & operator ^=(const builtin<T> & other);
  
  //  builtin<T> & operator++(void); // prefix  ++. returns an lvalue.
  //  builtin<T>   operator++(int);  // postfix ++. returns an rvalue.
  //  builtin<T> & operator--(void); // prefix  --. returns an lvalue.
  //  builtin<T>   operator--(int);  // postfix --. returns an rvalue.
  
  operator T const &() const { return(value); }
  
  const T * operator&(void) const;
  T * operator&(void)      ;
  
private:
  T value;
  
};

// members:

template <class T> inline builtin<T>::builtin() {  value = 0;}
// These casts don't create problems when going to double
template <class T> inline builtin<T>::builtin(long new_value) {
	value = (T)new_value;
}
template <class T> inline builtin<T>::builtin(int new_value) {
	value = (T)new_value;
}
// specialize this one later
template <class T> inline builtin<T>::builtin(double new_value) {
	value = (T)new_value;
}
template <class T> inline builtin<T>::builtin(float new_value) {
	value = (T)new_value;
}

template <class T> inline builtin<T>::builtin(const builtin<T> & other) {
  value = other.value;
  
}

template <class T> inline builtin<T>::~builtin(void) {

}

template <class T> inline builtin<T> & builtin<T>::operator=(const builtin<T> & other) {
  value = other.value;
  return *this;
}

template <class T> inline builtin<T> & builtin<T>::operator+=(const builtin<T> & other) {
  value += other.value;
  return *this;
}

template <class T> inline builtin<T> & builtin<T>::operator-=(const builtin<T> & other) {
  value -= other.value;
  return *this;
}

template <class T> inline builtin<T> & builtin<T>::operator*=(const builtin<T> & other) {
  value *= other.value;
  return *this;
}

template <class T> inline builtin<T> & builtin<T>::operator/=(const builtin<T> & other) {
  value /= other.value;
  return *this;
}

/*
  template <class T> inline builtin<T> & builtin<T>::operator%=(const builtin<T> & other)
  {
  value %= other.value;
  return *this;
  }

  template <class T> inline builtin<T> & builtin<T>::operator<<=(const builtin<T> & other)
  {
  value <<= other.value;
  return *this;
  }

  template <class T> inline builtin<T> & builtin<T>::operator>>=(const builtin<T> & other)
  {
  value >>= other.value;
  return *this;
  }

  template <class T> inline builtin<T> & builtin<T>::operator&=(const builtin<T> & other)
  {
  value &= other.value;
  return *this;
  }

  template <class T> inline builtin<T> & builtin<T>::operator|=(const builtin<T> & other)
  {
  value |= other.value;
  return *this;
  }

  template <class T> inline builtin<T> & builtin<T>::operator^=(const builtin<T> & other)
  {
  value ^= other.value;
  return *this;
  }
template <class T> inline builtin<T> & builtin<T>::operator++(void) // prefix ++. returns an lvalue. 
{
  ++value;
  return *this;
}

template <class T> inline builtin<T> builtin<T>::operator++(int) // postfix ++. returns an rvalue. 
{
  T result(value);
  value++;
  return result;
}

template <class T> inline builtin<T> & builtin<T>::operator--(void) // prefix --. returns an lvalue. 
{
  --value;
  return *this;
}

template <class T> inline builtin<T> builtin<T>::operator--(int) // postfix --. returns an rvalue. 
{
  T result(value);
  value--;
  return result;
}
*/

template <class T> inline const T * builtin<T>::operator&(void) const {
  return &value;
}

template <class T> inline T * builtin<T>::operator&(void) {
  return &value;
}

// non-members:
// unary:

template <class T> inline builtin<T> operator+(const builtin<T> & bi) {
  return bi;
}

template <class T> inline builtin<T> operator-(const builtin<T> & bi) {
  return -((T) bi);
}

template <class T> inline builtin<T> operator~(const builtin<T> & bi) {
  return ~((T) bi);
}

template <class T> inline builtin<T> operator!(const builtin<T> & bi) {
  return !((T) bi);
}

// binary:
template <class T> inline std::istream & operator>>(std::istream & s, builtin<T> & bi) {
  T local_t;
  s >> local_t;
  bi = local_t;
  return s;
}

template <class T> inline std::ostream & operator<<(std::ostream & s, const builtin<T> & bi) {
  s << ((T) bi);
  return s;
}

template <class T> inline builtin<T> operator>>(const builtin<T> & bi, int i) {
  return ((T) bi) >> i;
}

template <class T> inline builtin<T> operator<<(const builtin<T> & bi, int i) {
  return ((T) bi) << i;
}
template <class T> inline builtin<T> operator>>(const builtin<T> & bi, long i) {
  return ((T) bi) >> i;
}

template <class T> inline builtin<T> operator<<(const builtin<T> & bi, long i) {
  return ((T) bi) << i;
}

template <class T> inline bool operator==(const builtin<T> & bi1, const builtin<T> & bi2) {
  return ((T) bi1) == ((T) bi2);
}

template <class T> inline bool operator!=(const builtin<T> & bi1, const builtin<T> & bi2) {
  return ((T) bi1) != ((T) bi2);
}

template <class T> inline bool operator<(const builtin<T> & bi1, const builtin<T> & bi2) {
  return ((T) bi1) < ((T) bi2);
}

template <class T> inline bool operator<=(const builtin<T> & bi1, const builtin<T> & bi2) {
  return ((T) bi1) <= ((T) bi2);
}

template <class T> inline bool operator>(const builtin<T> & bi1, const builtin<T> & bi2) {
  return ((T) bi1) > ((T) bi2);
}

template <class T> inline bool operator>=(const builtin<T> & bi1, const builtin<T> & bi2) {
  return ((T) bi1) >= ((T) bi2);
}

template <class T> inline builtin<T> operator+(const builtin<T> & bi1, const builtin<T> & bi2) {
  return ((T) bi1) + ((T) bi2);
}

template <class T> inline builtin<T> operator-(const builtin<T> & bi1, const builtin<T> & bi2) {
  return ((T) bi1) - ((T) bi2);
}

template <class T> inline builtin<T> operator*(const builtin<T> & bi1, const builtin<T> & bi2) {
  return ((T) bi1) * ((T) bi2);
}

template <class T> inline builtin<T> operator/(const builtin<T> & bi1, const builtin<T> & bi2) {
  return ((T) bi1) / ((T) bi2);
}

/*
  template <class T> inline builtin<T> operator%(const builtin<T> & bi1, const builtin<T> & bi2)
  {
  return ((T) bi1) % ((T) bi2);
  }

  template <class T> inline builtin<T> operator&(const builtin<T> & bi1, const builtin<T> & bi2)
  {
  return ((T) bi1) & ((T) bi2);

  }

  template <class T> inline builtin<T> operator^(const builtin<T> & bi1, const builtin<T> & bi2)
  {
  return ((T) bi1) ^ ((T) bi2);

  }

  template <class T> inline builtin<T> operator|(const builtin<T> & bi1, const builtin<T> & bi2)
  {
  return ((T) bi1) | ((T) bi2);

  }
*/
//--------------------------------------------------------------------------------------

template <> inline builtin<double> operator<<(const builtin<double> & bi, int i)  {
  double x = (double)(1<<i)*(double)bi;
  return(builtin<double>(x));
}

template <> inline builtin<double> operator>>(const builtin<double> & bi, int i)  {
  double x = (double)(bi)/(double)(1<<i);
  return(builtin<double>(x));
}

template <> inline builtin<double> operator<<(const builtin<double> & bi, long i)  {
  double x = (double)(1<<i)*(double)bi;
  return(builtin<double>(x));
}

template <> inline builtin<double> operator>>(const builtin<double> & bi, long i)  {
  double x = (double)(bi)/(double)(1<<i);
  return(builtin<double>(x));
}

template <> inline builtin<float> operator<<(const builtin<float> & bi, int i)  {
  float x = (float)(1<<i)*(float)bi;
  return(builtin<float>(x));
}

template <> inline builtin<float> operator>>(const builtin<float> & bi, int i)  {
  float x = (float)(bi)/(float)(1<<i);
  return(builtin<float>(x));
}

template <> inline builtin<float> operator<<(const builtin<float> & bi, long i)  {
  float x = (float)(1<<i)*(float)bi;
  return(builtin<float>(x));
}

template <> inline builtin<float> operator>>(const builtin<float> & bi, long i)  {
  float x = (float)(bi)/(float)(1<<i);
  return(builtin<float>(x));
}


// partial specializations...
template <> inline builtin<long>::builtin(double new_value) {
  value = SPUC_TOLONG(new_value);
}
template <> inline builtin<int>::builtin(double new_value) {
  value = SPUC_TOINT(new_value);
}

// partial specializations...
template <> inline builtin<long>::builtin(float new_value) {
  value = SPUC_TOLONG(new_value);
}
template <> inline builtin<int>::builtin(float new_value) {
  value = SPUC_TOINT(new_value);
}

#ifndef PYSTE
#define BUILTIN_OPS( T1, T2, RESULT) \
  RESULT inline operator *(T1 r, T2 l) { return((RESULT)r*(RESULT)l); }	\
  RESULT inline operator *(T2 r, T1 l) { return((RESULT)l*(RESULT)r); } \
  RESULT inline operator +(T1 r, T2 l) { return((RESULT)r+(RESULT)l); }	\
  RESULT inline operator +(T2 r, T1 l) { return((RESULT)l+(RESULT)r); } \
  RESULT inline operator -(T1 r, T2 l) { return((RESULT)r-(RESULT)l); }	\
  RESULT inline operator -(T2 r, T1 l) { return((RESULT)l-(RESULT)r); } 

BUILTIN_OPS(double,Float,double)
BUILTIN_OPS(double,Long,double)
BUILTIN_OPS(double,Int,double)
BUILTIN_OPS(double,Double,double)
BUILTIN_OPS(float,Float,float)
BUILTIN_OPS(float,Long,float)
BUILTIN_OPS(float,Int,float)
BUILTIN_OPS(float,Double,double)
BUILTIN_OPS(long,Float,float)
BUILTIN_OPS(long,Long,long)
BUILTIN_OPS(long,Int,long)
BUILTIN_OPS(long,Double,double)
BUILTIN_OPS(int,Float,float)
BUILTIN_OPS(int,Long,long)
BUILTIN_OPS(int,Int,int)
BUILTIN_OPS(int,Double,double)
BUILTIN_OPS(Float,Long,float)
BUILTIN_OPS(Float,Int,float)
BUILTIN_OPS(Float,Double,double)
BUILTIN_OPS(Long,Int,long)
BUILTIN_OPS(Long,Double,double)
BUILTIN_OPS(Int,Double,double)

#endif

} // namespace SPUC
#endif
