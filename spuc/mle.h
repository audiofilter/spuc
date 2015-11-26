#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_templates
#include <spuc/spuc_types.h>
#include <cmath>
#include <spuc/complex.h>
#include <spuc/delay.h>
#include <spuce/filters/fir_adapt.h>
namespace SPUC {
//! \file
//! \brief A Configurable Maximum Likelihood Sequence Estimator Class
//
//! \brief A Configurable Maximum Likelihood Sequence Estimator Class
//
//! can be configured as either a
//!
//! <p>MLSD - Basic Maximum Likelihood Sequence Detector
//! <p>DDFSE - MLSD with Delayed Decision Feedback Sequence Detector
//! <p>RSDFSE - MLSD with Reduced State Decision Feedback Sequence Detector
//! \author Tony Kirke
//! \ingroup templates equalizers
//! \author Tony Kirke
//! \ingroup templates comm
template <class Numeric> class mle {
 public:
  const long mlsd_span;              //! number of bits spanned by MLSD part of equaliser
  const long dfe_span;               //! Number of bits spanned by DFE part of equaliser
  const long n_states;               //! Number of states
  const long n_branches;             //! Number of branches
  Numeric fb_est;                    //! Feedback estimator for RSDFSE
  spuce::fir_adapt<Numeric, Numeric> cfir;  //! Channel impulse response
  std::vector<Numeric> cir_mlsd;
  std::vector<Numeric> cir_dfe;
  std::vector<Numeric> f_est;  //! Feedforward
  std::vector<Numeric> b_est;
  std::vector<float_type> weight;      //! state metric calculations/state
  std::vector<long> path;              //! path history
  std::vector<long> tmp_path;          // Temporary variable
  std::vector<float_type> tmp_weight;  // Temporary variable
  std::vector<long> path_symbol;
  long phase_states;     //! Phase states for MLSD_CPM (not implemented)
  long total_states;     //! for CPM total = n_states*phase_states! (not implemented)
  float_type phase_inc;  //! phase increment for MLSD_CPM (should divide evenly into 360 degrees) (not implemented)

  //! Constructor (default to MLSE with no feedback)
  //! q=1 Binary, q=2 Quaternary
  mle(int mlsd_size, int dfe_size = 0, long q = 1)
      : mlsd_span(mlsd_size + 1),
        dfe_span(dfe_size),
        n_states(1 << (q * mlsd_size)),
        n_branches(2 * q * n_states),
        cir_mlsd(mlsd_span),
        cir_dfe(dfe_span),
        f_est(n_branches),
        b_est(n_states),
        weight(n_states),
        path(n_states),
        tmp_path(n_states),
        tmp_weight(n_states),
        path_symbol(n_states) {
    cfir.set_size(mlsd_span);
    for (int i = 0; i < n_states; i++) {
      path_symbol[i] = 0;
      path[i] = 0;
      weight[i] = 0;
    }
    fb_est = (Numeric)0;
  }
  ~mle(void) {}
  //! Reset filter
  void reset() { cfir.reset(); }
  //! Update coefficients
  void update_taps_lms(Numeric err) { cfir.update_lms(err); }
  //! Get tap0
  Numeric tap0(void) { return (cfir.gettap(0)); }
  //! Copy channel impulse response
  void set_cir(const spuce::fir<Numeric, Numeric>& cir) {
    int i;
    for (i = 0; i < mlsd_span; i++) cir_mlsd[i] = cir.gettap(i);
    for (i = 0; i < dfe_span; i++) {
        if (i + mlsd_span < cir.number_of_taps())
          cir_dfe[i] = cir.gettap(mlsd_span + i);
      else
        cir_dfe[i] = (Numeric)0;
    }
  }
  //! Calculate convolution of feedback taps with past decisions for a
  //! particular state (for next iteration of branch metric calculation)
  Numeric df_est(int state) {
    int pnt, i;
    Numeric est(0);
    pnt = 0x1;
    for (i = 0; i < dfe_span; i++) {
      if ((path[state] & pnt) != 0)
        est = est + cir_dfe[i];
      else
        est = est - cir_dfe[i];
      pnt <<= 1;
    }
    return (est);
  }
  //! Feedforward estimates
  Numeric ff_estimate(long seq) {
    int j, i;
    long num_taps = mlsd_span;
    Numeric pred(0);
    j = (0x1 << num_taps);
    for (i = 0; i < num_taps; i++) {
      j >>= 1;
      if ((seq & j) != 0)
          pred = pred + cfir.gettap(i);
      else
          pred = pred - cfir.gettap(i);
    }
    return (pred);
  }
  //! Allows selection of Equalizer type
  float_type estimate(Numeric rx, long seq, long state, long type) {
    Numeric y;
    if (type == 1) {  // RSDFE
      y = ff_estimate(seq) + fb_est;
      return (magsq(y - rx));
    } else if (type == 2) {  // DDFSE
      y = ff_estimate(seq) + b_est[state];
      return (magsq(y - rx));
    } else {  // MLSD
      y = ff_estimate(seq);
      return (magsq(y - rx));
    }
  }
  //! Perform DDFSE Sequence detection
  long ddfse(Numeric rx) { return (equalize(rx, 2)); }
  //! Perform MLSD Sequence detection
  long mlsd(Numeric rx) { return (equalize(rx, 0)); }
  //! Perform RSDFSE Sequence detection
  long rsdfse(Numeric rx) { return (equalize(rx, 1)); }
  //! Generic Sequence detection allowing selection of type
  long equalize(Numeric rx, long type) {
    float_type temp0, temp1;
    long ex_state0, ex_state1;
    long old_state0, old_state1;
    float_type metric0, metric1;
    float_type min_weight;
    long path_state;
    int i;
    for (i = 0; i < n_states; i++) {
      // 0 transition
      ex_state0 = (i << 1);
      // previous state assuming 0 transition
      metric0 = estimate(rx, ex_state0, i, type);
      old_state0 = ex_state0 % n_states;
      temp0 = weight[old_state0] + metric0;
      // 1 transition
      ex_state1 = ex_state0 + 1;
      // previous state assuming 1 transition
      metric1 = estimate(rx, ex_state1, i + n_states, type);
      old_state1 = ex_state1 % n_states;
      temp1 = weight[old_state1] + metric1;
      if (temp0 < temp1) {
        tmp_weight[i] = temp0;
        tmp_path[i] = (path[old_state0] << 1);
      } else {
        tmp_weight[i] = temp1;
        tmp_path[i] = (path[old_state1] << 1) | 0x1;
      }
    }
    // get minimum weight for all the
    // states and return the path data
    // for this minimum weight
    // Also, store new weights and paths
    // for all states
    min_weight = tmp_weight[0];
    path_state = 0;
    for (i = 0; i < n_states; i++) {
      if (tmp_weight[i] < min_weight) {
        min_weight = tmp_weight[i];
        path_state = i;
      }
      // store for next iteration
      weight[i] = tmp_weight[i];
      path[i] = tmp_path[i];
      b_est[i] = df_est(i);         // for ddfse
      fb_est = df_est(path_state);  // for rsdfse
    }
    return (path[path_state]);
  }
};
}  // namespace SPUC
