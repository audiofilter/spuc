#ifndef SPUC_FBOOL_NCO
#define SPUC_FBOOL_NCO

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
template <int M, int L=12> class fbool_nco
{
 public:
  bool phase;
//  char v[20];

  protected:
  uint<M> acc;
  uint<M> fcw;
  uint<M> new_fcw;

public:
    fbool_nco() { acc = fcw = new_fcw = 0;}
	inline void set_frequency(uint<M> freq) { fcw = freq; }
	inline void reset_frequency(uint<M> freq) { new_fcw = fcw = freq; }
	inline bool get_phase(void) { return(phase);}
	inline void load(uint<L> loop_filter_out) {new_fcw = fcw + loop_filter_out;}
	bool clock() {
		acc = acc + new_fcw;
		phase = acc.overflow;
		return(phase);
	}
	bool clock(uint<L> loop_filter_out) {
	new_fcw = fcw + loop_filter_out;
	return(clock());
	}
};
// template_instantiations: 5
} // namespace SPUC
#endif
