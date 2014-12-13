#ifndef SPUC_QPSK_VARIABLE
#define SPUC_QPSK_VARIABLE

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
#include <spuc/fir.h>
#include <spuc/lagrange.h>
#include <spuc/cordic.h>
#include <spuc/qpsk_discriminators.h>
#include <spuc/sum_and_dump.h>
#include <spuc/resampler.h>
#include <spuc/agc.h>
#include <spuc/quant.h>
#include <spuc/builtin.h>
#include <spuc/fundtype.h>
namespace SPUC {
//! \file
//! \brief A QPSK receiver that can operate over a range of non-integer sampling
//rates
//
//! \brief A QPSK receiver that can operate over a range of non-integer sampling
//rates
//
//! ,Symbol timing, frequency control and carrier phase locked loops
//! are included. Also contains root-raised cosine matched filter,
//! A/D and agc function.
//! \author Tony Kirke
//!  \ingroup real_templates comm examples
template <class Numeric>
class qpsk_variable {
 public:
  typedef typename fundtype<Numeric>::ftype CNumeric;

  a_d ADC;
  fir<complex<CNumeric>, Numeric> rcv_sqrt_rc;

  lagrange<complex<float_type> > interp;

  delay<complex<CNumeric> > final_baseband_delay;
  delay<complex<CNumeric> > hard_decision_delay;
  delay<complex<CNumeric> > timing_disc_delay;

  sum_and_dump<CNumeric> symbol_lock_detect;
  fir<complex<CNumeric>, Numeric> fmf;

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
  cordic<CNumeric> cordic_mult;

  resampler<complex<CNumeric> > rate_change;

  long bpsk;
  long resampler_round;
  //  Numeric dec_rate_log;
  int sym_dec;
  Numeric carrier_error;
  Numeric symbol_nco_out;
  complex<CNumeric> hard_decision_prev, final_baseband_prev;
  complex<long> adc_out;
  complex<CNumeric> baseband;
  complex<CNumeric> decimated;
  complex<CNumeric> decimated_baseband;
  complex<CNumeric> resampled;
  complex<CNumeric> carrier_in;
  complex<CNumeric> carrier_nco_out;
  complex<CNumeric> mf_in;
  complex<CNumeric> mf_out;
  complex<CNumeric> fmf_out;
  complex<CNumeric> final_baseband;
  Numeric timing_error;
  Numeric nda_timing_error;
  Numeric sym_lock;       // from lock discriminator
  Numeric symbol_locked;  // averaged value;
  Numeric sym_lock_thres;
  Numeric cp_afc, quad_afc;
  bool afc;
  complex<CNumeric> hard_decision;

  Numeric qpsk_bpsk_reg;
  Numeric lock_rate_reg;
  Numeric invert_q_reg;

  Numeric I_data() { return (real(hard_decision)); }
  Numeric Q_data() { return (imag(hard_decision)); }
  complex<CNumeric> data() { return (hard_decision); }
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
    rcv_sqrt_rc.coeff[4] = 14;
    rcv_sqrt_rc.coeff[3] = rcv_sqrt_rc.coeff[5] = 8;
    rcv_sqrt_rc.coeff[2] = rcv_sqrt_rc.coeff[6] = -1;
    rcv_sqrt_rc.coeff[1] = rcv_sqrt_rc.coeff[7] = -2;
    rcv_sqrt_rc.coeff[0] = rcv_sqrt_rc.coeff[8] = 1;

    fmf.coeff[3] = rcv_sqrt_rc.coeff[5];
    fmf.coeff[2] = rcv_sqrt_rc.coeff[6];
    fmf.coeff[1] = rcv_sqrt_rc.coeff[7];
    fmf.coeff[0] = rcv_sqrt_rc.coeff[8];
    fmf.coeff[4] = 0;
    fmf.coeff[5] = -rcv_sqrt_rc.coeff[5];
    fmf.coeff[6] = -rcv_sqrt_rc.coeff[6];
    fmf.coeff[7] = -rcv_sqrt_rc.coeff[7];
    fmf.coeff[8] = -rcv_sqrt_rc.coeff[8];

    //	unsigned long fcw = 1 << (25); for testing
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
  void clock(complex<CNumeric> adc) {
    long rcfd = 1;  // FMF frequency discriminator
#ifdef NDA
    long nda = 1;
#else
    long nda = 0;  // Don't use NDA timing discriminator
#endif

    // A/D input (assume valid every time step called!
    //    adc_out = ADC.sample(adc_in);
    //	agc_bit = sigma_delta.run(adc_out);

    // Down conversion
    if (symbol_clk_pls) carrier__nco.load(carrier_loop_out);
    carrier__nco.clock();
    Numeric carrier_phase = carrier__nco.get_phase();
    //	long carrier_phase =
    //carrier_nco.run(carrier_loop_out,symbol_x2_clk_pls);

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
      // TEMP -> FORCE SYMBOL_LOOP_OUT-> LONG
      resampled =
          rate_change.update(decimated, (long)symbol_loop_out, symbol_clk);
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
          if ((symbol_lock_detect.output()) > (long)1024 * sym_lock_thres)
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
          if (!rcfd || !afc)
            carrier_loop_out = carrier_loop_filter.update(carrier_error);
        }
      }
    }
    return;
  }
};

}  // namespace SPUC
#endif
