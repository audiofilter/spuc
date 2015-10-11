#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_classes
#include <spuc/spuc_types.h>
#define POLYA 0x6d
#define POLYB 0x4f
namespace SPUC {
//
#ifndef DOXYGEN_SHOULD_SKIP_THIS
class viterbi_state {
 public:
  unsigned long path; /* Decoded path to this state */
  long metric;        /* Cumulative metric to this state */
};
#endif
//! \file
//! \brief A Viterbi decoder (for DVB)
//
//! \brief A Viterbi decoder (for DVB)
//
//! The two generator polynomials for the NASA Standard K=7 code.
//! Since these polynomials are known to be optimal for this constraint
//! length there is not much point in changing them. But if you do, you
//! will have to regenerate the BUTTERFLY macro calls in viterbi()
//! \author Tony Kirke,  Copyright(c) 2001
//! \author Tony Kirke
//! \ingroup classes comm fec
class viterbi {
 public:
  bool decoded;
  bool enable_output;
  bool output_ready;
  long prev_value;
  viterbi_state *state0, *state1, *state, *next;
  int bitcnt;
  int beststate;
  long depuncture_bit_number;
  bool phase;

  viterbi() {
    viterbi_state* state0 = new viterbi_state[64];
    viterbi_state* state1 = new viterbi_state[64];
    state = state0;
    next = state1;
    reset();
    for (int i = 0; i < 64; i++) state[i].metric = -999999;
    state[0].path = 0;
  }
  void reset() {
    phase = 0;
    depuncture_bit_number = 0;
    decoded = 1;
    output_ready = 0;
    enable_output = 0;
    bitcnt = 0;
    prev_value = 0;
    beststate = 0;
    state = state0;
    next = state1;
    // Initialize starting metrics
    // ...no longer prefer 0 state
    for (int i = 0; i < 64; i++) {
      state0[i].metric = -999999;
      state1[i].metric = -999999;
      state0[i].path = 0;
      state1[i].path = 0;
    }
  }
  bool clock(long value) {
    bool z = false;
    decoded = !decoded;
    if (decoded) z = decode(prev_value, value);
    prev_value = value;
    if (enable_output) output_ready = decoded;
    return (z);
  }
  bool decode(long s0, long s1);
  void minimize_metrics() {
    long bestmetric = state[beststate].metric;
    for (int i = 0; i < 64; i++) { state[i].metric -= bestmetric; }
  }
  bool depuncture(const long steal, long soft_in);
};
}  // namespace SPUC
