#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_classes
#include <spuc/spuc_types.h>
#include <vector>
#include <spuc/complex.h>
namespace SPUC {
class rotate90 {
 public:
  rotate90() { phase = 0; }

  void process(const std::vector<complex<double> >& samples_in, std::vector<complex<double> >& samples_out);

 private:
  unsigned int phase;
};

}  // namespace SPUC
