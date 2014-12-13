
/*
    Copyright (C) 2014 Tony Kirke

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
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
template <float_type Des_function(float_type),
          float_type Weight_function(float_type)>
void remez_function(std::vector<float_type>& r_fir, int numtaps, int numband,
                    int r, std::vector<float_type> bands, int type) {
  float_type floor(float_type x);
  int j = 0;
  int k;
  float_type lowf, highf;
  float_type delf = 0.5 / (GRIDDENSITY * r);
  // Predict dense grid size in advance for array sizes
  int gridSize = 0;
  for (int i = 0; i < numband; i++) {
    gridSize += (int)floor(
        0.5 + 2 * r * GRIDDENSITY * (bands[2 * i + 1] - bands[2 * i]));
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
