#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_double_templates
#include <spuc/spuc_types.h>
#include <spuc/spuc_defines.h>
#include <vector>
namespace SPUC {
//! \file
//! \brief  Template class for Delay line with Fixed Delay
//
//! \brief  Template class for Delay line with Fixed Delay
//
//! Template class for a Delay line (primitive used in other classes)
//!  Allows user to check at various points in delay line,
//!  but default use is a pure delay.
//! \author Tony Kirke
//! \ingroup double_templates misc
//! \image html delay.gif
//! \image latex delay.eps
template <class Numeric, int D> class fixed_delay {
 public:
  long NumTaps;

 protected:
  Numeric z[D + 1];

 public:
  //! Constructor
  fixed_delay() : NumTaps(D + 1) {
    for (int i = 0; i < NumTaps; i++) z[i] = (Numeric)0;
  }
  void reset(void) {
    for (int i = 0; i < NumTaps; i++) z[i] = (Numeric)0;
  }
  //! Get delay at tap i
  Numeric check(long i) {
    SPUC_ASSERT(i <= this->NumTaps);
    return (z[i]);
  }
  //! Look back in delay line by i samples
  Numeric checkback(long i) {
    SPUC_ASSERT(i <= this->NumTaps);
    return (z[NumTaps - 1 - i]);
  }
  //! Get last tap
  Numeric last() { return (z[NumTaps - 1]); }
  //! Clock in new input sample
  Numeric input(Numeric in) {
    int i;
    // Update history of inputs
    for (i = NumTaps - 1; i > 0; i--) z[i] = z[i - 1];
    // Add new input
    z[0] = in;
    return (z[NumTaps - 1]);
  }
  //! Clock in new sample and get output from delay line
  inline Numeric update(Numeric in) {
    input(in);
    return (z[NumTaps - 1]);
  }
};
}  // namespace SPUC
