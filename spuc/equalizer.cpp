
// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_src
#include <spuc/equalizer.h>
#include <spuc/magsqr.h>
#include <spuc/spuc_math.h>
namespace SPUC {

const int AP_ORDER = 4;  // was 4
equalizer::equalizer(int BANDS) : S_All(BANDS - 1), fil_out(BANDS - 1), eq(BANDS), levels(BANDS), gains(BANDS) {
  num_bands = BANDS;
  reset();
  lev_gain = 0.75;
}

void equalizer::reset() {
  count = 0;
  const double fp = 0.0;
  for (int i = 0; i < num_bands; i++) gains[i] = 1.0;
  for (int i = 0; i < num_bands; i++) levels[i] = 1e-9;
  int dly = 2;
  for (int i = 0; i < num_bands - 1; i++) {
    S_All[i].set_coeffs(fp, AP_ORDER, dly);
    dly *= 2;
  }
}

void equalizer::adjust_level(int filt_num, double gain) { gains[filt_num] = gain; }

void equalizer::update_levels() {
  for (int i = 0; i < num_bands; i++) { levels[i] = lev_gain * levels[i] + (1 - lev_gain) * magsq(eq[i]); }
}
void equalizer::get_gains(float* lx) {
  for (int i = 0; i < num_bands; i++) lx[i] = gains[i];
#ifdef DEBUG
  std::cout << "Gains = ";
  for (int i = 0; i < num_bands; i++) std::cout << lx[i] << " ";
  std::cout << "\n";
#endif
}
void equalizer::get_levels(float* lx) {
  for (int i = 0; i < num_bands; i++) lx[i] = levels[i];
#ifdef DEBUG
  std::cout << "Levels = ";
  for (int i = 0; i < num_bands; i++) std::cout << lx[i] << " ";
  std::cout << "\n";
#endif
}
/////
complex<double> equalizer::run(const complex<double>& sample) {
  int i;
  complex<double> ret;
  audio_data_type hpf;
  audio_data_type sum = 0;
  audio_data_type lpf = sample;
  for (i = 0; i < num_bands - 1; i++) {
    fil_out[i] = S_All[i].clock(lpf);
    hpf = S_All[i].get_hp_out();
    lpf = fil_out[i];
    eq[num_bands - 1 - i] = gains[num_bands - 1 - i] * hpf;
    sum += eq[num_bands - 1 - i];
  }
  eq[0] = gains[0] * lpf;  // fil_out[i-1];
  ret = sum + eq[0];
  return ret;
}
}  // namespace SPUC
