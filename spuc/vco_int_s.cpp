
// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_templates
#include <spuc/vco.h>
#include <spuc/spuc_math.h>
#include <spuc/int_s.h>
#include <spuc/complex.h>
namespace SPUC {
template <> int_s vco<int_s>::get_phase(void) { return (phase); }
template <> complex<int_s> vco<int_s>::clock() {
  acc += new_fcw;
  phase = acc >> (long)(32 - phase_bits);  // truncate
  float arg = TWOPI * ((float)phase) / phase_bits;
  complex<float> x = ((float)amp) * expj(arg);
  return (complex<int_s>(SPUC_TOLONG(real(x)), SPUC_TOLONG(imag(x))));
}
template <> complex<int_s> vco<int_s>::clock(int_s loop_filter_out) {
  new_fcw = fcw + loop_filter_out;
  return (clock());
}
}  // namespace SPUC
