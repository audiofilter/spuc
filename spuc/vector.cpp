
// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_vector
#include <iostream>
#include <spuc/vector.h>
namespace SPUC {
template <class T> std::ostream &operator<<(std::ostream &os, const vector<T> &v) {
  int sz = v.len();
  os << "[";
  for (int i = 0; i < sz; i++) {
    os << v(i);
    if (i < sz - 1) os << " ";
  }
  os << "]";

  return os;
}
}  // namespace SPUC
