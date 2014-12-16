#ifndef SPUC_VECTOR_OPERATORS
#define SPUC_VECTOR_OPERATORS
#include <ostream>

// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
namespace SPUC {
/*------------------ Inline definitions ----------------------------*/
template <class T> inline vector<T> operator+(const vector<T> &v1, const vector<T> &v2) {
  vector<T> r(v1.size());
  for (int i = 0; i < v1.size(); i++) r[i] = v1[i] + v2[i];
  return r;
}
/*
template<class T> inline vector<T> operator+( vector<T> &v, T t)
{
  vector<T> r(v.size());
  for (int i=0; i<v.size(); i++)	r[i] = v[i] + t;
  return r;
}

template<class T> inline vector<T> operator+(T t,  vector<T> &v)
{
  vector<T> r(v.size());
  for (int i=0; i<v.size(); i++)	r[i] = t + v[i];
  return r;
}
*/

template <class T> inline vector<T> operator-(const vector<T> &v1, const vector<T> &v2) {
  vector<T> r(v1.size());
  for (int i = 0; i < v1.size(); i++) r[i] = v1[i] - v2[i];
  return r;
}
/*
template<class T> inline vector<T> operator-( vector<T> &v, T t)
{
  vector<T> r(v.size());
  for (int i=0; i<v.size(); i++)	r[i] = v[i] - t;
  return r;
}

template<class T> inline vector<T> operator-(T t,  vector<T> &v)
{
  vector<T> r(v.size());
  for (int i=0; i<v.size(); i++)	r[i] = t - v[i];
  return r;
}
*/
template <class T> inline vector<T> operator-(const vector<T> &v) {
  vector<T> r(v.size());
  for (int i = 0; i < v.size(); i++) r[i] = -v[i];
  return r;
}

#ifndef DOXYGEN_SHOULD_SKIP_THIS

template <class T> inline T dot(const vector<T> &v1, const vector<T> &v2) {
  T r = T(0);
  for (int i = 0; i < v1.size(); i++) r += v1[i] * v2[i];
  return r;
}

#endif  // DOXYGEN_SHOULD_SKIP_THIS

template <class T> inline vector<T> operator*(const vector<T> &v, const T t) {
  vector<T> r(v.size());
  for (int i = 0; i < v.size(); i++) r[i] = v[i] * t;
  return r;
}

template <class T> inline vector<T> operator*(const T t, const vector<T> &v) {
  vector<T> r(v.size());
  for (int i = 0; i < v.size(); i++) r[i] = t * v[i];
  return r;
}

template <class T> inline vector<T> elem_mult(const vector<T> &v1, const vector<T> &v2) {
  vector<T> r(v1.size());
  for (int i = 0; i < v1.size(); i++) r[i] = v1[i] * v2[i];
  return r;
}

// Same as element multiplication
template <class T> inline vector<T> operator*(const vector<T> &v1, const vector<T> &v2) {
  vector<T> r(v1.size());
  for (int i = 0; i < v1.size(); i++) r[i] = v1[i] * v2[i];
  return r;
}

template <class T> inline vector<T> operator/(const vector<T> &v, const T t) {
  vector<T> r(v.size());
  for (int i = 0; i < v.size(); i++) r[i] = v[i] / t;
  return r;
}

template <class T> inline vector<T> operator/(const T t, const vector<T> &v) {
  vector<T> r(v.size());
  for (int i = 0; i < v.size(); i++) r[i] = t / v[i];
  return r;
}

template <class T> inline vector<T> elem_div(const vector<T> &v1, const vector<T> &v2) {
  vector<T> r(v1.size());
  for (int i = 0; i < v1.size(); i++) r[i] = v1[i] / v2[i];
  return r;
}

template <class T> inline vector<T> elem_div(const T t, const vector<T> &v) {
  vector<T> r(v.size());
  for (int i = 0; i < v.size(); i++) r[i] = t / v[i];
  return r;
}

template <class T> inline vector<T> to_vector(std::vector<T> y) {
  vector<T> v(y.size());
  for (int i = 0; i < y.size(); i++) v[i] = y[i];
  return (v);
}

template <class T> inline void copy_vector(std::vector<T> x, std::vector<T> y) {
  // maybe use memcpy?????
  // memcpy(y, x, (unsigned int)n*sizeof(T));
  for (int i = 0; i < y.size(); i++) y[i] = x[i];
}

template <class T> std::ostream &operator<<(std::ostream &os, const vector<T> &v);

}  // namespace
#endif
