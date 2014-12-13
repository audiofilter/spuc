#ifndef SPUC_NOTCH_COMB
#define SPUC_NOTCH_COMB

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
// from directory: spuc_double_templates
#include <spuc/spuc_types.h>
#include <spuc/allpass_1.h>
namespace SPUC {

//! \file
//! \author Tony Kirke
//! \author Tony Kirke
//! \ingroup double_templates double_templates iir
template <class Numeric, class Coeff = float_type>
class notch_comb {
 public:
  allpass_1<Numeric, Coeff> ap;

  notch_comb(float_type fp, int dly) : ap(fp, dly) {}
  notch_comb(float_type fp) : ap(fp, 1) {}
  notch_comb() : ap(0.5, 1) {}
  void set_coeffs(float_type fp, int dly) { ap.init(fp, dly); }

  void reset() { ap.reset(); }
  Numeric clock(Numeric x) {
    Numeric sum = 0.5 * (x + ap.clock(x));
    return (sum);
  }
};

}  // namespace SPUC
#endif
