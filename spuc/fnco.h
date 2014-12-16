#ifndef SPUC_FNCO
#define SPUC_FNCO

// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_n_templates
#include <spuc/spuc_types.h>
#include <spuc/uint.h>
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
  uint<M> phase;
  //  char v[20];

 protected:
  uint<M> fcw;
  uint<M> new_fcw;

 public:
  fnco() { fcw = new_fcw = phase = 0; }
  inline void set_frequency(uint<M> freq) { fcw = freq; }
  inline void reset_frequency(uint<M> freq) { new_fcw = fcw = freq; }
  inline uint<M> get_phase(void) { return (phase); }
  inline void load(uint<M> loop_filter_out) { new_fcw = fcw + loop_filter_out; }
  uint<M> clock(uint<M> loop_filter_out) {
    new_fcw = fcw + loop_filter_out;
    return (clock());
  }
  uint<M> clock() {
    phase += new_fcw;
    return (phase);
  }
};
// template_instantiations: 5
}  // namespace SPUC
#endif
