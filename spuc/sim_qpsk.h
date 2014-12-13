#ifndef SPUC_SIM_QPSK
#define SPUC_SIM_QPSK

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
#include <cmath>
#include <spuc/complex.h>
#include <spuc/max_pn.h>
#include <spuc/noise.h>
#include <spuc/vco.h>
#include <spuc/quad_data.h>
#include <spuc/qpsk_ber_test.h>
#include <spuc/qpsk.h>
#include <spuc/builtin.h>
#include <spuc/fundtype.h>
namespace SPUC {
//! \file
//! \brief  A Class for simulating a QPSK system
//!  \author Tony Kirke,  Copyright(c) 2001
//
//! \brief A Class for simulating a QPSK system that includes
//
//! transmitters, receivers, A/D, frequency offsets,
//! gaussian noise, and a BER tester
//! \author Tony Kirke
//!  \ingroup real_templates sim
template <class Numeric>
class sim_qpsk {
 public:
  typedef typename fundtype<Numeric>::ftype CNumeric;
  typedef complex<CNumeric> complex_type;

  qpsk_ber_test BER_mon;
  quad_data<float_type>* tx_data_source;
  vco<float_type>* freq_offset;
  noise* n;
  qpsk<Numeric> RECEIVER;
  a_d* ADC;

  long num;
  float_type var;
  float_type snr;
  float_type timing_offset;
  long total_over;

  complex<float_type> base;
  complex<float_type> main;
  complex<float_type> b_noise;  // Noise
  complex<CNumeric> adc_out;
  long rcv_symbols;  //! Number of symbols decoded
  long count;        //! index of sample number at input rate
  float_type resample_over;
  float_type nominal_scale;
  float_type actual_over;
  float_type tx_time_inc;
  int rc_delay;
  long symbol_nco_word;

  long time;
  long freq;

  sim_qpsk(void) {
    snr = 6.0;
    timing_offset = 0.0;
    base = complex<float_type>(0, 0);
    rcv_symbols = 0;
    count = 0;
    resample_over = 0;
    tx_time_inc = 0;
    rc_delay = 0;
    symbol_nco_word = 0;
#ifdef NEWNOISE
    n = new noise;
#endif
    time = 0;
    freq = 0;
  }
  void loop_init(float_type actual, float_type time_offset = 0,
                 long adj_chan = 0) {
    actual_over = actual;
    total_over = (int)actual_over;  // Nearest integer oversampling rate
    // Timing Increment (in 1/total_over samples) for tx
    tx_time_inc = total_over / actual_over;
    resample_over = actual_over;
    var = sqrt(0.5 * actual_over) *
          pow(10.0, -0.05 * snr);  // Unfiltered noise std dev
    tx_data_source = new quad_data<float_type>(total_over);
    freq_offset = new vco<float_type>;
    ADC = new a_d(6);
#ifndef NEWNOISE
    n = new noise;
#endif
    tx_data_source->set_initial_offset(time_offset);
    freq_offset->reset_frequency(-TWOPI / (actual_over * 4000.0));

    BER_mon.reset();
    RECEIVER.reset();
    rcv_symbols = 0;  // Number of symbols decoded
    count = 0;        // index of sample number at input rate

    // QPSK Receiver Setup
    if (time)
      resample_over *= 1.0001;  // 100 ppm timing error (internal clock faster
                                // than reference)
    // This should be related to total_over + offset
    symbol_nco_word = (long)floor(resample_over * (1 << 14));
    //	RECEIVER.rate_change.symbol_nco.reset_frequency(symbol_nco_word);
  }
  // STEP
  complex<float_type> tx_step(void) {
    count++;
    // Get new sample from transmitter
    base = tx_data_source->get_sample(tx_time_inc);
    // Analog signal + noise + Up conversion
    if (freq) base *= freq_offset->clock();
    // Noise term
    b_noise = var * n->Cgauss();
    // Add noise
    base += b_noise;
    // AGC
    base *= 20;
    return (base);
  }
  void step(void) {
    complex<float_type> tmp = tx_step();
    adc_out = ADC->clock(tmp);
    rx_step(adc_out);
  }
  void rx_step(complex<CNumeric> sample) {
    // Clock IC
    RECEIVER.clock(sample);
    if (RECEIVER.symclk()) rcv_symbols++;
  }
  void loop_end(void) {
    delete tx_data_source;
    delete freq_offset;
    delete ADC;
#ifndef NEWNOISE
    delete n;
#endif
  }
};
}  // namespace SPUC
#endif
