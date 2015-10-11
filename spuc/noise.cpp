// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_src
#include <cmath>
#include <spuc/complex.h>
#include "noise.h"
#define M 714025
#define IA 1366
#define IC 150889
#define LM 2147483647
#define LAM (1.0 / LM)
#define LA 16807
#define LR 2836
#define LQ 127773
namespace SPUC {
// Gaussian noise routine
// Can create (double) gaussian white noise
//            complex<double> gaussian white noise
//        or  (double) uniform noise
noise::noise(float_type i) : s(0), idum((long)i) { ; }  // Constructor
complex<float_type> noise::Cgauss(void) {
  float_type fac, r, v1, v2;
  do {
    v1 = (2.0 * uniform()) - 1.0;
    v2 = (2.0 * uniform()) - 1.0;
    r = (v1 * v1) + (v2 * v2);
  } while (r >= 1.0);
  fac = sqrt(-2.0 * log(r) / r);
  return (complex<float_type>(v2 * fac, v1 * fac));
}
float_type noise::gauss() {
  float_type fac, r, v1, v2;

  if (s == 0) {
    do {
      v1 = (2.0 * uni()) - 1.0;
      v2 = (2.0 * uni()) - 1.0;
      r = (v1 * v1) + (v2 * v2);
    } while (r >= 1.0);
    fac = sqrt(-2.0 * log(r) / r);
    x = v1 * fac;
    s = 1;
    return (v2 * fac);
  } else {
    s = 0;
    return (x);
  }
}
float_type noise::uni(void)
//--------------------------------------------------------------------
//       Returns uniform deviate between 0.0 and 1.0.
//       Used to generate PN data
//---------------------------------------------------------------------

{
  double rm, r1;
  rm = 1. / M;
  idum = (long)fmod((double)(IA * idum + IC), (double)M);
  r1 = idum * rm;
  return ((float_type)r1);
}
float_type noise::uniform(void)
//--------------------------------------------------------------------
//       Returns uniform deviate between 0.0 and 1.0.
//       Used to generate PN data
//---------------------------------------------------------------------

{
  double r1;
  long hi;
  hi = idum / LQ;
  idum = LA * (idum - hi * LQ) - LR * hi;
  if (idum < 0) idum += LM;
  r1 = LAM * idum;
  return ((float_type)r1);
}
}  // namespace SPUC
