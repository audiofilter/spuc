
// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_src
#include <spuc/spuc_defines.h>
#include <spuc/complex.h>
#include <spuc/spuc_math.h>
#include <spuc/iir_coeff.h>
#include <spuc/fliplr.h>
#include <spuc/convolve.h>
#include <spuc/partial_convolve.h>
#include <spuc/find_roots.h>
#include <iostream>
#include <spuc/qnoise.h>
namespace SPUC {
iir_coeff::iir_coeff(long ord) : poles((ord + 1) / 2), zeros((ord + 1) / 2), a_tf(ord + 1), b_tf(ord + 1) {
  // amax - attenuation at cutoff
  order = ord;
  n2 = (order + 1) / 2;
  odd = (order % 2);
  for (int j = 0; j < n2; j++) {
    poles[j] = complex<float_type>(0.0, 0.0);
    zeros[j] = complex<float_type>(0.0, 0.0);
  }
  state = 0;  // un-initialized
  tf_state = 0;
  ap_state = 0;
}
//! Destructor
iir_coeff::~iir_coeff() {}
// bilinear
void iir_coeff::bilinear() {
  for (int j = 0; j < n2; j++) {
    zeros[j] = ((float_type)1.0 - zeros[j]) / ((float_type)1.0 + zeros[j]);
    poles[j] = ((float_type)1.0 - poles[j]) / ((float_type)1.0 + poles[j]);
  }
  state = 2;  // in Z-domain now!
}
void iir_coeff::convert_to_ab() {
  gain = (float_type)1.0;
  hpf_gain = gain;
  z_root_to_ab(zeros);
  // if (odd) std::cout << "Zero = " << zeros[0] << "\n";
  if (odd) gain *= 0.5 * (1.0 - real(zeros[0]));

  gain = (float_type)1.0 / gain;
  hpf_gain = (float_type)1.0 / hpf_gain;

  z_root_to_ab(poles);

  if (odd) gain *= 0.5 * (1.0 - real(poles[0]));
  // if (odd) std::cout << "odd z[0] = " << poles[0] << " gain = " << gain <<
  // "\n";

  //  std::cout << "Calc gain = " << gain << "\n";
  //  gain = 1.0;
  state = 3;  // in Z-domain 2nd order A/B coefficients
  a_tf = p2_to_poly(poles);
  b_tf = p2_to_poly(zeros);
}
void iir_coeff::ab_to_tf() {
  a_tf = p2_to_poly(poles);
  b_tf = p2_to_poly(zeros);
  state = 3;  // in Z-domain 2nd order A/B coefficients
}
void iir_coeff::z_root_to_ab(std::vector<complex<float_type> >& z) {
  // if (odd) z[0] = complex<float_type>((float_type)1.0/real(z[0]),0.0);
  for (int j = odd; j < n2; j++) {
    gain *= (magsq(z[j]) - 2 * real(z[j]) + 1.0);
    hpf_gain *= (magsq(z[j]) + 2 * real(z[j]) + 1.0);
    z[j] = complex<float_type>(-2 * real(z[j]), magsq(z[j]));
  }
  state = 3;  // in Z-domain 2nd order A/B coefficients
}
// Takes poles or zeros and creates a polynomial transfer function
std::vector<float_type> iir_coeff::pz_to_poly(const std::vector<complex<float_type> >& z) {
  std::vector<float_type> p2(3);
  std::vector<float_type> p(order + 1);
  std::vector<float_type> tf(order + 1);
  float_type td;

  p[0] = 1;
  p2[0] = 1;
  long m = 1;

  for (int j = 0; j < n2; j++) {
    td = 1 - 2 * real(z[j]) + magsq(z[j]);
    p2[1] = (1 - magsq(z[j])) / td;
    p2[2] = 2.0 * imag(z[j]) / td;
    tf = partial_convolve(p, p2, m, 3);
    m += 2;
    for (int i = 0; i < m; i++) p[i] = tf[i];
  }
  tf_state = 1;
  return (tf);
}
// Takes 'n' 2nd order polynomials of the form 1+a*z + b*z^2
// where a and b are packed into a complex float_type as
// complex<float_type>(a,b)
// and convolves them all together as 1 polynomial
std::vector<float_type> iir_coeff::p2_to_poly(const std::vector<complex<float_type> >& ab) {
  std::vector<float_type> tf;
  std::vector<float_type> p2(3);
  std::vector<float_type> p(order + 1);

  p[0] = 1;
  p2[0] = 1;
  long m = 1;
  if (odd) {
    p2[1] = -real(ab[0]);
    p2[2] = 0;
    tf = partial_convolve(p, p2, m, 2);
    m += 1;
    for (int i = 0; i < m; i++) p[i] = tf[i];
  }
  for (int j = odd; j < n2; j++) {
    p2[1] = real(ab[j]);
    p2[2] = imag(ab[j]);
    tf = partial_convolve(p, p2, m, 3);
    m += 2;
    for (int i = 0; i < m; i++) { p[i] = tf[i]; }
  }
  return tf;
}
float_type iir_coeff::get_a(long i) {
  if (i < order + 1) { return (a_tf[i]); } else {
    return (0);
  }
}
float_type iir_coeff::get_coeff_a(long i) {
  if (i < order) {
    if (i % 2 == 0)
      return (real(poles[i / 2]));
    else
      return (imag(poles[i / 2]));
  } else { return (0); }
}
float_type iir_coeff::get_coeff_b(long i) {
  if (i < order) {
    if (i % 2 == 0)
      return (real(zeros[i / 2]));
    else
      return (imag(zeros[i / 2]));
  } else { return (0); }
}
float_type iir_coeff::get_b(long i) {
  if (i < order + 1) { return (b_tf[i]); } else {
    return (0);
  }
}
complex<float_type> iir_coeff::get_root(long i) {
  if (i <= n2)
    return (poles[i]);
  else
    return (complex<float_type>(0.0, 0.0));
}
complex<float_type> iir_coeff::get_zero(long i) {
  if (i <= n2)
    return (zeros[i]);
  else
    return (complex<float_type>(0.0, 0.0));
}
void iir_coeff::pz_to_ap() {
  int m = 2 * order - 1;
  typedef std::vector<float_type> Array;
  typedef std::vector<complex<float_type> > CArray;
  Array fa;
  Array d2(m);
  Array p2(m);
  Array r(m);
  Array q(m);
  CArray rq;
  CArray h1(m);
  CArray h2(m);
  float_type divtmp;
  float_type tmp;
  int np, nq;
  int i, j;

  // Convert from poles and zeros to 2nd order section coefficients
  //  root_to_ab(zeros);
  //  root_to_ab(poles);

  // Get overall A and B transfer functions
  //  p2_to_poly(zeros, b_tf, n2);
  //  p2_to_poly(poles, a_tf, n2);

  // Convert from poles and zeros to polynomial transfer functions
  b_tf = pz_to_poly(zeros);
  a_tf = pz_to_poly(poles);

  // Now start real work
  p2 = convolve(b_tf, b_tf);
  fa = fliplr(a_tf);
  d2 = convolve(fa, a_tf);

  // B*B - A*fliplr(A)
  for (j = 0; j < m; j++) { r[j] = p2[j] - d2[j]; }

  // Appendix IEEE assp-34, no 2, april 1986, page 360
  q[0] = sqrt(r[0]);
  q[1] = r[1] / (2 * q[0]);

  divtmp = 0.5 / q[0];
  for (j = 2; j < m; j++) {
    for (tmp = 0, i = 2; i < j; i++) tmp += q[i] * q[j - i];
    q[j] = (r[j] - tmp) * divtmp;
  }

  for (j = 0; j < m; j++) q[j] += b_tf[j];

  rq = find_roots(q, m);

  np = nq = 0;
  for (j = 0; j < m; j++) {
    if (magsq(rq[j]) >= (float_type)1.0) { h1[nq++] = rq[j]; } else {
      h2[np++] = rq[j];
    }
  }
  // We now roots for H1 sections in h1 and
  //              for H2 sections in h2 and

  // We convert from each root pair to an allpass section
  // with coefficients

  // Save these coefficients for transfer to IIR implemented as
  // allpass sections

  ap_state = 1;
  state = 4;
}
float_type iir_coeff::max_abs_coeff() {
  float_type maxv = 0;
  for (int j = 0; j < n2; j++) {
    if (ABS(real(poles[j])) > maxv) maxv = ABS(real(poles[j]));
    if (ABS(imag(poles[j])) > maxv) maxv = ABS(imag(poles[j]));
    if (ABS(real(zeros[j])) > maxv) maxv = ABS(real(zeros[j]));
    if (ABS(imag(zeros[j])) > maxv) maxv = ABS(imag(zeros[j]));
  }
  return (maxv);
}
void iir_coeff::quantize(int bits) {
  char int_bits = (char)ceil(log(max_abs_coeff()) / log(2.0));
  bits -= int_bits;
  qnoise<complex<float_type> > Quantize((char)bits);
  if (bits > 0) {
    for (int j = 0; j < n2; j++) {
      poles[j] = Quantize(poles[j]);
      zeros[j] = Quantize(zeros[j]);
    }
  }
  // Re-calculate TF
  ab_to_tf();
}
// Get frequency response at freq
float_type iir_coeff::freqz_mag(float_type freq) {
  int i;
  complex<float_type> z(1, 0);
  complex<float_type> z_inc = complex<float_type>(cos(freq), sin(freq));
  complex<float_type> nom(0);
  complex<float_type> den(0);
  for (i = 0; i < order + 1; i++) {
    nom += z * b_tf[i];
    den += z * a_tf[i];
    z *= z_inc;
  }
  return sqrt(magsq(nom / den));
}
}  // namespace SPUC
