
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
namespace SPUC {
void create_remez_fir(fir_coeff<float_type>& remezfir, int jtype,int nbands,
											std::vector<float_type> edge, 
											std::vector<float_type> fx,
											std::vector<float_type> wtx) {
  bool ok;
  long nfilt = remezfir.num_taps;
  remez_fir Remz;
  std::vector<float_type> fir_coef(nfilt);
  ok = Remz.remez(fir_coef,nfilt,nbands,edge,fx,wtx,jtype);
  if (!ok) {
	for (int i=0;i<nfilt;i++) remezfir.settap(i,0);
	remezfir.settap(0,1);
  } else {
	for (int i=0;i<nfilt;i++) remezfir.settap(i,fir_coef[i]);
  }
}
} // namespace SPUC
