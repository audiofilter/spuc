// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_src
#include <spuc/fm_discriminator.h>
namespace SPUC {
float_type fm_discriminator::sample(complex<float_type> c) {
  float_type new_phase = 0;
  float_type delta_phase = 0;

#ifdef USE_SPUC_COMPLEX
  new_phase = arg(c);
#endif
  if (new_phase > PI) new_phase -= TWOPI;

  delta_phase = new_phase - phase;
  if (delta_phase > PI) delta_phase -= TWOPI;
  if (delta_phase < -PI) delta_phase += TWOPI;

  phase = new_phase;

  return (delta_phase);
}
}  // namespace SPUC
