
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
// from directory: spuc_src
#include <cmath>
#include <spuc/spuc_defines.h>
#include <spuc/complex.h>
#include <spuc/fir_coeff.h>
#include <spuc/remez_fir.h>
#include <spuc/create_remez_lpfir.h>
namespace SPUC {
//! \brief calculates the coefficients for lowpass FIR based on Remez constraints
void create_remez_lpfir(fir_coeff<float_type>& remezfir, float_type pass_edge, float_type stop_edge, float_type stop_weight) {
  bool ok=true;
  std::vector<float_type> e1(4);
  std::vector<float_type> f1(4); 
  std::vector<float_type> w1(4); 
  long nfilt = remezfir.num_taps;
  remez_fir Remz;
  w1[0] = 1.0;
  w1[1] = stop_weight;
  e1[0] = 0;
  e1[1] = pass_edge/2.0;
  e1[2] = stop_edge/2.0;
  e1[3] = 0.5;
  f1[0] = 1.0;
  f1[1] = 0.0;
  std::vector<float_type> fir_coef(nfilt);
  ok = Remz.remez(fir_coef,nfilt,2,e1,f1,w1,1);
  if (ok) {
	for (int i=0;i<nfilt;i++) remezfir.settap(i,fir_coef[i]);
  } else {
	for (int i=0;i<nfilt;i++) remezfir.settap(i,0);
	remezfir.settap(0,1);
  }
}
} // namespace SPUC
