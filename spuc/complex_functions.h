#ifndef SPUC_COMPLEX_FUNCTIONS
#define SPUC_COMPLEX_FUNCTIONS

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
//----------------------Various Complex functions----------------------------------
//! Complex value (0,1) 
template <typename T> inline complex<T> complexj(void) {  return(complex<T>(0,1));}
//! Conjugate
template <typename T> inline complex<T> conjugate(complex<T> x)
{
  complex<T> y;
  y.re = x.re;
  y.im = -x.im;
  return y;
}
//! Magnitude Squared of complex vector (also norm)
template <typename T> inline T magnitude_squared(complex<T> x)
{
  ASP_C(hcmult_count)
  ASP_C(hcadd_count)
  return(magsqr<complex<T> >::magsqd(x));
}
//! Magnitude Squared of complex vector (also magnitude_squared)
template <typename T> inline T norm(complex<T> x)
{
  ASP_C(hcmult_count)
  ASP_C(hcadd_count)
  return(magsqr<complex<T> >::magsqd(x));
}
//! Normalized vector (magnitude = 1)
template <typename T> inline complex<double> normalized(complex<T> x)
{
  T y;
  y = ::sqrt(x.re*x.re + x.im*x.im);
  return (complex<double>(x.re/y,x.im/y));
}
//! only get real part of result
template <typename T> inline complex<T> real_mult(complex<T> r, complex<T> l)
{
  ASP_C(hcmult_count)
  ASP_C(hcadd_count)
  complex<T> z;
  z.re = ((r.re*l.re) - (r.im*l.im));
  z.im = 0;
  return (z);
}
//! only get product of real parts
template <typename T> inline complex<T> reals_only_mult(complex<T> r, complex<T> l)
{
  ASP_C(rmult_count)
  complex<T> z;
  z.re = (r.re*l.re);
  z.im = 0;
  return (z);
}
//! Approximate magnitude function
template <typename T> inline T approx_mag(complex<T> x)
{
  T xa = ABS(x.re);
  T ya = ABS(x.im);
  return(MAX(xa,ya) + MIN(xa,ya)/4);
}
//! Type Specific functions

//! Return phase angle (radians) of complex number
#ifndef USE_STD_COMPLEX
template <typename T> inline double arg(const complex<T> x)
{
  double TMPANG;
  if (real(x) == (T)0) {
	if (imag(x) < (T)0) return(3.0*PI/2.0);
	else return(PI/2.0);
  } else {
	TMPANG=atan((double)imag(x)/(double)real(x));
	if (real(x) < (T)0) TMPANG -= PI;
	if (TMPANG < 0) TMPANG += TWOPI;
  }
  return(TMPANG);
}
#endif
template <typename T> inline double calc_angle(const complex<T> x)
{
  double TMPANG;
  if (real(x) == (T)0) {
	if (imag(x) < (T)0) return(3.0*PI/2.0);
	else return(PI/2.0);
  } else {
	TMPANG=atan((double)imag(x)/(double)real(x));
	if (real(x) < (T)0) TMPANG -= PI;
	if (TMPANG < 0) TMPANG += TWOPI;
  }
  return(TMPANG);
}
//! Convert to complex<double>
template <typename T> inline complex<double> rational(complex<T> l) {
  return(complex<double>((double)l.re,(double)l.im));
}
template <typename T> inline complex<double> reciprocal(complex<T> x)
{
  T y = (x.re*x.re + x.im*x.im);
  return (complex<double>(x.re/y,-x.im/y));
}
}
#endif
