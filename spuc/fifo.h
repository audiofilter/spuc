#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_templates
#include <spuc/spuc_types.h>
#include <vector>
namespace SPUC {
//! \file
//! \author Tony Kirke,  Copyright(c) 2014
//! \author Tony Kirke
//! \ingroup templates templates templates misc
template <class T> class fifo {
 protected:
  std::vector<T> buf;
  int len;
  int w_ptr;
  int r_ptr;
  int fill_size;

 public:
  fifo(void) : len(0), w_ptr(0), r_ptr(0) { ; }
  // copy constructor
  fifo(int len1) : buf(len1) {
    len = len1;
    reset();
  }
  void set_size(int len1) {
    len = len1;
    buf.resize(len);
    reset();
  }
  ~fifo(void) {}
  int size(void) const { return len; }
  void reset() {
    w_ptr = 0;
    r_ptr = 0;
    fill_size = 0;
  }
  T operator[](int i) const { return buf[(r_ptr + i) % len]; }
  void write(T data_in) {
    buf[w_ptr] = data_in;
    w_ptr = (w_ptr + 1) % len;
    fill_size++;
    if (fill_size > len) { std::cout << "FIFO overflow \n"; }
  }
  T read() {
    T ret = buf[r_ptr];
    r_ptr = (r_ptr + 1) % len;
    fill_size--;
    if (fill_size < 0) { std::cout << "FIFO underflow \n"; }
    return (ret);
  }
  bool half_empty() {
    int d = fill_amount();
    if (d <= len / 2)
      return true;
    else
      return false;
  }
  bool half_full() {
    int d = fill_amount();
    if (d >= len / 2)
      return true;
    else
      return false;
  }

  int fill_amount() { return (fill_size); }
};
}  // namespace SPUC
