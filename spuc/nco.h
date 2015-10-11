#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_classes
#include <spuc/spuc_types.h>
#include <spuc/spuc_defines.h>
namespace SPUC {
//! \file
//! \brief NCO with 32 bit accumulator
//
//! \brief NCO with 32 bit accumulator
//!
//!    Numerically controlled oscillator (with 32 bits accumulator)
//!    returns the top (mask_bits) MSBs from accumulator
//!    Useful for carrier recovery where top bits used for input to
//!    sine,cos lookup table.
//!    FCW : frequency control word
//!    ACC : accumulator
//!    Frequency must be set through interface routines set_frequency
//!    or reset_frequency.
//!    Load routine is to allow frequency to be updated (typically with
//!    a loop filter).
//!    When not changing frequency call "clock" routine.
//! \author Tony Kirke
//! \image html nco.png
//! \ingroup classes PLL
class nco {
 public:
  unsigned long phase;

 protected:
  unsigned long acc;
  unsigned long fcw;
  unsigned long new_fcw;
  unsigned long mask_bits;

 public:
  //! Constructor
  nco(long bits = 8);
  //! Reset object
  inline void reset() { phase = new_fcw = fcw = acc = 0; }
  //! Set frequency control word
  inline void set_frequency(unsigned long freq) { fcw = freq; }
  //! Set frequency control word and register for frequency control word
  inline void reset_frequency(unsigned long freq) { new_fcw = fcw = freq; }
  //! Return current phase
  inline long get_phase(void) { return (phase); }
  //! Load new frequency control word
  inline void load(long loop_filter_out) { new_fcw = fcw + loop_filter_out; }
  //! Clock NCO with new frequency control word input
  long clock(long loop_filter_out);
  //! Clock NCO without changing frequency control word
  long clock();
};
}  // namespace SPUC
