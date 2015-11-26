#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_real_templates
#include <spuc/spuc_types.h>
#include <string>
#include <cmath>
#include <iostream>
#include <spuc/spuc_defines.h>
#include <spuc/complex.h>
#include <spuc/delay.h>
#include <spuc/loop_filter.h>
#include <spuc/vco.h>
#include <spuc/a_d.h>
#include <spuce/filters/fir.h>
#include <spuce/filters/lagrange.h>
#include <spuc/cordic.h>
#include <spuc/qpsk_discriminators.h>
#include <spuc/sum_and_dump.h>
#include <spuc/resampler.h>
#include <spuc/agc.h>
#include <spuc/quant.h>
#include <spuc/builtin.h>
namespace SPUC {
//! \file
//! \brief A QPSK receiver that can operate over a range of non-integer sampling rates
//
//! ,Symbol timing, frequency control and carrier phase locked loops
//! are included. Also contains root-raised cosine matched filter,
//! A/D and agc function.
//! \author Tony Kirke
//!  \ingroup real_templates comm examples
template <class Numeric> class qpsk_variable {
 public:
  a_d ADC;
  spuce::fir<std::complex<Numeric>, Numeric> rcv_sqrt_rc;
  spuce::lagrange<std::complex<float_type> > interp;

  delay<std::complex<Numeric> > final_baseband_delay;
  delay<std::complex<Numeric> > hard_decision_delay;
  delay<std::complex<Numeric> > timing_disc_delay;

  sum_and_dump<Numeric> symbol_lock_detect;
  spuce::fir<std::complex<Numeric>, Numeric> fmf;

  agc sigma_delta;
  loop_filter<Numeric> afc_loop_filter;
  loop_filter<Numeric> carrier_loop_filter;
  loop_filter<Numeric> symbol_loop_filter;
  qpsk_discriminators discriminators;

  Numeric agc_bit;
  Numeric carrier_loop_out, symbol_loop_out;
  bool symbol_clk;
  bool symbol_clk_pls;
  bool sample_clk;
  bool symbol_x2_clk;
  bool symbol_x2_clk_pls;

  vco<Numeric> carrier__nco;
  cordic<Numeric> cordic_mult;

  resampler<std::complex<Numeric> > rate_change;

  int64_t bpsk;
  int64_t resampler_round;
  //  Numeric dec_rate_log;
  int sym_dec;
  Numeric carrier_error;
  Numeric symbol_nco_out;
  std::complex<Numeric> hard_decision_prev, final_baseband_prev;
  std::complex<int64_t> adc_out;
  std::complex<Numeric> baseband;
  std::complex<Numeric> decimated;
  std::complex<Numeric> decimated_baseband;
  std::complex<Numeric> resampled;
  std::complex<Numeric> carrier_in;
  std::complex<Numeric> carrier_nco_out;
  std::complex<Numeric> mf_in;
  std::complex<Numeric> mf_out;
  std::complex<Numeric> fmf_out;
  std::complex<Numeric> final_baseband;
  Numeric timing_error;
  Numeric nda_timing_error;
  Numeric sym_lock;       // from lock discriminator
  Numeric symbol_locked;  // averaged value;
  Numeric sym_lock_thres;
  Numeric cp_afc, quad_afc;
  bool afc;
  std::complex<Numeric> hard_decision;

  Numeric qpsk_bpsk_reg;
  Numeric lock_rate_reg;
  Numeric invert_q_reg;

  Numeric I_data() { return (real(hard_decision)); }
  Numeric Q_data() { return (imag(hard_decision)); }
  std::complex<Numeric> data() { return (hard_decision); }
  Numeric carrier_loop() { return (carrier_loop_out); }
  Numeric symbol_loop() { return (symbol_loop_out); }
  bool symclk(void) { return (symbol_clk_pls); }
  Numeric agc_out(void) { return (agc_bit); }
  //  void symbol_lock_average(void);
  qpsk_variable(void)
      : ADC(6),
        rcv_sqrt_rc(9),
        interp(4),
        final_baseband_delay(2),
        hard_decision_delay(2),
        timing_disc_delay(3),
        symbol_lock_detect(12),
        fmf(9),
        sigma_delta(32)

  {
    // CSD Coefficients for alpha = 0.35 root raised cosine fir
      rcv_sqrt_rc.settap(4,14);
      rcv_sqrt_rc.settap(3,8);
      rcv_sqrt_rc.settap(5,8);
      rcv_sqrt_rc.settap(2,-1);
      rcv_sqrt_rc.settap(6,-1);
      rcv_sqrt_rc.settap(1,-2);
      rcv_sqrt_rc.settap(0,1);
      rcv_sqrt_rc.settap(8,1);

      fmf.settap(3, rcv_sqrt_rc.gettap(5));
      fmf.settap(2, rcv_sqrt_rc.gettap(6));
      fmf.settap(1, rcv_sqrt_rc.gettap(7));
      fmf.settap(0, rcv_sqrt_rc.gettap(8));
      fmf.settap(4,0);
      fmf.settap(5,-rcv_sqrt_rc.gettap(5));
      fmf.settap(6,-rcv_sqrt_rc.gettap(6));
      fmf.settap(7,-rcv_sqrt_rc.gettap(7));
      fmf.settap(8,-rcv_sqrt_rc.gettap(8));

    //	unsigned int64_t fcw = 1 << (25); for testing
    carrier__nco.reset_frequency(0);
    carrier_error = 0;
    timing_error = 0;
    carrier_loop_out = 0;
    carrier_loop_filter.k0 = 1 << 15;
    carrier_loop_filter.k1 = 1 << 8;

    carrier_loop_filter.k0_en = 0;
    carrier_loop_filter.k1_en = 0;
    symbol_loop_out = 0;
    symbol_loop_filter.k0 = 1 << 7;
    symbol_loop_filter.k1 = 1;

    symbol_loop_filter.k0_en = 0;
    symbol_loop_filter.k1_en = 0;

    resampler_round = 2;  // default
    bpsk = 0;
    afc = 0;
    discriminators.set_mode(bpsk);
    sym_dec = 1;
    symbol_clk = 0;
    symbol_clk_pls = 0;
    symbol_x2_clk_pls = 0;
    sample_clk = 0;
    nda_timing_error = 0;
    sym_lock = 0;
    symbol_locked = 0;
    agc_bit = 0;
    sym_lock_thres = 4;
    symbol_lock_detect.set_exp(12);
  }
  void clock(std::complex<Numeric> adc) {
    int64_t rcfd = 1;  // FMF frequency discriminator
#ifdef NDA
    int64_t nda = 1;
#else
    int64_t nda = 0;  // Don't use NDA timing discriminator
#endif

    // A/D input (assume valid every time step called!
    //    adc_out = ADC.sample(adc_in);
    //	agc_bit = sigma_delta.run(adc_out);

    // Down conversion
    if (symbol_clk_pls) carrier__nco.load(carrier_loop_out);
    carrier__nco.clock();
    Numeric carrier_phase = carrier__nco.get_phase();
    //	int64_t carrier_phase = carrier_nco.run(carrier_loop_out,symbol_x2_clk_pls);

    baseband = cordic_mult.rotate(adc, carrier_phase);
#ifdef NODC
    baseband = adc;
#endif

    symbol_clk_pls = 0;

    // Decimation
    decimated = baseband;  // decim.update(baseband);
    sample_clk = 1;        // decim.ready; // Output at decimated rate
    symbol_x2_clk_pls = 0;

    // Processing at Decimated Rate
    if (sample_clk) {
      // TEMP -> FORCE SYMBOL_LOOP_OUT-> INT64_T
      resampled = rate_change.update(decimated, (int64_t)symbol_loop_out, symbol_clk);
      resampled = round(resampled, resampler_round);
      symbol_x2_clk = rate_change.ready;

      // Processing at 2 times the symbol rate
      if (symbol_x2_clk) {
        symbol_x2_clk_pls = 1;
        // input to matched filter & does calculation
        mf_in = saturate(resampled, 6);
        mf_out = rcv_sqrt_rc.update(mf_in);
        fmf_out = fmf.update(mf_in);
        // Slicer - get sign bit prior to rounding!
        hard_decision = signbit(mf_out);
        mf_out = round(mf_out, 7);
        mf_out = saturate(mf_out, 4);
        fmf_out = round(fmf_out, 7);

        symbol_clk = !symbol_clk;
        discriminators.sample(fmf_out, mf_out, hard_decision, symbol_clk);
        if (nda) timing_error = discriminators.nda_timing_disc();
        sym_lock = discriminators.symbol_lock_out();
        if (rcfd && afc) {
          // carrier_error = discriminators.rcfd();
          carrier_error = discriminators.quad();
          carrier_loop_out = carrier_loop_filter.update(carrier_error);
        }

        // Symbol rate processing
        if (symbol_clk) {
          symbol_clk_pls = 1;
          // lock detector
          symbol_lock_detect.input(sym_lock);
          if ((symbol_lock_detect.output()) > (int64_t)1024 * sym_lock_thres)
            symbol_locked = 1;
          else
            symbol_locked = 0;
          // Matched Filter out
          final_baseband = mf_out;
          // Symbol discriminator
          if (!nda) timing_error = discriminators.dd_timing_disc();
          // Carrier discriminator
          if (afc)
            carrier_error = discriminators.cross_prod_afc();
          else
            carrier_error = discriminators.pll_disc();
          // Symbol + timing loop filters
          symbol_loop_out = symbol_loop_filter.update(timing_error);
          if (!rcfd || !afc) carrier_loop_out = carrier_loop_filter.update(carrier_error);
        }
      }
    }
    return;
  }
};

}  // namespace SPUC
