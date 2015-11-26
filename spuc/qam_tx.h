#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_real_templates
#include <spuc/spuc_types.h>
#include <cmath>
#include <spuc/spuc_defines.h>
#include <spuc/complex.h>
#include <spuc/max_pn.h>
#include <spuc/fading_channel.h>
#include <spuc/root_raised_cosine.h>
#include <spuc/fir_coeff.h>
#include <spuc/fir_interp.h>
#include <spuc/qam_mod.h>
#include <spuc/spuc_math.h>
#include <spuc/builtin.h>
namespace SPUC {
//! \file
//! \brief  Class for QAM transmitter using a root raised cosine transmit filter
//
//! \author Tony Kirke
//! \image html qam_tx.png
//!  \ingroup real_templates comm modulators
template <class Numeric> class qam_tx {
 public:
  float_type alpha;
  max_pn training_source;
  qam_mod ENC;
  fir_interp<complex<Numeric>, Numeric> tx_filter;
  max_pn preamble_source;
  complex<Numeric> tx_data;
  float_type data_level;
  long preamble_pn;  // Number of symbols used for pre-amble PN
  long training_interval;
  long tx_symbols;  // Counter for transmitted symbols
  long over;        // Oversampling rate
  Numeric training_scale;
  long count;
  long rate;

  //----------------------------------------------------------------------------
  // Constructor!
  //---------------------------------------------------------------------------
  qam_tx(long sym_sp = 5, long over_sam = 8, long mod_rate = 0, long conv_rate = 0, float_type rc_alpha = 0.25)
      : alpha(rc_alpha), training_source(0x074d, 1023, -1), ENC(3), tx_filter(sym_sp * over_sam + 1), rate(mod_rate) {
    preamble_pn = 63 * 4;
    training_interval = 2048;
    over = over_sam;
    loop_init(mod_rate, conv_rate);
  }
  void loop_init(long mod_rate, long conv_rate) {
    tx_data = 0;
    tx_symbols = 0;  // Counter for transmitted symbols
    rate = mod_rate;

    preamble_source.reset();
    ENC.rate_index = rate;
    if (rate == 0) {
      data_level = 1;  // BPSK
      training_scale = 1;
    } else if (rate == 1) {
      data_level = sqrt(0.5);  // QPSK
      training_scale = 1;
    } else if (rate == 2) {
      data_level = sqrt(0.1);
      training_scale = 3;
    } else if (rate == 3) {
      data_level = sqrt(1.0 / 42.0);
      training_scale = 5;
    } else {
      data_level = 1;
      training_scale = 1;
    }

#ifdef NORM
    data_level = 1;
#endif

    tx_filter.reset();
    tx_filter.set_rate(over);
    tx_filter.set_automatic();
    //! alpha = 0.35 root raised cosine fir
    fir_coeff<Numeric> fir_c(tx_filter.number_of_taps());
    root_raised_cosine(fir_c, alpha, over);
    tx_filter.settaps(fir_c);

    //  float_type scale  = sqrt(1.0); ///float_type(over));
    //  for (int j=0;j<tx_filter.num_taps;j++) { tx_filter.coeff[j] *= scale; }

    tx_symbols = 0;
    count = 0;
    training_source.reset();
  }
  //---------------------------------------------------------------------------
  // STEP
  //---------------------------------------------------------------------------
  complex<Numeric> clock() {
    // Get new sample from transmitter
    if (count++ % over == 0) {
      if (tx_symbols < preamble_pn) {
        // Preamble is not scaled!!!
        tx_data = complex<Numeric>(preamble_source.out(), 0);
      } else if (tx_symbols < training_interval + preamble_pn) {
        tx_data = training_scale * complex<Numeric>(training_source.out(), 0);
      } else {
        tx_data = ENC.data_map(rate, 0);
      }
      tx_symbols++;
      tx_filter.input(tx_data);
    }
    return (tx_filter.clock());
  }
};
}  // namespace SPUC
