#ifndef SPUC_SPUC_TYPEDEFS
#define SPUC_SPUC_TYPEDEFS
#ifdef USE_STD_COMPLEX
#include <complex>
using std::complex;
#endif
namespace SPUC {
// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_include
typedef long natural;

// Handle different names for 64-bit integers
#if defined(_MSC_VER) || defined(__BORLANDC__)
typedef __int64 long_long;
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
typedef builtin<float> Float;
typedef builtin<double> Double;
typedef builtin<int> Int;
typedef builtin<long> Long;

// Don't used obvious typedefs unless you want to
// put guards when PYSTE is defined
typedef complex<float> complex_f;
typedef complex<double> complex_d;
typedef complex<int> complex_i;
typedef complex<long int> complex_l;

typedef complex<builtin<float> > complex_F;
typedef complex<builtin<double> > complex_D;
typedef complex<builtin<int> > complex_I;
typedef complex<builtin<long int> > complex_L;

}  // namespace SPUC
#endif
