// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_src
#include <cstdlib>
#include "misc.h"
namespace SPUC {
// Exclusive or the bits in x together.
// N is the number of bits in x.
bool reduce(long x, long n) {
  bool c = 0;
  for (int i = 0; i < n; i++) {
    c ^= (x & 0x01);
    x >>= 1;
  }
  return (c);
}
float_type erfc1(float_type x) {
  const float_type a1 = 0.254829592;
  const float_type a2 = -0.284496736;
  const float_type a3 = 1.421413741;
  const float_type a4 = -1.453152027;
  const float_type a5 = 1.0601405429;
  const float_type p = .3275911;
  float_type t, rf;
  t = 1. / (1. + p * x);
  rf = (a1 * t + a2 * t * t + a3 * t * t * t + a4 * t * t * t * t + a5 * t * t * t * t * t) * exp(-x * x);
  return (rf);
}
float_type erf1(float_type x) { return (1 - erfc1(x)); }
/* +++Date last modified: 05-Jul-1997 */
/*
** quicksort.c -- quicksort integer array
** public domain by Raymond Gardner     12/91
*/
void swap(int *a, int *b) {
  int t;
  t = *a;
  *a = *b;
  *b = t;
}

void quicksort(int *v, unsigned n) {
  unsigned i, j, ln, rn;
  while (n > 1) {
    swap(&v[0], &v[n / 2]);
    for (i = 0, j = n;;) {
      do
        --j;
      while (v[j] > v[0]);
      do
        ++i;
      while (i < j && v[i] < v[0]);
      if (i >= j) break;
      swap(&v[i], &v[j]);
    }
    swap(&v[j], &v[0]);
    ln = j;
    rn = n - ++j;
    if (ln < rn) {
      quicksort(v, ln);
      v += j;
      n = rn;
    } else {
      quicksort(v + j, rn);
      n = ln;
    }
  }
}
// void audi(unsigned char* w, long nf){for (int i=0;i<nf;i++) w[i] = w[i] >> 2;}
}  // namespace SPUC
