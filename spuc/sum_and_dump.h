#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
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

  sum_and_dump(long exp = 0) : count_exp(exp) {
    count = 0;
    result = average = (Numeric)0;
    count_val = (1 << count_exp) - 1;
  }
  Numeric get_sum() { return average; }
  void reset() {
    count = 0;
    average = 0;
    result = 0;
  }
  Numeric output(void) { return (result); }
  void set_exp(long exp) {
    count_exp = exp;
    count = 0;
    count_val = (1 << count_exp) - 1;
  }
  Numeric run(Numeric in_val) {
    input(in_val);
    return result;
  }
  void input(Numeric in_val) {
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
}  // namespace SPUC
