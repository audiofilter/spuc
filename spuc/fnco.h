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
template <int M> class fnco {
 public:
  spuc_uint<M> phase;

 protected:
  spuc_uint<M> fcw;
  spuc_uint<M> new_fcw;

 public:
  fnco() { fcw = new_fcw = phase = 0; }
  inline void set_frequency(spuc_uint<M> freq) { fcw = freq; }
  inline void reset_frequency(spuc_uint<M> freq) { new_fcw = fcw = freq; }
  inline spuc_uint<M> get_phase(void) { return (phase); }
  inline void load(spuc_uint<M> loop_filter_out) { new_fcw = fcw + loop_filter_out; }
  spuc_uint<M> clock(spuc_uint<M> loop_filter_out) {
    new_fcw = fcw + loop_filter_out;
    return (clock());
  }
  spuc_uint<M> clock() {
    phase += new_fcw;
    return (phase);
  }
};
// template_instantiations: 5
}  // namespace SPUC
