#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_n_templates
#include <spuc/spuc_types.h>
#include <spuc/spuc_uint.h>
namespace SPUC {
//! \file
//! \brief Template class for a NCO based on template unsigned int class
//
//! \brief Template class for a NCO based on template unsigned int class
//
//! \author Tony Kirke
//! \ingroup n_templates sim
template <int M, int L = 12> class fbool_nco {
 public:
  bool phase;
  //  char v[20];

 protected:
  spuc_uint<M> acc;
  spuc_uint<M> fcw;
  spuc_uint<M> new_fcw;

 public:
  fbool_nco() { acc = fcw = new_fcw = 0; }
  inline void set_frequency(spuc_uint<M> freq) { fcw = freq; }
  inline void reset_frequency(spuc_uint<M> freq) { new_fcw = fcw = freq; }
  inline bool get_phase(void) { return (phase); }
  inline void load(spuc_uint<L> loop_filter_out) { new_fcw = fcw + loop_filter_out; }
  bool clock() {
    acc = acc + new_fcw;
    phase = 0; ///acc.overflow;
    return (phase);
  }
  bool clock(spuc_uint<L> loop_filter_out) {
    new_fcw = fcw + loop_filter_out;
    return (clock());
  }
};
// template_instantiations: 5
}  // namespace SPUC
