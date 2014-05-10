#ifndef SPUC_SPUC_TYPEDEFS
#define SPUC_SPUC_TYPEDEFS

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
// from directory: spuc_include
#ifdef USE_STD_COMPLEX
#include <complex>
using std::complex;
#endif
namespace SPUC {

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
// from directory: spuc_include
typedef long natural;

// Handle different names for 64-bit integers
#if defined(_MSC_VER) || defined(__BORLANDC__)
typedef __int64   long_long;
#else
typedef long long long_long;
#endif

// if defined USE_FLOAT, default to float type
#ifndef USE_FLOAT
typedef double float_type;
#else
typedef float float_type;
#endif

// Class Declarations
class bit;
template <class T> class conjr;
template <class T> class magsqr;
template <class T> class signbitr;
template <class T> class quantizer;

template <class T> class builtin;
#ifndef USE_STD_COMPLEX
template <typename T> T conj(T in);
template <class T> class complex;
#endif
template <class T> class matrix;
template <class T> class vector;

// Shortcut Typedefs
typedef builtin<float>   Float;
typedef builtin<double>  Double;
typedef builtin<int>     Int;
typedef builtin<long>    Long;

// Don't used obvious typedefs unless you want to
// put guards when PYSTE is defined
typedef complex<float>              complex_f;
typedef complex<double>             complex_d;
typedef complex<int>                complex_i;
typedef complex<long int>           complex_l;

typedef complex<builtin<float> >    complex_F;
typedef complex<builtin<double> >   complex_D;
typedef complex<builtin<int> >      complex_I;
typedef complex<builtin<long int> > complex_L;

} // namespace SPUC
#endif
