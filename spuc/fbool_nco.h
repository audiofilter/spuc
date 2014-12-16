#ifndef SPUC_FBOOL_NCO
#define SPUC_FBOOL_NCO

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
template <int M, int L = 12> class fbool_nco {
 public:
  bool phase;
  //  char v[20];

 protected:
  uint<M> acc;
  uint<M> fcw;
  uint<M> new_fcw;

 public:
  fbool_nco() { acc = fcw = new_fcw = 0; }
  inline void set_frequency(uint<M> freq) { fcw = freq; }
  inline void reset_frequency(uint<M> freq) { new_fcw = fcw = freq; }
  inline bool get_phase(void) { return (phase); }
  inline void load(uint<L> loop_filter_out) { new_fcw = fcw + loop_filter_out; }
  bool clock() {
    acc = acc + new_fcw;
    phase = acc.overflow;
    return (phase);
  }
  bool clock(uint<L> loop_filter_out) {
    new_fcw = fcw + loop_filter_out;
    return (clock());
  }
};
// template_instantiations: 5
}  // namespace SPUC
#endif
