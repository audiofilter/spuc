// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_templates
#include <spuc/vco.h>
#include <spuc/dsp_functions/spuc_math.h>
#include <spuc/complex.h>
namespace SPUC {
template <> float vco<float>::get_phase(void) { return (acc); }
template <> double vco<double>::get_phase(void) { return (acc); }
template <> int vco<int>::get_phase(void) { return (phase); }
template <> long vco<long>::get_phase(void) { return (phase); }

template <> complex<float> vco<float>::clock() {
  acc += new_fcw;
  if (acc > TWOPI) acc -= TWOPI;
  if (acc < -TWOPI) acc += TWOPI;
  return (expj(acc));
}
template <> complex<float> vco<float>::clock(float loop_filter_out) {
  load(loop_filter_out);
  return (clock());
}
template <> complex<long> vco<long>::clock() {
  acc += new_fcw;
  phase = acc >> (32 - phase_bits);  // truncate
  float arg = TWOPI * phase / phase_bits;
  complex<float> x = ((float)amp) * expj(arg);
  return (complex<long>(SPUC_TOLONG(real(x)), SPUC_TOLONG(imag(x))));
}
template <> complex<long> vco<long>::clock(long loop_filter_out) {
  new_fcw = fcw + loop_filter_out;
  return (clock());
}
/////////////////
template <> complex<double> vco<double>::clock() {
  acc += new_fcw;
  if (acc > TWOPI) acc -= TWOPI;
  if (acc < -TWOPI) acc += TWOPI;
  return (expj(acc));
}
template <> complex<double> vco<double>::clock(double loop_filter_out) {
  load(loop_filter_out);
  return (clock());
}
template <> complex<int> vco<int>::clock() {
  acc += new_fcw;
  phase = acc >> (32 - phase_bits);  // truncate
  double arg = TWOPI * phase / phase_bits;
  complex<double> x = ((double)amp) * expj(arg);
  return (complex<int>(SPUC_TOLONG(real(x)), SPUC_TOLONG(imag(x))));
}
template <> complex<int> vco<int>::clock(int loop_filter_out) {
  new_fcw = fcw + loop_filter_out;
  return (clock());
}
}  // namespace SPUC
