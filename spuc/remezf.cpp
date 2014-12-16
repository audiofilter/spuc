
// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_template_functions
#include <spuc/spuc_defines.h>
#include <spuc/remez_fir.h>
namespace SPUC {

//: <font color="red"><i>Under construction!</i></font>
// \brief Template remez function where the desired response and
// weighting functions are passed as template functions,
// thus allowing a simpler interface
//!  \author Tony Kirke,  Copyright(c) 2001
template <float_type Des_function(float_type), float_type Weight_function(float_type)>
void remez_function(std::vector<float_type>& r_fir, int numtaps, int numband, int r, std::vector<float_type>& bands,
                    int type) {
  float_type floor(float_type x);
  int j = 0;
  int k;
  float_type lowf, highf;
  float_type delf = 0.5 / (GRIDDENSITY * r);
  // Predict dense grid size in advance for array sizes
  int gridSize = 0;
  for (int i = 0; i < numband; i++) {
    gridSize += (int)floor(0.5 + 2 * r * GRIDDENSITY * (bands[2 * i + 1] - bands[2 * i]));
  }
  int symmetry = (type == BANDPASS) ? POSITIVE : NEGATIVE;
  if (symmetry == NEGATIVE) gridSize--;

  //  std::vector<float_type> r_fir(numtaps);
  std::vector<float_type> des(gridSize);
  std::vector<float_type> weight(gridSize);

  for (int band = 0; band < numband; band++) {
    lowf = bands[2 * band];
    highf = bands[2 * band + 1];
    k = (int)floor((highf - lowf) / delf + 0.5);
    for (int i = 0; i < k; i++) {
      des[band] = Des_function(lowf);
      weight[band] = Weight_function(lowf);
      lowf += delf;
      j++;
    }
  }

  remez_fir::remez(r_fir, numtaps, numband, bands, des, weight, type);
}
}  // namespace SPUC
