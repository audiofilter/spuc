#ifndef SPUC_VECTOR_CLASS
#define SPUC_VECTOR_CLASS
#include <vector>

// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
namespace SPUC {
template <class T> class vector {
 public:
  vector() { ; }
  vector(int size) { resize(size); }
  vector(const vector<T>& v) {
    resize(v.size());
    for (int i = 0; i < data.size(); i++) data[i] = v[i];
  }
  ~vector() { ; }

  inline int len() const { return data.size(); }
  inline int size() const { return data.size(); }

  inline void reset() {
    for (int i = 0; i < data.size(); i++) { data[i] = T(0); }
  }
  inline void ones() {
    for (int i = 0; i < data.size(); i++) { data[i] = T(1); }
  }

  inline T operator[](int i) const { return data[i]; }
  inline T operator()(int i) const { return data[i]; }

#ifndef PYSTE
  inline T& operator[](int i) { return data[i]; }
  inline T& operator()(int i) { return data[i]; }
  inline vector& operator+=(const vector<T>& v) {
    int i;
    if (data.size() == 0) {
      resize(v.size());
      for (i = 0; i < v.size(); i++) data[i] = v[i];
    } else {
      for (i = 0; i < data.size(); i++) data[i] += v[i];
    }
    return (*this);
  }
  inline vector& operator-=(const vector<T>& v) {
    int i;
    if (data.size() == 0) {  // if not assigned a size.
      resize(v.size());
      for (i = 0; i < v.size(); i++) data[i] = -v[i];
    } else {
      for (i = 0; i < data.size(); i++) data[i] -= v[i];
    }
    return (*this);
  }
  inline vector& operator+=(const T t) {
    for (int i = 0; i < data.size(); i++) data[i] += t;
    return *this;
  }
  inline vector& operator-=(const T t) {
    for (int i = 0; i < data.size(); i++) data[i] -= t;
    return *this;
  }
  inline vector& operator*=(const T t) {
    for (int i = 0; i < data.size(); i++) data[i] *= t;
    return *this;
  }
  inline vector& operator/=(const T t) {
    for (int i = 0; i < data.size(); i++) data[i] /= t;
    return *this;
  }
#endif
  void operator=(const T v) {
    for (int i = 0; i < data.size(); i++) data[i] = v;
  }
  void operator=(const vector<T>& v) {
    resize(v.size());
    for (int i = 0; i < data.size(); i++) data[i] = v[i];
  }

 protected:
  void resize(int siz) {
    if (data.size() == siz) return;
    if (siz == 0) return;
    data.resize(siz);
  }

  std::vector<T> data;
};

}  // namespace SPUC
#endif
