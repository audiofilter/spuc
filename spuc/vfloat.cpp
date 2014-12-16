
// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_types
#include <spuc/vfloat.h>
namespace SPUC {
typedef vfloat self;
// IO functions
std::ostream& operator<<(std::ostream& os, const self& r) {
  os << (double)r;
  return (os);
}
std::istream& operator>>(std::istream& is, self r) {
  double x;
  is >> x;
  r = x;
  return (is);
}
vfloat operator<<(vfloat r, const natural shift) {
  vfloat x = r;
  x.exp += shift;
  return (x);
};

vfloat operator>>(vfloat r, const natural shift) {
  vfloat x = r;
  x.exp -= shift;
  return (x);
};

}  // namespace SPUC
