#ifndef SPUC_SCIC
#define SPUC_SCIC

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
// from directory: spuc_templates
#include <spuc/spuc_types.h>
#include <spuc/delay.h>
#include <spuc/cic.h>
namespace SPUC {
//! \file
//! \brief Implementation for sharped cascaded integrator comb filter
//
//! \brief Implementation for sharped cascaded integrator comb filter
//
//! Registers are signed long and default number of stages is 2.
//! \author Tony Kirke
//! \image html scic.png
//! \ingroup templates fir
template <class Numeric>
class scic {
 protected:
  long max_rate;
  char stages;
  cic<Numeric> main;
  cic<Numeric> sub;
  delay<Numeric> dly;

 public:
  // Constructor
  scic(char n = 2, long r = 4)
      : max_rate(r), stages(3 * n), main(3 * n), sub(2 * n) {
    dly.set_size(max_rate);
  }
  // To change the number of stages dynamically
  void num_stages(char n, long r) {
    stages = 3 * n;
    max_rate = r;
    main.num_stages(3 * n);
    sub.num_stages(2 * n);
    dly.set_size(max_rate);
  }
  // For SCIC decimation
  Numeric decimate(Numeric in, long rate, signed char dump) {
    Numeric result;
    dly.input(in);
    result = (Numeric)2 * main.decimate(in, dump) -
             (Numeric)3 * sub.decimate(dly.check(rate - 2), dump);
    return (result);
  }
};
}  // namespace SPUC
#endif
