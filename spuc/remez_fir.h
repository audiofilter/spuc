#ifndef SPUC_REMEZ_FIR
#define SPUC_REMEZ_FIR

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
// from directory: spuc_classes
#include <spuc/spuc_types.h>
#include <vector>
#define BANDPASS 1
#define DIFFERENTIATOR 2
#define HILBERT 3
#define NEGATIVE 0
#define POSITIVE 1
#define GRIDDENSITY 16
#define MAXITERATIONS 40
namespace SPUC {
//!-------------------------------------------------
//! \file
//! \brief template Remez_fir class
//
//! \brief template Remez_fir class
//
//! <p>Calculates the optimal (in the Chebyshev/minimax sense)
//! FIR filter impulse response given a set of band edges,
//! the desired reponse on those bands, and the weight given to
//! the error in those bands.
//!
//! <p><b>Inputs:</b>
//! <p>int      numtaps - Number of filter coefficients</p>
//! <p>int      numband - Number of bands in filter specification
//! <p>float_type[] bands   - User-specified band edges [2 * numband]
//! <p>float_type[] des     - User-specified band responses [numband]
//! <p>float_type[] weight  - User-specified error weights [numband]
//! <p>int      type    - Type of filter
//!
//! <p><b>Output:</b>
//! <p>float_type[] h       - Impulse response of final filter [numtaps]
//! 
//! \author Tony Kirke
//! \ingroup classes fir
class remez_fir {

 public:
	remez_fir() {}  

 private:
  static void createDenseGrid(int r, int numtaps, int numband, 
							  std::vector<float_type>& bands,
							  const std::vector<float_type>& des, 
							  const std::vector<float_type>& weight, int gridSize,
							  std::vector<float_type>& grid, 
							  std::vector<float_type>& d, 
							  std::vector<float_type>& w,
							  int symmetry);

  static std::vector<float_type> calc_d(int r, const std::vector<float_type>& x);
  static std::vector<float_type> calc_y(int r, const std::vector<int>& ext, 
										const std::vector<float_type>& des, 
										const std::vector<float_type>& w,
										const std::vector<float_type>& d);
  static float_type gee(float_type freq, int r,
						const std::vector<float_type>& ad,
						const std::vector<float_type>& x,
						const std::vector<float_type>& y);
  static void search(int r, std::vector<int>& ext, int gridSize, const std::vector<float_type>& e);
  static bool isDone(int r, const std::vector<int>& ext, const std::vector<float_type>& e);
public:
  static bool remez(std::vector<float_type>& filt, int n, int numband,
					std::vector<float_type>& bands, 
					const std::vector<float_type>& des, 
					const std::vector<float_type>& weight, int type);
};
} // namespace SPUC
#endif
