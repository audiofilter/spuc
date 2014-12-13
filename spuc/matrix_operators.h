#ifndef SPUC_MATRIX_OPERATORS
#define SPUC_MATRIX_OPERATORS

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
//-------------------- Templated friend functions --------------------------
template <class T>
inline matrix<T> operator+(const matrix<T> &m1, const matrix<T> &m2) {
  matrix<T> r(m1.num_rows(), m1.num_cols());
  int i, j, m1_pos = 0, m2_pos = 0, r_pos = 0;

  for (i = 0; i < r.num_cols(); i++) {
    for (j = 0; j < r.num_rows(); j++)
      r[r_pos + j] = m1[m1_pos + j] + m2[m2_pos + j];
    m1_pos += m1.num_rows();
    m2_pos += m2.num_rows();
    r_pos += r.num_rows();
  }
  return r;
}

template <class T>
inline matrix<T> operator+(const matrix<T> &m, T t) {
  matrix<T> r(m.num_rows(), m.num_cols());
  for (int i = 0; i < r.len(); i++) r[i] = m[i] + t;
  return r;
}

template <class T>
inline matrix<T> operator+(T t, const matrix<T> &m) {
  matrix<T> r(m.num_rows(), m.num_cols());
  for (int i = 0; i < r.len(); i++) r[i] = t + m[i];
  return r;
}

template <class T>
inline matrix<T> operator-(const matrix<T> &m1, const matrix<T> &m2) {
  matrix<T> r(m1.num_rows(), m1.num_cols());
  int i, j, m1_pos = 0, m2_pos = 0, r_pos = 0;

  for (i = 0; i < r.num_cols(); i++) {
    for (j = 0; j < r.num_rows(); j++)
      r[r_pos + j] = m1[m1_pos + j] - m2[m2_pos + j];
    // next column
    m1_pos += m1.num_rows();
    m2_pos += m2.num_rows();
    r_pos += r.num_rows();
  }
  return r;
}

template <class T>
inline matrix<T> operator-(const matrix<T> &m, T t) {
  matrix<T> r(m.num_rows(), m.num_cols());
  int i, j, m_pos = 0, r_pos = 0;

  for (i = 0; i < r.num_cols(); i++) {
    for (j = 0; j < r.num_rows(); j++) r[r_pos + j] = m[m_pos + j] - t;
    // next column
    m_pos += m.num_rows();
    r_pos += r.num_rows();
  }

  return r;
}

template <class T>
inline matrix<T> operator-(T t, const matrix<T> &m) {
  matrix<T> r(m.num_rows(), m.num_cols());
  int i, j, m_pos = 0, r_pos = 0;

  for (i = 0; i < r.num_cols(); i++) {
    for (j = 0; j < r.num_rows(); j++) r[r_pos + j] = t - m[m_pos + j];
    // next column
    m_pos += m.num_rows();
    r_pos += r.num_rows();
  }

  return r;
}

template <class T>
inline matrix<T> operator-(const matrix<T> &m) {
  matrix<T> r(m.num_rows(), m.num_cols());
  int i, j, m_pos = 0, r_pos = 0;

  for (i = 0; i < r.num_cols(); i++) {
    for (j = 0; j < r.num_rows(); j++) r[r_pos + j] = -m[m_pos + j];
    // next column
    m_pos += m.num_rows();
    r_pos += r.num_rows();
  }

  return r;
}

template <class T>
inline matrix<T> operator*(const matrix<T> &m1, const matrix<T> &m2) {
  matrix<T> r(m1.num_rows(), m2.num_cols());

  T tmp;
  int i, j, k;
  T *tr = r, *t1, *t2 = m2;

  for (i = 0; i < r.num_cols(); i++) {
    for (j = 0; j < r.num_rows(); j++) {
      tmp = T(0);
      t1 = m1 + j;
      for (k = m1.num_cols(); k > 0; k--) {
        tmp += *(t1) * *(t2++);
        t1 += m1.num_rows();
      }
      *(tr++) = tmp;
      t2 -= m2.num_rows();
    }
    t2 += m2.num_rows();
  }

  return r;
}

template <class T>
inline vector<T> operator*(const matrix<T> &m, const vector<T> &v) {
  vector<T> r(m.num_rows());
  int i, k, m_pos;

  for (i = 0; i < m.num_rows(); i++) {
    r(i) = T(0);
    m_pos = 0;
    for (k = 0; k < m.num_cols(); k++) {
      r(i) += m[m_pos + i] * v(k);
      m_pos += m.num_rows();
    }
  }

  return r;
}

template <class T>
inline vector<T> operator*(const vector<T> &v, const matrix<T> &m) {
  vector<T> r(m.num_cols());
  int i, k, m_pos = 0;

  for (i = 0; i < m.num_cols(); i++) {
    r(i) = T(0);
    for (k = 0; k < m.num_rows(); k++) {
      r(i) += m[m_pos + k] * v(k);
    }
    m_pos += m.num_rows();
  }

  return r;
}

template <class T>
inline matrix<T> operator*(const matrix<T> &m, T t) {
  matrix<T> r(m.num_rows(), m.num_cols());
  for (int i = 0; i < r.len(); i++) r[i] = m[i] * t;
  return r;
}

template <class T>
inline matrix<T> operator*(T t, const matrix<T> &m) {
  matrix<T> r(m.num_rows(), m.num_cols());
  for (int i = 0; i < r.len(); i++) r[i] = m[i] * t;
  return r;
}
}  // namespace
#endif
