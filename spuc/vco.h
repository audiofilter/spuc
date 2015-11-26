#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_templates
#include <spuc/spuc_types.h>
#include <spuc/complex.h>
#include <spuc/dsp_functions/spuc_math.h>
namespace SPUC {
//! \file
//! \brief VCO
//
//! \brief  Voltage controlled oscillator with complex output.
//
//! FCW : frequency control word
//! ACC : accumulator
//! Frequency must be set through interface routines set_frequency
//! or reset_frequency.
//! Load routine is to allow frequency to be updated (typically with
//! a loop filter).
//! \author Tony Kirke
//! \ingroup templates PLL
//! \author Tony Kirke
//! \ingroup templates sim
//! \image html vco.gif
//! \image latex vco.eps
template <class Numeric> class vco {
 protected:
  Numeric phase;
  Numeric acc;
  Numeric fcw;
  Numeric new_fcw;
  unsigned long phase_bits;
  long amp;

 public:
  //!
  inline vco(long bits = 8, long a_bits = 10) {
    reset();
    phase_bits = bits;
    amp = (1 << a_bits);
  }
  //!
  inline void reset() { phase = new_fcw = fcw = acc = (Numeric)0; }
  //! Set frequency control word
  inline void set_frequency(Numeric freq) { fcw = freq; }
  //! Set new frequency
  inline void reset_frequency(Numeric freq) {
    fcw = freq;
    new_fcw = fcw;
  }
  //! return phase
  Numeric get_phase(void) { return ((Numeric)0); }  // needs explicit def
  //! Update fcw
  inline void load(Numeric loop_filter_out) { new_fcw = fcw + loop_filter_out; }
  //! return output with updated input
  complex<Numeric> clock(Numeric loop_filter_out);  // { return((Numeric)0); } // needs explicit def
  //! return output only
  complex<Numeric> clock();  // { return((Numeric)0); } // needs explicit def
};
}  // namespace SPUC
