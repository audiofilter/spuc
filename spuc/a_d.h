#ifndef SPUC_A_D
#define SPUC_A_D

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
#include <spuc/complex.h>
namespace SPUC {
//!  \file
//!  \brief An A/D conversion class
//
//!  \brief An A/D conversion class
//
//!  Bit width is specified in constructor. Default is 8 bits.
//!  Handles real and complex samples
//! \author Tony Kirke
//! \image html a_d.png
//!  \ingroup classes misc sim
// \image html a_d.gif
// \image latex a_d.eps
class a_d
{
protected:
  char size;              //! Number of bits <= 8
  long max;
  long min;
  
public:
  //! Constructor
  a_d(char h=8);
  //! Quantize and limit signal to size bits  
  long clock(float_type x);
  complex<long> clock(complex<float_type> x);
};
} // namespace SPUC
#endif
