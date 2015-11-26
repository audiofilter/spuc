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
#include <spuc/qpsk_variable.h>
namespace SPUC {
//! \file
//! \brief  A Class for simulating a variable rate QPSK system
//
//! that includes transmitters, receivers, frequency offsets,
//! gaussian noise, and a BER tester
//! Based on sim_qpsk with some minor changes.
//! \author Tony Kirke
//! \ingroup real_templates sim examples
template <class Numeric> class sim_qpsk_variable {
 public:
  typedef std::complex<Numeric> complex_type;

  qpsk_ber_test* BER_mon;
  quad_data<float_type>* tx_data_source;
  vco<float_type>* freq_offset;
  noise* n;
  qpsk_variable<Numeric>* RECEIVER;

  int64_t num;
  float_type var;
  float_type snr;
  float_type timing_offset;
  int64_t total_over;

  std::complex<float_type> data;
  std::complex<float_type> base;
  std::complex<float_type> main;
  std::complex<float_type> b_noise;  // Noise

  float_type sum_s;  // Signal sum for Es/No estimation
  float_type sum_n;  // Noise sum for Es/No estimation
  int64_t rcv_symbols;  // Number of symbols decoded
  int64_t count;        // index of sample number at input rate
  int dec_rate_log;
  float_type resample_over;
  // AGC stuff
  float_type agc_scale;
  float_type nominal_scale;
  float_type analog_agc;
  float_type analog_filter_gain;
  float_type analog_agc_gain;
  //

  float_type actual_over;
  float_type tx_time_inc;
  int rc_delay;
  int64_t symbol_nco_word;

  sim_qpsk_variable(void) {
    snr = 6.0;
    timing_offset = 0.0;
    data = std::complex<float_type>(1, 1);
    base = std::complex<float_type>(0, 0);
    rcv_symbols = 0;
    count = 0;
    dec_rate_log = 0;
    resample_over = 0;
    tx_time_inc = 0;
    rc_delay = 0;
    symbol_nco_word = 0;
    sum_s = sum_n = 0;
#ifdef NEWNOISE
    n = new noise;
#endif
  }
  void loop_init(float_type actual, float_type time_offset = 0) {
    //  void root_raised_cosine(fir<float_type> rcfir, float_type alpha, int rate);
    actual_over = actual;
    total_over = (int)actual_over;           // Nearest integer oversampling rate
    tx_time_inc = total_over / actual_over;  // Timing Inc (in 1/total_over samples) for tx
    dec_rate_log = (int)floor(log(actual_over / 2.0) / log(2.0));
    resample_over = actual_over / (1 << dec_rate_log);
    var = std::sqrt(0.5 * actual_over) * pow(10.0, -0.05 * snr);  // Unfiltered noise std dev
    BER_mon = new qpsk_ber_test;
    tx_data_source = new quad_data<float_type>(total_over);
    freq_offset = new vco<float_type>;
    RECEIVER = new qpsk_variable<Numeric>;
#ifndef NEWNOISE
    n = new noise;
#endif
    tx_data_source->set_initial_offset(time_offset);

    freq_offset->reset_frequency(-TWOPI / (actual_over * 1000.0));
    /////freq_offset->acc = -0.2783;
    // nominal_scale = 20.0*pow(actual_over,-0.2);
    nominal_scale = 20;         ///////////////////////////////
    agc_scale = nominal_scale;  // initialization
    analog_agc = 0;
    analog_agc_gain = 0.0002;
    analog_filter_gain = 1 - analog_agc_gain;

#ifdef _DEBUG
    sum_s = 0;  // Signal sum for Es/No estimation
    sum_n = 0;  // Noise sum for Es/No estimation
#endif
    rcv_symbols = 0;  // Number of symbols decoded
    count = 0;        // index of sample number at input rate

// QPSK Receiver Setup
#ifndef NOTIME
    resample_over *= 1.0001;  // 100 ppm timing error (internal clock faster than reference)
#endif
    symbol_nco_word = (int64_t)floor(resample_over * (1 << 14));  // This should be related to total_over + offset
    RECEIVER->rate_change.symbol_nco.reset_frequency(symbol_nco_word);
    // Change Carrier loop gain (from default) based on oversampling rate.
    RECEIVER->carrier_loop_filter.k0 -= dec_rate_log;
    RECEIVER->carrier_loop_filter.k1 -= dec_rate_log;
  }
  //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  void tx_step(void) {
    count++;
    // Get new sample from transmitter
    base = tx_data_source->get_sample(tx_time_inc);
// Analog signal + noise + Up conversion
#ifndef NOFREQ
    base *= freq_offset->clock();
#endif
    // Noise term
    b_noise = var * n->Cgauss();
// Statistics
#ifdef _DEBUG
    sum_s += magsq(base);
    sum_n += magsq(b_noise);
#endif
    // Add noise
    base += b_noise;
    // AGC
    base *= agc_scale;
  }
  void rx_step(std::complex<Numeric> b) {
    // Clock IC
    RECEIVER->clock(b);
    if (RECEIVER->symclk()) rcv_symbols++;
    // Analog AGC circuitry
    //  analog_agc = analog_filter_gain*analog_agc + analog_agc_gain*(2*RECEIVER->agc_out()-1);
    //  agc_scale += 0.01*analog_agc; // integrator!
  }
  void step(void) {
    tx_step();
    rx_step(base);
  }
  void loop_end(void) {
    //	BER_mon->final(rcv_symbols);
    delete BER_mon;
    delete tx_data_source;
    delete freq_offset;
#ifndef NEWNOISE
    delete n;
#endif
    delete RECEIVER;
  }
};
}  // namespace SPUC
