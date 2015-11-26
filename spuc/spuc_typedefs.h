#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_include
#ifndef USE_SPUC_COMPLEX
#include <complex>
using std::complex;
#endif
namespace SPUC {
// Copyright (c) 1993-2007 Tony Kirke
// from directory: spuc_include
typedef long natural;

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
