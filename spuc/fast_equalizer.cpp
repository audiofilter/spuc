
// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_src
#include <spuc/fast_equalizer.h>
#include <spuc/magsqr.h>
#include <spuc/spuc_math.h>
namespace SPUC {

const int AP_ORDER = 2;  // was 4
const int MAX_BANDS = 10;
const int MIN_BANDS = 3;
fast_equalizer::fast_equalizer(int BANDS)
    : S_All(BANDS - 1),
      S_Up(BANDS - 1),
      vld_All(BANDS),
      vld_en(BANDS),
      eqh(BANDS),
      eql(BANDS),
      fil_out(BANDS - 1),
      eq(BANDS),
      levels(BANDS),
      gains(BANDS) {
  num_bands = BANDS;
  reset();
  lev_gain = 0.75;
}
void fast_equalizer::set_num_bands(int B) {
  if (B > MAX_BANDS) num_bands = MAX_BANDS;
  if (B < MIN_BANDS)
    num_bands = MIN_BANDS;  // don't bother < 3
  else
    num_bands = B;
}

void fast_equalizer::print_gains() {
  std::cout << "Eq gains = ";
  for (int i = 0; i < num_bands; i++) std::cout << (int)20 * log10(gains[i]) << " (dB), ";
  std::cout << "\n";
}
void fast_equalizer::print_levels() {
  std::cout << "Eq levels = ";
  for (int i = 0; i < num_bands; i++) std::cout << (int)20 * log10(levels[i]) << " (dB), ";
  std::cout << "\n";
}

void fast_equalizer::reset() {
  count = 0;
  const double fp = 0.0;
  for (int i = 0; i < num_bands; i++) gains[i] = 0.0;
  for (int i = 0; i < num_bands; i++) levels[i] = 1e-9;
  for (int i = 0; i < num_bands; i++) vld_All[i] = true;
  for (int i = 0; i < num_bands; i++) vld_en[i] = false;
  for (int i = 0; i < num_bands - 1; i++) S_All[i].set_coeffs(fp, AP_ORDER, 2);
  for (int i = 0; i < num_bands - 1; i++) S_Up[i].set_coeffs(fp, AP_ORDER, 2);
}

void fast_equalizer::adjust_level(int filt_num, double gain) { gains[filt_num] = gain; }

void fast_equalizer::update_levels() {
  for (int i = 0; i < num_bands; i++) { levels[i] = lev_gain * levels[i] + (1 - lev_gain) * magsq(eq[i]); }
}
void fast_equalizer::get_gains(float* lx) {
  for (int i = 0; i < num_bands; i++) lx[i] = gains[i];
#ifdef DEBUG
  std::cout << "Gains = ";
  for (int i = 0; i < num_bands; i++) std::cout << lx[i] << " ";
  std::cout << "\n";
#endif
}
void fast_equalizer::get_levels(float* lx) {
  for (int i = 0; i < num_bands; i++) lx[i] = levels[i];
#ifdef DEBUG
  std::cout << "Levels = ";
  for (int i = 0; i < num_bands; i++) std::cout << lx[i] << " ";
  std::cout << "\n";
#endif
}
bool fast_equalizer::stage(complex<double> s, int i, complex<double>& h, complex<double>& l) {
  // Do HbF
  bool vld1 = vld_All[i];
  l = S_All[i].clock(s);
  h = S_All[i].get_hp_out();
  vld_All[i] = !vld1;
  return (vld1);
}

complex<double> fast_equalizer::stage_up_down(int i, complex<double> s) {
  complex<double> up;
  complex<double> up2;
  if (vld_en[i - 1]) {
    complex<double> th2, tl2;
    vld_en[i] = stage(2 * s, i, th2, tl2);
    if (i < num_bands - 2)
      tl2 = stage_up_down(i + 1, tl2);
    else
      tl2 = gains[i + 1] * tl2;
    up2 = tl2 + gains[i] * th2;
  } else { up2 = 0; }
  up = S_Up[i - 1].clock(up2);
  return (up);
}

complex<double> fast_equalizer::run(const complex<double>& sample) {
  complex<double> ret;
  vld_en[0] = stage(sample, 0, eqh[0], eql[0]);
  complex<double> tl;
  tl = stage_up_down(1, eql[0]);
  ret = tl + gains[0] * eqh[0];  // combine with 1st HPF
  return ret;
}
}  // namespace SPUC
