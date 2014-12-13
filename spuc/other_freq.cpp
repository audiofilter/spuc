
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
#include <spuc/complex.h>
#include <spuc/spuc_math.h>
#include <spuc/other_freq.h>
namespace SPUC {

void cic_freq(int rate, int order, int pts, double* w, int freq_off,
              double inc) {
  double db = 0;
  double sum = 0;
  double wf = inc * PI / (double)pts;
  for (int i = 0; i < pts; i++) {
    if (i != freq_off)
      sum = (1.0 / rate) * sin(0.5 * wf * (i - freq_off) * rate) /
            sin(0.5 * wf * (i - freq_off));
    else
      sum = 0;
    //	  std::cout << "w1[" << i << "] = " << sum << "\n";
    db = 10.0 * order * log(magsq(sum)) / log(10.0);
    w[i] = db;
  }
}

}  // namespace SPUC
