#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
#include <spuc/spuc_types.h>
#include <spuc/spuc_defines.h>
#include <cmath>
#include <iostream>
#include <spuc/complex.h>
#include <spuc/quant.h>
#include <spuc/delay.h>
#include <spuc/loop_filter.h>
#include <spuc/nco.h>
#include <spuc/a_d.h>
#include <spuce/filters/fir.h>
#include <spuce/filters/root_raised_cosine.h>
#include <spuce/filters/lagrange.h>
#include <spuc/dd_symbol.h>
#include <spuc/qpsk_quadricorrelator.h>
#include <spuc/bpsk_quadricorrelator.h>
#include <spuc/qpsk_rcfd.h>
#include <spuc/cp_afc.h>
#include <spuc/carrier_nco.h>
#include <spuc/vco.h>
#include <spuc/nda_symbol.h>
#include <spuc/qpsk_dd_phase.h>
namespace SPUC {
//! \file
//! \brief A QPSK receiver that can operate at exactly 2 samples/symbol
//
//! \brief A QPSK receiver that can operate at exactly 2 samples/symbol
//
//! to illustrate carrier phase locked loop and demod process
//! see qpsk_variable for more comprehensive example.
//! \author Tony Kirke,  Copyright(c) 2001
//! \author Tony Kirke
//! \ingroup real_templates comm examples
//! \image html qpsk.gif
//! \image latex qpsk.eps
template <class Numeric> class qpsk {
 public:
  a_d ADC;
  loop_filter<Numeric> carrier_loop_filter;
  loop_filter<Numeric> symbol_loop_filter;

  Numeric carrier_loop_out, symbol_loop_out;
  bool symbol_clk;
  bool symbol_clk_pls;
  bool sample_clk;
  bool symbol_x2_clk;
  bool symbol_x2_clk_pls;

  vco<Numeric> c_nco;

  spuce::fir<std::complex<Numeric>, int64_t> rcv_sqrt_rc;

  delay<std::complex<Numeric> > final_baseband_delay;
  delay<std::complex<Numeric> > hard_decision_delay;
  delay<std::complex<Numeric> > timing_disc_delay;

  int64_t bpsk;
  int64_t dec_rate_log;
  Numeric carrier_error;
  Numeric symbol_nco_out;
  std::complex<Numeric> prev_sam, prev_sym;
  std::complex<Numeric> decision;
  std::complex<Numeric> hard_decision_prev, final_baseband_prev;
  std::complex<Numeric> baseband;
  std::complex<Numeric> resampled;
  std::complex<Numeric> carrier_in;
  std::complex<Numeric> carrier_nco_out;
  std::complex<Numeric> mf_in;
  std::complex<Numeric> mf_out;
  std::complex<Numeric> final_baseband;
  std::complex<Numeric> hard_decision;

  Numeric timing_error;
  Numeric nda_timing_error;
  Numeric I_data() { return (real(hard_decision)); }
  Numeric Q_data() { return (imag(hard_decision)); }
  std::complex<Numeric> data() { return (hard_decision); }
  Numeric carrier_loop() { return (carrier_loop_out); }
  Numeric symbol_loop() { return (symbol_loop_out); }
  bool symclk(void) { return (symbol_clk_pls); }
  qpsk(void) : rcv_sqrt_rc(9), final_baseband_delay(2), hard_decision_delay(2), timing_disc_delay(3) {
    //! alpha = 0.35 root raised cosine fir
    spuce::fir_coeff<int64_t> fir_c(rcv_sqrt_rc.number_of_taps());
    spuce::root_raised_cosine_quantized(fir_c, 0.35, 2, 8, -0.2);
    rcv_sqrt_rc.settaps(fir_c);

    reset();

    carrier_loop_filter.k0 = 1 << 15;
    carrier_loop_filter.k1 = 1 << 8;

    carrier_loop_filter.k0_en = 0;
    carrier_loop_filter.k1_en = 0;
    symbol_loop_filter.k0 = 1 << 6;
    symbol_loop_filter.k1 = 1;

    symbol_loop_filter.k0_en = 0;
    symbol_loop_filter.k1_en = 0;
  }
  void reset(void) {
    rcv_sqrt_rc.reset();
    carrier_loop_filter.reset();
    symbol_loop_filter.reset();
    c_nco.reset_frequency(0);
    c_nco.reset();

    carrier_error = 0;
    timing_error = 0;
    carrier_loop_out = 0;
    symbol_loop_out = 0;
    symbol_clk = 0;
    symbol_clk_pls = 0;
    symbol_x2_clk_pls = 0;
    sample_clk = 0;
    nda_timing_error = 0;
  }
  void clock(std::complex<Numeric> adc_out) {
    std::complex<Numeric> carrier_phase;
    int64_t nda = 0;  //! Don't use NDA timing discriminator

    //! Down conversion
    if (symbol_clk_pls)
      carrier_phase = c_nco.clock(carrier_loop_out);
    else
      carrier_phase = c_nco.clock();
    baseband = adc_out * carrier_phase;
    baseband = round(baseband, 7);

    symbol_clk_pls = 0;
    symbol_x2_clk_pls = 0;
    resampled = baseband;  //! Digital Interpolation/Resampling would go here
    symbol_x2_clk = 1;

    //! Processing at 2 times the symbol rate
    if (symbol_x2_clk) {
      symbol_x2_clk_pls = 1;
      //! input to matched filter & does calculation
      mf_in = resampled;
      mf_out = rcv_sqrt_rc.update(mf_in);
      mf_out = round(mf_out, 6);
      //! Slicer - get sign bit prior to rounding!
      hard_decision = signbit(mf_out);
      symbol_clk = !symbol_clk;
      prev_sym = timing_disc_delay.input(mf_out);
      prev_sam = timing_disc_delay.checkback(1);
      decision = hard_decision;
      if (nda) timing_error = nda_symbol(prev_sym, mf_out);
      //! Symbol rate processing
      if (symbol_clk) {
        hard_decision_prev = hard_decision_delay.input(decision);
        symbol_clk_pls = 1;
        //! Matched Filter out
        final_baseband = mf_out;
        //! Symbol discriminator
        if (!nda) timing_error = dd_symbol(prev_sym, mf_out, hard_decision_prev, decision);
        //! Carrier discriminator
        carrier_error = qpsk_dd_phase(mf_out, decision);
        //! Symbol + timing loop filters
        symbol_loop_out = symbol_loop_filter.update(timing_error);
        carrier_loop_out = carrier_loop_filter.update(carrier_error);
      }
    }
    return;
  }
};
}  // namespace SPUC
