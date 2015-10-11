// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_src
#include <iostream>
#include <fstream>
#include <iomanip>
#include <spuc/bit.h>
namespace SPUC {
std::ostream &operator<<(std::ostream &output, const bit &inbin) {
  output << static_cast<int>(inbin);
  return output;
}
std::istream &operator>>(std::istream &input, bit &outbin) {
  int tmp;
  input >> tmp;
  outbin = tmp;
  return input;
}
}  // namespace SPUC
