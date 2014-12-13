#ifndef SPUC_CFFT
#define SPUC_CFFT

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
// from directory: spuc_classes
#include <spuc/spuc_types.h>
#include <spuc/complex.h>
#include <cmath>  // for sin and cos
namespace SPUC {
//! \file
//! \brief  General Purpose C++ complex FFT Transform
//
//! \brief  General Purpose C++ complex FFT Transform
//
//! This is a general-purpose C++ complex FFT transform class.
//! it is defined as a template over a complex type. For instance,
//! if using gnu gcc, the complex type is
//!			complex<float_type>
//! And you declare the cfft class as
//!          cfft<complex<float_type>>
//!
//! The underlying CPLX type requires:
//!  CPLX()
//!  operator = , CPLX(CPLX const&)
//!	CPLX(float_type,float_type)	[used on cos/sin]
//!	CPLX operator*( CPLX , float_type )
//!  CPLX conj(CPLX const &);		[conjugate]
//!  ComPlex::operator @ (CPLX , CPLX )	[ where @ =* + - ]
//! \author Tony Kirke
//!  \ingroup classes misc
typedef complex<float_type> CPLX;
class cfft {
  int N, log2N;           //! these define size of FFT buffer
  CPLX *w;                //! array [N/2] of cos/sin values
  int *bitrev;            //! bit-reversing table, in 0..N
  float_type fscales[2];  //! f-transform scalings
  float_type iscales[2];  //! i-transform scales
  void fft_func(CPLX *buf, int iflag);

 public:
  cfft(int size,  // size is power of 2
       float_type scalef1 = 0.5,
       float_type scalef2 = 1.0,  // fwd transform scalings
       float_type scalei1 = 1.0, float_type scalei2 = 1.0  // rev xform
       );
  ~cfft();
  inline void fft(CPLX *buf)  //! perform forward fft on buffer
  {
    fft_func(buf, 0);
  }
  inline void ifft(CPLX *buf)  //! perform reverse fft on buffer
  {
    fft_func(buf, 1);
  }
  inline int length() const { return N; }
  //! used to fill in last half of complex spectrum of real signal
  //! when the first half is already there.
  void hermitian(CPLX *buf);

};  // class cfft
}  // namespace SPUC
#endif
