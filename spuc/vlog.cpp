
// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_types
#include <spuc/vlog.h>
namespace SPUC {
typedef vlog self;

// IO functions
std::ostream& operator<<(std::ostream& os, self r) {
  os << (double)r;
  return (os);
}
std::istream& operator>>(std::istream& is, self r) {
  double x;
  is >> x;
  r = x;
  return (is);
}

}  // namespace SPUC
