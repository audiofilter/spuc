#ifndef SPUC_SHELF_ALLPASS1
#define SPUC_SHELF_ALLPASS1

// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_double_templates
#include <spuc/spuc_types.h>
#include <spuc/allpass_1.h>
namespace SPUC {

double z_freqz_db(bool hpf, double f, double a, double h, double l);
double find_a(bool hpf, double f, double des_gain, double h, double l);

//! \file
//! \brief IIR zolzer filter based on 2nd order allpass structure
//
//! \brief IIR zolzer filter based on 2nd order allpass structure
//! \author Tony Kirke
//! \image html zolzer_allpass.png
//! \author Tony Kirke
//! \ingroup double_templates double_templates iir
template <class Numeric, class Coeff = float_type> class shelf_allpass1 {
 public:
  allpass_1<Numeric, Coeff> ap;
  Coeff low_gain;
  Coeff high_gain;
  bool high_boost;  // high-pass sum case

  // zolzer_allpass(float_type a, float_type g) : ap(a) { gain=g; }
  shelf_allpass1() : ap(0) {}

  void set_coeffs(float_type fc, float_type low_g_db, float_type high_g_db) {
    high_boost = (low_g_db < 0);
    // Convert from dB to gain values
    // std::cout << "Zolzer gains (dbs) " << low_g_db << " " << high_g_db << "
    // ";
    low_gain = pow(10.0, low_g_db / 20.0);
    high_gain = pow(10.0, high_g_db / 20.0);
    // std::cout << " gains " << low_gain << " " << high_gain << " ";
    if (high_boost) { high_gain = (high_gain - low_gain) / 2.0; } else {
      low_gain = (low_gain - high_gain) / 2.0;
    }

    // std::cout << " new low/high gains " << low_gain <<  " " << high_gain <<
    // "\n";
    // std::cout << " new low/high dbs " << 20*log10(low_gain) <<  " " <<
    // 20*log10(high_gain) << "\n";
    //
    // double a = (tan(PI*fc) - 1.0)/(tan(PI*fc) + 1.0);
    // std::cout << " orig fc = " << fc << " a = " << a << "\n";

    double a = find_a(high_boost, fc, 0.0, high_gain, low_gain);
    // std::cout << " Calc new a = " << a  <<  "\n";

    ap.init(a, 1);
    reset();
  }

  void reset() { ap.reset(); }

  Numeric clock(Numeric x) {
    Numeric sum;
    if (high_boost) { sum = low_gain * x + high_gain * (x - ap.clock(x)); } else {
      sum = high_gain * x + low_gain * (x + ap.clock(x));
    }
    return (sum);
  }
};

}  // namespace SPUC
#endif
