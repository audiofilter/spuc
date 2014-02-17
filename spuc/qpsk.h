#ifndef SPUC_QPSK
#define SPUC_QPSK

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
#include <spuc/spuc_defines.h>
#include <cmath>
#include <iostream>
#include <spuc/complex.h>
#include <spuc/quant.h>
#include <spuc/delay.h>
#include <spuc/loop_filter.h>
#include <spuc/nco.h>
#include <spuc/a_d.h>
#include <spuc/fir.h>
#include <spuc/root_raised_cosine.h>
#include <spuc/lagrange.h>
#include <spuc/dd_symbol.h>
#include <spuc/qpsk_quadricorrelator.h>
#include <spuc/bpsk_quadricorrelator.h>
#include <spuc/qpsk_rcfd.h>
#include <spuc/cp_afc.h>
#include <spuc/carrier_nco.h>
#include <spuc/vco.h>
#include <spuc/nda_symbol.h>
#include <spuc/qpsk_dd_phase.h>
#include <spuc/builtin.h>
#include <spuc/fundtype.h>
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
template <class Numeric> class qpsk
{
  public:
  typedef typename fundtype<Numeric>::ftype CNumeric;

  a_d	ADC;
  loop_filter<Numeric> carrier_loop_filter;
  loop_filter<Numeric> symbol_loop_filter;


  Numeric carrier_loop_out,symbol_loop_out;
  bool symbol_clk;
  bool symbol_clk_pls;
  bool sample_clk;
  bool symbol_x2_clk;
  bool symbol_x2_clk_pls;

  vco<Numeric> c_nco;

  fir< complex<CNumeric>, long > rcv_sqrt_rc;

  delay < complex<CNumeric> > final_baseband_delay;
  delay < complex<CNumeric> > hard_decision_delay;
  delay < complex<CNumeric> > timing_disc_delay;

  long bpsk;
  long dec_rate_log;
  Numeric carrier_error;
  Numeric symbol_nco_out;
  complex<CNumeric> prev_sam,prev_sym;
  complex<CNumeric> decision;
  complex<CNumeric> hard_decision_prev,final_baseband_prev;
  complex<CNumeric> baseband;
  complex<CNumeric> resampled;
  complex<CNumeric> carrier_in;
  complex<CNumeric> carrier_nco_out;
  complex<CNumeric> mf_in;
  complex<CNumeric> mf_out;
  complex<CNumeric> final_baseband;
  complex<CNumeric> hard_decision;
  
  Numeric timing_error;
  Numeric nda_timing_error;
  Numeric I_data() { return(real(hard_decision)); }
  Numeric Q_data() { return(imag(hard_decision)); }
  complex<CNumeric> data() { return(hard_decision); }
  Numeric carrier_loop() { return(carrier_loop_out); }
  Numeric symbol_loop() { return(symbol_loop_out); }
  bool    symclk(void) { return(symbol_clk_pls); }
  qpsk(void)  : rcv_sqrt_rc(9), final_baseband_delay(2),
				hard_decision_delay(2), timing_disc_delay(3)
  {
	//! alpha = 0.35 root raised cosine fir
	fir_coeff<long> fir_c(rcv_sqrt_rc.num_taps);
	root_raised_cosine_quantized(fir_c,0.35,2,8, -0.2);
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
  void reset(void) 
  {
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
  void clock(complex<CNumeric>adc_out)  {
	complex<CNumeric> carrier_phase;
	long nda=0; //! Don't use NDA timing discriminator
	
	//! Down conversion 
	if (symbol_clk_pls)	carrier_phase = c_nco.clock(carrier_loop_out);
	else 	carrier_phase = c_nco.clock();
	baseband = adc_out*carrier_phase;
	baseband = round(baseband,7);
	
	symbol_clk_pls = 0;
	symbol_x2_clk_pls = 0;
	resampled = baseband; //! Digital Interpolation/Resampling would go here
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
	  if (nda) timing_error = nda_symbol(prev_sym,mf_out);
	  //! Symbol rate processing	
	  if (symbol_clk) {
		hard_decision_prev = hard_decision_delay.input(decision);
		symbol_clk_pls = 1;
		//! Matched Filter out
		final_baseband = mf_out; 
		//! Symbol discriminator
		if (!nda) timing_error = dd_symbol(prev_sym,mf_out,
										   hard_decision_prev,
										   decision);
		//! Carrier discriminator
		carrier_error = qpsk_dd_phase(mf_out,decision);
		//! Symbol + timing loop filters
		symbol_loop_out = symbol_loop_filter.update(timing_error); 
		carrier_loop_out = carrier_loop_filter.update(carrier_error);
	  }	
	}
	return;
  }
};
} // namespace SPUC
#endif
