#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
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
