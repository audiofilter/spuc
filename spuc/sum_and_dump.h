#ifndef SPUC_SUM_AND_DUMP
#define SPUC_SUM_AND_DUMP

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
namespace SPUC {
//! \file
//! \brief sum and dump filter
//
//! \brief sum and dump filter
//
//! This modules sums the input for a fixed number of samples
//! stores the result and begins a new summation.
//! Similar to an integrate and dump function
//! \author="Tony Kirke" Copyright(c) 1993-1996
//! \author Tony Kirke
//! \ingroup templates fir
template <class Numeric> class sum_and_dump {
public:
  Numeric average;
  Numeric result;
  long count_exp;
  long count;
  long count_val;

  sum_and_dump(long exp=0) : count_exp(exp) {
    count = 0;
	result = average = (Numeric)0;
    count_val = (1 << count_exp) - 1;
  }
  Numeric get_sum() {	return average;  }
  void reset() {
	count = 0;
	average = 0;
	result = 0;
  }
  Numeric output(void) {return(result);}
  void set_exp(long exp) { 
	  count_exp = exp; count = 0; 
	  count_val = (1 << count_exp) - 1;
  }
  Numeric run(Numeric in_val) {
	input(in_val);
	return result;
  }
  void input(Numeric in_val)
  {
	if (count == count_val) {
	  average += in_val;
	  result = average;
	  count = 0;
	} else if (count == 0) {
	  average = in_val;
	  count++;
	} else {
	  average += in_val;
	  count++;
	}
  }
};
} // namespace SPUC
#endif
