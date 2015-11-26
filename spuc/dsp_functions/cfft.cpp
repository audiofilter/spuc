// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_src
#include <spuc/dsp_functions/cfft.h>
namespace SPUC {
//!  \brief  General Purpose C++ complex FFT Transform
//!  \ingroup misc
//////////////////////////////  cfft methods //////////////////////////////
/*
 * constructor takes an int, power-of-2.
 * scalef1,scalef2, are the post-pass and post-transform
 * scalings for the forward transform; scalei1 and scalei2 are
 * the same for the inverse transform.
 */
cfft::cfft(int size, float_type scalef1, float_type scalef2, float_type scalei1, float_type scalei2) {
  int i, j, k;
  float_type t;

  fscales[0] = scalef1;
  fscales[1] = scalef2;
  iscales[0] = scalei1;
  iscales[1] = scalei2;

  for (k = 0;; ++k) {
    if ((1 << k) == size) break;
    if (k == 18 || (1 << k) > size) throw "cfft: size not power of 2";
  }
  N = 1 << k;
  log2N = k;

  bitrev = new int[N];

  if (k > 0)
    w = new CPLX[N >> 1];
  else
    w = NULL;
  if (bitrev == NULL || ((k > 0) && w == NULL)) throw "cfft: out of memory";

  //
  // do bit-rev table
  //
  bitrev[0] = 0;

  for (j = 1; j < N; j <<= 1) {
    for (i = 0; i < j; ++i) {
      bitrev[i] <<= 1;
      bitrev[i + j] = bitrev[i] + 1;
    }
  }
  //
  // prepare the cos/sin table. This is bit-reversed, and goes
  // like this: 0, 90, 45, 135, 22.5 ...  for N/2 entries.
  //
  if (k > 0) {
    CPLX ww;
    k = (1 << (k - 1));
    for (i = 0; i < k; ++i) {
      t = float_type(bitrev[i << 1]) * PI / float_type(k);
      ww = CPLX(cos(t), sin(t));
      w[i] = conj(ww);  // force limiting of imag part if applic.
      // cout << w[i] << "\n";
    }
  }
}
/*
 * destructor frees the memory
 */
cfft::~cfft() {
  delete[] bitrev;
  if (w != NULL) delete[] w;
}
/*
 * hermitian() assumes the array has been filled in with values
 * up to the center and including the center point. It reflects these
 * conjugate-wise into the last half.
 */
void cfft::hermitian(CPLX *buf) {
  int i, j;
  if (N <= 2) return;  // nothing to do
  i = (N >> 1) - 1;    // input
  j = i + 2;           // output
  while (i > 0) {
    buf[j] = conj(buf[i]);
    --i;
    ++j;
  }
}
/*
 * cfft::fft_func(buf,0) performs a forward fft on the data in the buffer specified.
 * cfft::fft_func(buf,1) performs an inverse fft on the data in the buffer specified.
 */
void cfft::fft_func(CPLX *buf, int iflag) {
  int i, j, k;
  CPLX *buf0, *buf2, *bufe;
  CPLX z1, z2, zw;
  float_type *sp, s;

  sp = iflag ? iscales : fscales;
  s = sp[0];  // per-pass scale

  if (log2N == 0) {  // only 1 element !
    s = sp[1];
    buf[0] = buf[0] * s;  // final scale only
    return;
  }
  //
  // first pass:
  //  1st element  = sum of 1st & middle, middle element = diff.
  // repeat N/2 times.

  k = N >> 1;

  if (log2N == 1) s *= sp[1];  // final scale

  buf2 = buf + k;
  for (i = 0; i < k; ++i) {  // first pass is faster
    z1 = buf[i] + buf2[i];
    z2 = buf[i] - buf2[i];
    buf[i] = z1 * s;
    buf2[i] = z2 * s;
  }
  if (log2N == 1) return;  // only 2!

  k >>= 1;         // k is N/4 now
  bufe = buf + N;  // past end
  for (; k; k >>= 1) {
    if (k == 1) {  // last pass - include final scale
      s *= sp[1];  // final scale
    }
    buf0 = buf;
    for (j = 0; buf0 < bufe; ++j) {
      if (iflag) {
        zw = conj(w[j]);
      } else {
        zw = w[j]; /* get w-factor */
      }
      buf2 = buf0 + k;
      for (i = 0; i < k; ++i) {  // a butterfly
        z1 = zw * buf2[i];
        z2 = buf0[i] + z1;
        buf2[i] = (buf0[i] - z1) * s;
        buf0[i] = z2 * s;
      }
      buf0 += (k << 1);
    }
  }
  // bitrev the sucker
  for (i = 0; i < N; ++i) {
    j = bitrev[i];
    if (i <= j) continue;  // don't do these
    z1 = buf[i];
    buf[i] = buf[j];
    buf[j] = z1;
  }
}
}  // namespace SPUC
