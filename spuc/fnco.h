#ifndef SPUC_FNCO
#define SPUC_FNCO

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
template <int M>
class fnco {
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
