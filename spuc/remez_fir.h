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
#include <spuc/smart_array.h>
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
  static void createDenseGrid(int r, int numtaps, int numband, smart_array<float_type> bands,
							  smart_array<float_type> des, smart_array<float_type> weight, int gridSize,
							  smart_array<float_type> grid, smart_array<float_type> d, smart_array<float_type> w,
							  int symmetry);
  static void calc_d(int r, smart_array<float_type> x, smart_array<float_type> ad);
  static void calc_y(int r, smart_array<int> ext, smart_array<float_type> des, smart_array<float_type> w,
					 smart_array<float_type> d, smart_array<float_type> y);
  static float_type gee(float_type freq, int r, smart_array<float_type> d, smart_array<float_type> x, smart_array<float_type> y);
  static void search(int r, smart_array<int> ext, int gridSize, smart_array<float_type> e);
  static bool isDone(int r, smart_array<int> ext, smart_array<float_type> e);
public:
  static bool remez(smart_array<float_type>& filt, int n, int numband,
					smart_array<float_type> bands, smart_array<float_type> des, smart_array<float_type> weight, int type);
};
} // namespace SPUC
#endif
