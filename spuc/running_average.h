#ifndef SPUC_RUNNING_AVERAGE
#define SPUC_RUNNING_AVERAGE

// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_templates
#include <spuc/spuc_types.h>
#include <spuc/delay.h>
namespace SPUC {
//! \file
//! \brief template class running average filter consisting of a delay line,
// adder and subtractor
//
//! \brief template class running average filter consisting of a delay line,
// adder and subtractor
//
//! \author Tony Kirke
//! \image html running_average.png
//! \author Tony Kirke
//! \ingroup templates templates fir
//! \image html running_average.gif
//! \image latex running_average.eps
template <class Numeric> class running_average {
 protected:
  Numeric result;
  delay<Numeric> z;
  long size;
  float_type inv_size;

 public:
  //!/ Constructor
  running_average(long n = 0) : z() {
    size = n;
    inv_size = 1.0 / (float_type)size;
    if (n > 1) {
      z.set_size(n - 1);
      z.reset();
    }
    result = (Numeric)0;
  }
  //! Assignment
  running_average& operator=(const running_average& rhs) {
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
  ~running_average(void) {}
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
