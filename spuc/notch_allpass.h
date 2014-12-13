#ifndef SPUC_NOTCH_ALLPASS
#define SPUC_NOTCH_ALLPASS

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
#include <spuc/allpass_2nd.h>
namespace SPUC {
//! \file
//! \brief IIR notch filter based on 2nd order allpass structure
//
//! \brief IIR notch filter based on 2nd order allpass structure
//! \author Tony Kirke
//! \image html notch_allpass.png
//! \ingroup double_templates iir
template <class Numeric, class Coeff = float_type>
class notch_allpass {
 public:
  allpass_2nd<Numeric, Coeff> ap;

  notch_allpass(float_type fp, float_type k2)
      : ap(k2, -cos(TWOPI * fp) * (1 + k2)) {}
  notch_allpass(float_type fp) : ap(0.9, -cos(TWOPI * fp) * (1 + 0.9)) {}
  notch_allpass() : ap(0.9, -cos(TWOPI * 0.2) * (1 + 0.9)) {}
  void set_coeffs(float_type fp, float_type k2) {
    ap.set_coeffs(k2, -cos(TWOPI * fp) * (1 + k2));
  }

  void reset() { ap.reset(); }
  Numeric clock(Numeric x) {
    Numeric sum = 0.5 * (x + ap.clock(x));
    return (sum);
  }
};
}  // namespace SPUC
#endif
