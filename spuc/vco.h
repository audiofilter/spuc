#ifndef SPUC_VCO
#define SPUC_VCO

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
#include <spuc/complex.h>
#include <spuc/spuc_math.h>
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
template <class Numeric> class vco
{
protected:
  Numeric phase;
  Numeric acc;
  Numeric fcw;
  Numeric new_fcw;
  unsigned long phase_bits;
  long amp;
public:
	//!
  inline vco(long bits=8, long a_bits = 10) {
	reset();
	phase_bits = bits;
	amp   = (1 << a_bits);
  }
  //!
  inline void reset() { phase = new_fcw = fcw = acc = (Numeric)0; }
  //! Set frequency control word
  inline void set_frequency(Numeric freq) { fcw = freq; }
  //! Set new frequency
  inline void reset_frequency(Numeric freq) { fcw = freq; new_fcw = fcw;}
  //! return phase
  Numeric get_phase(void) { return((Numeric)0); } // needs explicit def
  //! Update fcw
  inline void load(Numeric loop_filter_out) {new_fcw = fcw + loop_filter_out;}
  //! return output with updated input
  complex<Numeric> clock(Numeric loop_filter_out); // { return((Numeric)0); } // needs explicit def
  //! return output only
  complex<Numeric> clock(); // { return((Numeric)0); } // needs explicit def
};
} // namespace SPUC
#endif
