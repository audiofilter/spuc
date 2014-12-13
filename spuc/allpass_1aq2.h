#ifndef SPUC_ALLPASS_1AQ2
#define SPUC_ALLPASS_1AQ2

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
namespace SPUC {
//! \file
//! \brief   The filter is a "first-order" Allpass section
//
//! \brief The filter is a "first-order" Allpass section
//
//!  of the form
//!  <p>\f$  G(z) =  \frac{a + z^{-1}}{(1+a*z^{-1})} \f$ with A = 0.75
//! \author Tony Kirke
//! \ingroup classes Allpass examples
class allpass_1aq2 {
 protected:
  long adder2;

 public:
  allpass_1aq2() { adder2 = 0; }

  void init() { adder2 = 0; }
  long clock(long input);
};
}  // namespace SPUC
#endif
