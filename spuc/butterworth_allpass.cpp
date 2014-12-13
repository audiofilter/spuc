
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
#include <spuc/butterworth_allpass.h>
namespace SPUC {
void butterworth_allpass(std::vector<float_type>& a0, 
						 std::vector<float_type>& a1, int L) {
  int N = 2*L+1;
  int J = L/2;
  int l;
  float_type d;
  for (l=1;l<=J;l++) {
	d = tan(PI*l/N);
	a1[l-1] = d*d;
  }
  for (l=J+1;l<=L;l++) {
	d = 1.0/tan(PI*l/N);
	a0[l-J-1] = d*d;
  }
}
} // namespace SPUC
