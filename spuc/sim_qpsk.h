#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
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
template <class Numeric> class sim_qpsk {
 public:
  typedef std::complex<Numeric> complex_type;

  qpsk_ber_test BER_mon;
  quad_data<float_type>* tx_data_source;
  vco<float_type>* freq_offset;
  noise* n;
  qpsk<Numeric> RECEIVER;
  a_d* ADC;

  int64_t num;
  float_type var;
  float_type snr;
  float_type timing_offset;
  int64_t total_over;

  std::complex<float_type> base;
  std::complex<float_type> main;
  std::complex<float_type> b_noise;  // Noise
  std::complex<Numeric> adc_out;
  int64_t rcv_symbols;  //! Number of symbols decoded
  int64_t count;        //! index of sample number at input rate
  float_type resample_over;
  float_type nominal_scale;
  float_type actual_over;
  float_type tx_time_inc;
  int rc_delay;
  int64_t symbol_nco_word;

  int64_t time;
  int64_t freq;

  sim_qpsk(void) {
    snr = 6.0;
    timing_offset = 0.0;
    base = std::complex<float_type>(0, 0);
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
  void loop_init(float_type actual, float_type time_offset = 0, int64_t adj_chan = 0) {
    actual_over = actual;
    total_over = (int)actual_over;  // Nearest integer oversampling rate
    // Timing Increment (in 1/total_over samples) for tx
    tx_time_inc = total_over / actual_over;
    resample_over = actual_over;
    var = std::sqrt(0.5 * actual_over) * pow(10.0, -0.05 * snr);  // Unfiltered noise std dev
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
    if (time) resample_over *= 1.0001;  // 100 ppm timing error (internal clock faster than reference)
    // This should be related to total_over + offset
    symbol_nco_word = (int64_t)floor(resample_over * (1 << 14));
    //	RECEIVER.rate_change.symbol_nco.reset_frequency(symbol_nco_word);
  }
  // STEP
  std::complex<float_type> tx_step(void) {
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
    std::complex<float_type> tmp = tx_step();
    adc_out = ADC->clock(tmp);
    rx_step(adc_out);
  }
  void rx_step(std::complex<Numeric> sample) {
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
