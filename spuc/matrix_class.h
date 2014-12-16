#ifndef SPUC_MATRIX_CLASS
#define SPUC_MATRIX_CLASS
#include <spuc/vector.h>

// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
namespace SPUC {
template <class T> class matrix {
 public:
  matrix() { datasize = rows = cols = 0; }
  matrix(int inrow, int incol) { resize(inrow, incol); }
  matrix(const matrix<T>& m) {
    resize(m.rows, m.cols);
    for (int i = 0; i < data.size(); i++) data[i] = m.data[i];
  }
  ~matrix() { ; }
  int num_cols() const { return cols; }
  int num_rows() const { return rows; }
  int size() const { return datasize; }
  int len() const { return datasize; }
  void reset() {
    for (int i = 0; i < datasize; i++) data[i] = T(0);
  }
  inline T operator()(int R, int C) const { return data[R + C * rows]; }
  inline T operator()(int index) const { return data[index]; }
  inline T operator[](int index) const { return data[index]; }

#ifndef PYSTE
  inline T& operator()(int R, int C) { return data[R + C * rows]; }
  inline T& operator()(int index) { return data[index]; }
  inline T& operator[](int index) { return data[index]; }
#endif

  void operator=(T t) {
    for (int i = 0; i < datasize; i++) data[i] = t;
  }
  void operator=(const matrix<T>& m) {
    resize(m.rows, m.cols);
    if (m.datasize == 0) return;
    for (int i = 0; i < data.size(); i++) data[i] = m.data[i];
  }
  void operator=(const vector<T>& v) {
    resize(v.size(), 1);
    for (int i = 0; i < data.size(); i++) data[i] = v[i];
  }

  /*
  void operator+=(const matrix<T> &m);
  void operator+=(T t);
  void operator-=(const matrix<T> &m);
  void operator-=(T t);
  void operator*=(const matrix<T> &m);
  void operator*=(T t);
  */
 protected:
  void resize(int r, int c) {
    if (datasize == r * c) {
      rows = r;
      cols = c;
      return;
    }
    if (r == 0 || c == 0) return;
    datasize = r * c;
    data.resize(datasize);
    rows = r;
    cols = c;
  }

  int datasize, rows, cols;
  std::vector<T> data;
};

//-------------------- Templated friend functions --------------------------
/*
template<class T> inline void matrix<T>::operator+=(const matrix<T> &m)
{
  if (datasize == 0)
    operator=(m);
  else {
    int i, j, m_pos=0, pos=0;
    for (i=0; i<cols; i++) {
      for (j=0; j<rows; j++)
        data[pos+j] += m.data[m_pos+j];
      pos += rows;
      m_pos += m.rows;
    }
  }
}


template<class T> inline void matrix<T>::operator+=(T t)
{
    for (int i=0; i<datasize; i++)
      data[i] += t;
}

template<class T> inline void matrix<T>::operator-=(const matrix<T> &m)
{
    int i,j, m_pos=0, pos=0;

    if (datasize == 0) {
        resize(m.rows, m.cols);
        for (i=0; i<cols; i++) {
            for (j=0; j<rows; j++)
                data[pos+j] = -m.data[m_pos+j];
            m_pos += m.rows;
            pos += rows;
        }
    } else {
        for (i=0; i<cols; i++) {
            for (j=0; j<rows; j++)
                data[pos+j] -= m.data[m_pos+j];
            m_pos += m.rows;
            pos += rows;
        }
    }
}
template<class T> inline void matrix<T>::operator-=(T t)
{
  for (int i=0; i<datasize; i++)
    data[i] -= t;
}

template<class T> inline void matrix<T>::operator*=(const matrix<T> &m)
{
    matrix<T> r(rows, m.cols);

    T tmp;

    int i,j,k, r_pos=0, pos=0, m_pos=0;

    for (i=0; i<r.cols; i++) {
        for (j=0; j<r.rows; j++) {
            tmp = T(0);
            pos = 0;
            for (k=0; k<cols; k++) {
                tmp += data[pos+j] * m.data[m_pos+k];
                pos += rows;
            }
            r.data[r_pos+j] = tmp;
        }
        r_pos += r.rows;
        m_pos += m.rows;
    }
    operator=(r);
}

template<class T> inline void matrix<T>::operator*=(T t)
{
  for (int i=0; i<datasize; i++)
    data[i] *= t;
}
*/
}  // end namespace
#endif
