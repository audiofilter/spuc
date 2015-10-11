// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_src
#include <spuc/rotate90.h>
namespace SPUC {
void rotate90::process(const std::vector<complex<double> >& in, std::vector<complex<double> >& out) {
  out.resize(in.size());
  for (int j = 0; j < in.size(); j++) {
    switch (phase) {
      case 0:
        out[j] = in[j];
        break;
      case 1:
        out[j] = rot90(in[j]);
        break;
      case 2:
        out[j] = -in[j];
        break;
      case 3:
        out[j] = rot270(in[j]);
        break;
    }
    phase = (phase + 1) % 4;
  }
}
}  // namespace SPUC
