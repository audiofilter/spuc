#ifndef SPUC_FAST_EQUALIZER
#define SPUC_FAST_EQUALIZER

// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_classes
#include <spuc/spuc_types.h>
#include <spuc/spuc_types.h>
#include <spuc/complex.h>
#include <vector>
#include <spuc/iir_allpass_variable_cascade.h>
namespace SPUC {

class fast_equalizer {
 public:
  typedef complex<double> audio_data_type;
  int num_bands;
  std::vector<iir_allpass_variable_cascade<audio_data_type, double> > S_All;
  std::vector<iir_allpass_variable_cascade<audio_data_type, double> > S_Up;
  std::vector<bool> vld_All;
  std::vector<bool> vld_en;
  std::vector<audio_data_type> eqh;
  std::vector<audio_data_type> eql;
  std::vector<audio_data_type> fil_out;
  std::vector<audio_data_type> eq;
  std::vector<double> levels;
  audio_data_type lpf;
  std::vector<double> gains;
  double lev_gain;
  long count;

  void adjust_level(int filt_num, double gain);

  fast_equalizer(int BANDS = 10);

  void set_num_bands(int B);
  void print_gains();
  void print_levels();
  void init(int points) { ; }
  void set_fs(double f) { ; }
  void reset();
  complex<double> run(const complex<double>& sample);
  complex<double> run_fast(const complex<double>& sample);
  void update_levels();
  void get_levels(float* levs);
  void get_gains(float* gains);
  float get_level(int band) {
    if (band < num_bands)
      return ((float)levels[band]);
    else
      return (0);
  }
  float get_gain(int band) {
    if (band < num_bands) return ((float)gains[band]);
    return (0);
  }
  bool stage(complex<double> s, int i, complex<double>& h, complex<double>& l);

  complex<double> stage_up_down(int i, complex<double> s);
};
}  // namespace SPUC
#endif
