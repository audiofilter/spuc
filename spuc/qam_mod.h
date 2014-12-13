#ifndef SPUC_QAM_MOD
#define SPUC_QAM_MOD

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
// from directory: spuc_classes
#include <spuc/spuc_types.h>
#include <cmath>
#include <spuc/complex.h>
namespace SPUC {
//! \file
//! \brief   QAM Modulator for BPSK - 64 QAM for 802.11A Data modulation
//
//! \brief   QAM Modulator for BPSK - 64 QAM for 802.11A Data modulation
//! \author Tony Kirke
//! \image html qam_mod.png
//! \ingroup classes comm modulators
class qam_mod {
 public:
  long rate_index;  // 0 BPSK, Max for highest QAM, etc

 public:
  // Constructor (with default data rate)
  qam_mod(int index) { rate_index = index; }
  ~qam_mod() {}
  complex<long> data_map(long r_ind, long data_in);
  complex<long> bpsk_map(long data_in);
  complex<long> qpsk_map(long data_in);
  complex<long> qam16_map(long data_in);
  complex<long> qam64_map(long data_in);
};
}  // namespace SPUC
#endif
