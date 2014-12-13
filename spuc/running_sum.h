#ifndef SPUC_RUNNING_SUM
#define SPUC_RUNNING_SUM

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
namespace SPUC {
//! \file
//! \brief template class running average filter consisting of a delay line,
//adder and subtractor
//
//! \brief template class running average filter consisting of a delay line,
//adder and subtractor
//
//! \author Tony Kirke
//! \image html running_sum.png
//! \ingroup templates fir
//! \image html running_sum.gif
//! \image latex running_sum.eps
template <class Numeric>
class running_sum {
 protected:
  Numeric result;
  delay<Numeric> z;
  long size;
  float_type inv_size;

 public:
  //!/ Constructor
  running_sum(long n = 0) : z() {
    size = n;
    inv_size = 1.0 / (float_type)size;
    if (n > 1) {
      z.set_size(n - 1);
      z.reset();
    }
    result = (Numeric)0;
  }
  //! Assignment
  running_sum& operator=(const running_sum& rhs) {
    z = rhs.z;
    result = rhs.result;
    return (*this);
  }
  //!
  void set_size(long n) {
    z.set_size(n - 1);
    result = (Numeric)0;
    size = n;
    inv_size = 1.0 / (float_type)size;
  }
  //! destructor
  ~running_sum(void) {}
  //! Reset/clear
  void reset(void) {
    z.reset();
    result = (Numeric)0;
  }
  //! return result
  Numeric get_result() { return (result); }
  //! Clock in new input sample
  Numeric update(Numeric in) {
    result -= z.last();
    z.input(in);
    result += in;
    return (result);
  }
  Numeric average(Numeric in) { return (((Numeric)inv_size * update(in))); }
};
}  // namespace SPUC
#endif
