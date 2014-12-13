#ifndef SPUC_COMPLEX
#define SPUC_COMPLEX
#include <iostream>
#include <spuc/spuc_defines.h>
#include <cmath>
#include <spuc/conj.h>
#include <spuc/signbit.h>
#include <spuc/magsq.h>
#include <spuc/builtin.h>
#ifdef COUNTOPS
#define ASP_C(x) \
  extern long x; \
  x++;
#else
#define ASP_C(x)
#endif
#ifdef USE_STD_COMPLEX
#include <complex>
using std::complex;
#else
#include <spuc/complex_class.h>
#endif
#include <spuc/complex_functions.h>
#ifndef PYSTE
#ifndef USE_STD_COMPLEX
#include <spuc/complex_io.h>
#include <spuc/complex_operators.h>
#endif
#endif
#endif
