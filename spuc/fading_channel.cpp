
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
//! \author Tony Kirke
// from directory: spuc_src
#include <cmath>
#include <spuc/fading_channel.h>
#include <spuc/complex.h>
#include <spuc/spuc_math.h>
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
  for (i = 0; i < taps; i++) tap_power[i] = sqrt(temp * tap_power[i]);

  exp_decay.reset();

  for (i = 0; i < taps; i++)
    exp_decay.settap(i, tap_power[i] * tap_gain.Cgauss());
}
// Convolution
complex<float_type> fading_channel::update(const complex<float_type> signal) {
  if (taps > 0)
    return (exp_decay.update(signal));
  else
    return (signal);
}
}  // namespace SPUC
