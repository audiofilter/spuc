#ifndef SPUC_COMPLEX_IO
#define SPUC_COMPLEX_IO

// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
namespace SPUC {
//!-------------------- I/O operators---------------------------------------
// IO functions
template <class T> std::ostream& operator<<(std::ostream& os, complex<T> r) {
  return os << r.re << " " << r.im << " ";
};
template <class T> std::istream& operator>>(std::istream& os, complex<T> r) { return os >> r.re >> r.im; };
//----------------------T only----------------------------------
//! Left shift (needs override for double)
template <typename T> inline complex<T> operator<<(complex<T> r, const long shift) {
  complex<T> res = complex<T>(r.re << shift, r.im << shift);
  return (res);
}
//! Right shift (needs override for double)
template <typename T> inline complex<T> operator>>(complex<T> r, const long shift) {
  complex<T> res = complex<T>(r.re >> shift, r.im >> shift);
  return (res);
}
//--EXPLICIT
// SPECIALIZATIONS----------------------------------------------------------------
//! Left shift
template <> inline complex<double> operator<<(complex<double> r, const long shift) {
  double scale = (double)(1 << shift);
  complex<double> res(scale * r.re, scale * r.im);
  return (res);
}
//! Right shift
template <> inline complex<double> operator>>(complex<double> r, const long shift) {
  double scale = (double)1.0 / (double)(1 << shift);
  complex<double> res(scale * r.re, scale * r.im);
  return (res);
}

template <> inline complex<float> operator<<(complex<float> r, const long shift) {
  float scale = (float)(1 << shift);
  complex<float> res(scale * r.re, scale * r.im);
  return (res);
}
//! Right shift
template <> inline complex<float> operator>>(complex<float> r, const long shift) {
  float scale = 1.0f / (float)(1 << shift);
  complex<float> res(scale * r.re, scale * r.im);
  return (res);
}
}
#endif
