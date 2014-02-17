#ifndef SPUC_NOTCH_IIR
#define SPUC_NOTCH_IIR

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
#include <spuc/iir_2nd.h>
namespace SPUC {
//! \file
//! \brief IIR notch filter based on 2nd order biquad
//
//! \brief IIR notch filter based on 2nd order biquad
//! \author Tony Kirke
//! \image html notch_iir.png
//! \ingroup double_templates iir
template <class Numeric, class Coeff=float_type> class notch_iir
{
public:
  iir_2nd<Numeric, Coeff> filter;
  Coeff gain;

  notch_iir(Coeff B, Coeff Y) : filter(1,Y*(1+B),B,2*Y,1) {
	gain = (1+B)*(Coeff)(0.5);
  }
  void set_coeffs(Coeff B, Coeff Y) {
    filter.set_coeffs(1,Y*(1+B),B,2*Y,1);
	gain = (1+B)*(Coeff)(0.5);
  }
  void set_freq(Coeff B) {
    Coeff Y = 0.5*filter.get_a1();
    filter.set_coeffs(1,Y*(1+B),B,2*Y,1);
    gain = (1+B)*(Coeff)(0.5);
  }
  void set_depth(Coeff Y) {
    Coeff B = 0.5*filter.get_b2();
    filter.set_coeffs(1,Y*(1+B),B,2*Y,1);
    gain = (1+B)*(Coeff)(0.5);
  }

  // force gain*x to be Numeric?
  Numeric clock(Numeric x) { return(filter.clock(Numeric(gain*x)));}
};
} // namespace SPUC
#endif
