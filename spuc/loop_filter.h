#ifndef SPUC_LOOP_FILTER
#define SPUC_LOOP_FILTER

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
// from directory: spuc_real_double_templates
#include <spuc/spuc_types.h>
#include <spuc/complex.h>
#include <spuc/unquantized_mixed_type.h>
namespace SPUC {
//! \file
//! \brief Loop Filter for use in PLL circuits
//
//! \brief Loop Filter for use in PLL circuits
//
//!    Template for 2nd order loop filter (for timing/carrier recovery, etc).
//!    Either branch can be enabled/disabled for 1st/2nd order operation
//!    There is no overflow protection on accumulator.
//!    Gains are not normalized.
//! \author Tony Kirke
//! \image html loop_filter.png
//! \ingroup real_double_templates PLL
//! \image html loop_filter.gif
//! \image latex loop_filter.eps
template <class Numeric, class Coeff=double> class loop_filter
{
 public:
  //! enable first order branch
  long k0_en; 
  //! enable second order branch
  long k1_en; 
  //! First order gain
  Coeff k0; 
  //! second order gain
  Coeff k1; 
  //! Accumulator for k1 branch (should not be written to)
  typedef typename unquantized_mixed_type<Numeric,Coeff>::dtype k_type;
  k_type k1_acc;

 protected:
  Numeric loop_out;
  k_type k1_prod, k0_prod;
  
 public:
  //! Constructor
  loop_filter(void) { 
	reset();
	k0 = k1 = (Coeff)0; k0_en = k1_en = 0;
  }
  //! Reset
  void reset(void) { k1_acc = k1_prod = k0_prod = (k_type)0; loop_out = (Numeric)0; }
  //! Normal call with input, returns output.
  Numeric update(Numeric error) {
    k0_prod = (k0_en) ? error*k0 : 0;
    k1_prod = (k1_en) ? error*k1 : 0;
    loop_out = (Numeric)(k1_acc + k0_prod); // Use last k1_acc!
    k1_acc += k1_prod; 
    return(loop_out);
  }
};
} // namespace SPUC
#endif
