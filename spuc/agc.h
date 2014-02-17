#ifndef SPUC_AGC
#define SPUC_AGC

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
//! \file
//! \brief This is a simple sigma-delta type AGC for the variable rate QPSK example
//
//! \brief This is a simple sigma-delta type AGC for the variable rate QPSK example
//
//! \author Tony Kirke
//! \ingroup classes examples
class agc {
public:	
  long agc_acc;
  long agc_bit;
  long agc_thres;
  
  agc(long thres=32);
  long run(complex<long> adc);
};
} // namespace SPUC
#endif
