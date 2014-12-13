#ifndef SPUC_VECTOR_OPERATORS
#define SPUC_VECTOR_OPERATORS
#include <ostream>

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
namespace SPUC {
/*------------------ Inline definitions ----------------------------*/
template <class T>
inline vector<T> operator+(const vector<T> &v1, const vector<T> &v2) {
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

template <class T>
inline vector<T> operator-(const vector<T> &v1, const vector<T> &v2) {
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
template <class T>
inline vector<T> operator-(const vector<T> &v) {
  vector<T> r(v.size());
  for (int i = 0; i < v.size(); i++) r[i] = -v[i];
  return r;
}

#ifndef DOXYGEN_SHOULD_SKIP_THIS

template <class T>
inline T dot(const vector<T> &v1, const vector<T> &v2) {
  T r = T(0);
  for (int i = 0; i < v1.size(); i++) r += v1[i] * v2[i];
  return r;
}

#endif  // DOXYGEN_SHOULD_SKIP_THIS

template <class T>
inline vector<T> operator*(const vector<T> &v, const T t) {
  vector<T> r(v.size());
  for (int i = 0; i < v.size(); i++) r[i] = v[i] * t;
  return r;
}

template <class T>
inline vector<T> operator*(const T t, const vector<T> &v) {
  vector<T> r(v.size());
  for (int i = 0; i < v.size(); i++) r[i] = t * v[i];
  return r;
}

template <class T>
inline vector<T> elem_mult(const vector<T> &v1, const vector<T> &v2) {
  vector<T> r(v1.size());
  for (int i = 0; i < v1.size(); i++) r[i] = v1[i] * v2[i];
  return r;
}

// Same as element multiplication
template <class T>
inline vector<T> operator*(const vector<T> &v1, const vector<T> &v2) {
  vector<T> r(v1.size());
  for (int i = 0; i < v1.size(); i++) r[i] = v1[i] * v2[i];
  return r;
}

template <class T>
inline vector<T> operator/(const vector<T> &v, const T t) {
  vector<T> r(v.size());
  for (int i = 0; i < v.size(); i++) r[i] = v[i] / t;
  return r;
}

template <class T>
inline vector<T> operator/(const T t, const vector<T> &v) {
  vector<T> r(v.size());
  for (int i = 0; i < v.size(); i++) r[i] = t / v[i];
  return r;
}

template <class T>
inline vector<T> elem_div(const vector<T> &v1, const vector<T> &v2) {
  vector<T> r(v1.size());
  for (int i = 0; i < v1.size(); i++) r[i] = v1[i] / v2[i];
  return r;
}

template <class T>
inline vector<T> elem_div(const T t, const vector<T> &v) {
  vector<T> r(v.size());
  for (int i = 0; i < v.size(); i++) r[i] = t / v[i];
  return r;
}

template <class T>
inline vector<T> to_vector(std::vector<T> y) {
  vector<T> v(y.size());
  for (int i = 0; i < y.size(); i++) v[i] = y[i];
  return (v);
}

template <class T>
inline void copy_vector(std::vector<T> x, std::vector<T> y) {
  // maybe use memcpy?????
  // memcpy(y, x, (unsigned int)n*sizeof(T));
  for (int i = 0; i < y.size(); i++) y[i] = x[i];
}

template <class T>
std::ostream &operator<<(std::ostream &os, const vector<T> &v);

}  // namespace
#endif
