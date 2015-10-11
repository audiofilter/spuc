#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
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
class a_d {
 protected:
  char size;  //! Number of bits <= 8
  long max;
  long min;

 public:
  //! Constructor
  a_d(char h = 8);
  //! Quantize and limit signal to size bits
  long clock(float_type x);
  complex<long> clock(complex<float_type> x);
};
}  // namespace SPUC
