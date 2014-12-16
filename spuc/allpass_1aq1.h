#ifndef SPUC_ALLPASS_1AQ1
#define SPUC_ALLPASS_1AQ1

// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_classes
#include <spuc/spuc_types.h>
namespace SPUC {
//! \file
//! \brief   The filter is a "first-order" Allpass section
//
//! \brief   The filter is a "first-order" Allpass section
//
//! of the form
//!  <p>\f$  G(z) =  \frac{a + z^{-1}}{(1+a*z^{-1})} \f$ with A = 0.25
//! \author Tony Kirke
//! \ingroup classes Allpass examples
class allpass_1aq1 {
 protected:
  long adder2;

 public:
  allpass_1aq1() { adder2 = 0; }
  void init() { adder2 = 0; }
  long clock(long input);
};
}  // namespace SPUC
#endif
