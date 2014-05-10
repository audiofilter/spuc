#ifndef SPUC_COMPLEX_OPERATORS
#define SPUC_COMPLEX_OPERATORS

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
namespace SPUC {
// forward declarations
template <class T> class base_type;
template <typename T> typename base_type<T>::btype magsq(T in);
//----------------------T1 + T2 operators----------------------------------
//!
template <typename T1, typename T2> inline bool operator ==(complex<T1> r, complex<T2> l)
{
  return ((real(r) == real(l)) && (imag(r) == imag(l)));  
}

///!
template <typename T1, typename T2> inline bool operator <=(complex<T1> r, complex<T2> l)
{
  return ((real(r) <= real(l)) && (imag(r) <= imag(l)));  
}
///!

template <typename T1, typename T2> inline bool operator <(complex<T1> r, complex<T2> l){
  return ((real(r) < real(l)) && (imag(r) < imag(l)));  
}
///!
template <typename T1, typename T2> inline bool operator >=(complex<T1> r, complex<T2> l)
{
  return ((real(r) >= real(l)) && (imag(r) >= imag(l)));  
}
///!
template <typename T1, typename T2> inline bool operator >(complex<T1> r, complex<T2> l)
{
  return ((real(r) > real(l)) && (imag(r) > imag(l)));  
}

//!
template <typename T1, typename T2> inline bool operator !=(complex<T1> r, complex<T2> l)
{
  return ((real(r) != real(l)) || (imag(r) != imag(l)));  
}
// Combination operators, order is important because inline
/*
don't repeate these ones.....
*/
#define COMPLEX_SINGOP( T1, T2, RESULT) \
complex<RESULT> inline operator -(complex<T1> r, complex<T2> l) { \
ASP_C(cadd_count) \
return complex<RESULT>((RESULT)r.re-(RESULT)l.re,(RESULT)r.im-(RESULT)l.im); } \
complex<RESULT> inline operator -(T1 r, complex<T2> l) { \
ASP_C(hcadd_count)                                      \
return complex<RESULT>(((RESULT)r-(RESULT)l.re),-(RESULT)l.im); }	\
complex<RESULT> inline operator -(complex<T1> l, T2 r) { \
ASP_C(hcadd_count)                                      \
return complex<RESULT>(((RESULT)r-(RESULT)l.re),-(RESULT)l.im); }	\
\
complex<RESULT> inline operator +(complex<T1> r, complex<T2> l) { \
ASP_C(cadd_count) \
return complex<RESULT>((RESULT)r.re+(RESULT)l.re,(RESULT)r.im+(RESULT)l.im); } \
complex<RESULT> inline operator +(T1 r, complex<T2> l) { \
ASP_C(hcadd_count)                                      \
return(complex<RESULT>((RESULT)r+(RESULT)l.re,(RESULT)l.im)); } \
complex<RESULT> inline operator +(complex<T1> l, T2 r) { \
ASP_C(hcadd_count)                                      \
return(complex<RESULT>((RESULT)r+(RESULT)l.re,(RESULT)l.im)); } \
\
complex<RESULT> inline operator *(T1 r, complex<T2> l) { \
ASP_C(hcmult_count)                                      \
return(complex<RESULT>(r*l.re,r*l.im)); }				 \
complex<RESULT> inline operator *(complex<T1> l, T2 r) { \
ASP_C(hcmult_count)                                      \
return(complex<RESULT>(r*l.re,r*l.im)); }				 \
complex<RESULT> inline operator *(complex<T1> r, complex<T2> l) { \
ASP_C(cmult_count)                                      \
ASP_C(cadd_count)                                      \
return(complex<RESULT>(((r.re*l.re) - (r.im*l.im)), \
					   (r.re*l.im + r.im*l.re))); } \
\
complex<RESULT> inline operator /(complex<T1> l, T2 r) { \
ASP_C(hdiv_count) \
SPUC_ASSERT(r != T2(0));										\
return(complex<RESULT>((RESULT)l.re/(RESULT)r,(RESULT)l.im/(RESULT)r)); } \
complex<RESULT> inline operator /(complex<T1> r, complex<T2> l) { \
ASP_C(div_count) \
return (complex<RESULT>((r * conj(l))/((RESULT)magsq(l)))); } \
complex<RESULT> inline operator /(T1 r, complex<T2> l) { \
ASP_C(hdiv_count) \
return(complex<RESULT>((r*conj(l))/(RESULT)magsq(l))); } 

COMPLEX_SINGOP(float,float,float)
COMPLEX_SINGOP(double,double,double)
COMPLEX_SINGOP(long,long,long)
COMPLEX_SINGOP(int,int,int)

COMPLEX_SINGOP(Double,Double,double)
COMPLEX_SINGOP(Float,Float,float)
COMPLEX_SINGOP(Long,Long,long)
COMPLEX_SINGOP(Int,Int,int)

#define COMPLEX_MULTOP( T1, T2, RESULT) \
  COMPLEX_SINGOP(T1,T2,RESULT) \
  COMPLEX_SINGOP(T2,T1,RESULT) 

// Explicit mixed cases (May need to add more)

COMPLEX_MULTOP(float,long,float)
COMPLEX_MULTOP(float,int,float)
COMPLEX_MULTOP(long,int,long)

COMPLEX_MULTOP(double,long,double)
COMPLEX_MULTOP(double,int,double)
COMPLEX_MULTOP(double,float,double)

COMPLEX_MULTOP(double,Double,double)
COMPLEX_MULTOP(float,Double,double)
COMPLEX_MULTOP(long,Double,double)
COMPLEX_MULTOP(int,Double,double)

COMPLEX_MULTOP(double,Float,double)
COMPLEX_MULTOP(float,Float,float)
COMPLEX_MULTOP(long,Float,float)
COMPLEX_MULTOP(int,Float,float)

COMPLEX_MULTOP(double,Long,double)
COMPLEX_MULTOP(float,Long,double)
COMPLEX_MULTOP(long,Long,long)
COMPLEX_MULTOP(int,Long,long)

COMPLEX_MULTOP(double,Int,double)
COMPLEX_MULTOP(float,Int,float)
COMPLEX_MULTOP(long,Int,long)
COMPLEX_MULTOP(int,Int,int)

COMPLEX_MULTOP(Float,Long,float)
COMPLEX_MULTOP(Float,Int,float)
COMPLEX_MULTOP(Float,Double,double)

// Can not mix types like these......
//COMPLEX_MULTOP(int_s,vfixed,vfixed)

#ifdef COMPLEXTEMPLATES_OK
template <typename T1, typename T2> complex<typename mixed_type<T1,T2>::dtype> operator *(T1 r, complex<T2> l) {
  ASP_C(hcmult_count)										
  return(complex<typename mixed_type<T1,T2>::dtype>(r*l.re,r*l.im));
}
template <typename T1, typename T2> complex<typename mixed_type<T1,T2>::dtype> operator +(T1 r, complex<T2> l) {
  ASP_C(hcadd_count)													
	return(complex<typename mixed_type<T1,T2>::dtype>((typename mixed_type<T1,T2>::dtype)r+(typename mixed_type<T1,T2>::dtype)l.re,
											 (typename mixed_type<T1,T2>::dtype)l.im
											 ));
}
template <typename T1, typename T2> complex<typename mixed_type<T1,T2>::dtype> operator /(T1 r, complex<T2> l) {
  ASP_C(hcdiv_count)													
	return(complex<typename mixed_type<T1,T2>::dtype>((r*conj(l)/(typename mixed_type<T1,T2>::dtype)magsq(l))));
}
#endif
}
#endif
