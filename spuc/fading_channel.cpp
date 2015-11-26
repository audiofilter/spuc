// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_src
#include <cmath>
#include <spuc/fading_channel.h>
#include <spuc/complex.h>
#include <spuc/dsp_functions/spuc_math.h>
#include <vector>
namespace SPUC {
void fading_channel::setup(float_type norm_delay_spread) {
  if (norm_delay_spread) {
    delay_spread = 1.0 / norm_delay_spread;
    generate_channel();
  } else {  // == 0
    exp_decay.settap(0, 1.0);
    for (int i = 1; i < taps; i++) exp_decay.settap(i, 0);
  }
}
void fading_channel::generate_channel() {
  int i;
  float_type exp(float_type y);
  float_type temp = 0;
  std::vector<float_type> tap_power(taps);
  // float_type tap_power[taps];

  for (i = 0; i < taps; i++) {
    tap_power[i] = ::exp(-i * delay_spread);
    temp += tap_power[i];
  }
  // normalize & Divide by 2 (because complex coefficients)
  temp = 0.5 / temp;
  for (i = 0; i < taps; i++) tap_power[i] = std::sqrt(temp * tap_power[i]);

  exp_decay.reset();

  for (i = 0; i < taps; i++) exp_decay.settap(i, tap_power[i] * tap_gain.Cgauss());
}
// Convolution
complex<float_type> fading_channel::update(const complex<float_type> signal) {
  if (taps > 0)
    return (exp_decay.update(signal));
  else
    return (signal);
}
}  // namespace SPUC
