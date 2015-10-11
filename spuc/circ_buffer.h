#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_templates
#include <spuc/spuc_types.h>
#include <vector>
namespace SPUC {
//! \file
//! \brief Circular Buffer
//
//! \brief Circular Buffer
//
//!  \author Tony Kirke,  Copyright(c) 2001
//! \author Tony Kirke
//! \ingroup templates misc
template <class T> class circ_buffer {
 protected:
  std::vector<T> buf;
  int len;
  int ptr;

 public:
  circ_buffer(void) : len(0), ptr(0) { ; }
  circ_buffer(const circ_buffer<T>& A);
  circ_buffer(int d);
  circ_buffer(int d, T init_value);
  ~circ_buffer(void) {}
  int size(void) const { return len; }
  void set_size(int l) {
    len = l + 1;
    buf.resize(len);
    reset();
  }
  T operator[](int i) const { return buf[(ptr + i) % (len)]; }
  circ_buffer<T> operator=(circ_buffer<T>& A);
  void put(T data_in) {
    buf[ptr] = data_in;
    ptr = (ptr + 1) % len;
  }
  void input(T d) {
    buf[ptr] = d;
    ptr = (ptr + 1) % (len);
  }
  void reset() {
    for (int i = 0; i < len; i++) buf[i] = 0;
    ptr = 0;
  }
  T last() { return (buf[ptr]); }
  T check(int l) { return (buf[(ptr + len - l - 1) % len]); }
};

template <class T> circ_buffer<T>::circ_buffer(const circ_buffer<T>& A) : buf(A.len) {
  len = A.len;
  ptr = A.ptr;
  for (int i = 0; i < len; i++) buf[i] = A.buf[i];
}
// copy constructor
template <class T> circ_buffer<T>::circ_buffer(int len1) : buf(len1) {
  len = len1;
  ptr = len - 1;
}

template <class T> circ_buffer<T>::circ_buffer(int len1, T init_value) : buf(len1) {
  len = len1;
  ptr = len - 1;
  for (int i = 0; i < len; i++) buf[i] = init_value;
}

template <class T> circ_buffer<T> circ_buffer<T>::operator=(circ_buffer<T>& A) {
  if (this->len != A.size()) {
    // create room for A
    len = A.size();
    buf.resize(len);
  }
  ptr = A.ptr;

  for (int i = 0; i < len; i++) buf[i] = A.buf[i];
  return *this;
}
}  // namespace SPUC
