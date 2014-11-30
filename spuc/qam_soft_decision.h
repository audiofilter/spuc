#ifndef SPUC_QAM_SOFT_DECISION
#define SPUC_QAM_SOFT_DECISION

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
// from directory: spuc_functions
#include <spuc/spuc_types.h>
#include <cmath>
#include <spuc/complex.h>
#include <spuc/smart_array.h>
namespace SPUC {
//! \file
//! \brief  Soft-decision QAM Demapper (used in 802.11A)
//
//! \brief  Soft-decision QAM Demapper (used in 802.11A)
//
//! Returns an array of soft decision bits, array size is dependant on modulation type
//! \author Tony Kirke
//!  \ingroup functions comm
void qam_data_demap(long rate_index, complex<long> data_in,
					long soft_decision_level, smart_array<long>& viterbi_input);
//! \brief BPSK data demapping
//! \author Tony Kirke
//!  \ingroup functions comm
void bpsk_soft_decision(complex<long> data_in, smart_array<long>& viterbi_input);
//! \brief QPSK data demapping
//! \author Tony Kirke
//! \ingroup functions comm
void qpsk_soft_decision(complex<long> data_in, smart_array<long>& viterbi_input);
//! \brief 16-QAM data demapping
//! \author Tony Kirke
//! \ingroup functions comm
void qam16_soft_decision(complex<long> data_in, long soft_decision_level, smart_array<long>& viterbi_input);
//! \brief 64-QAM data demapping
//! \author Tony Kirke
//! \ingroup functions comm
void qam64_soft_decision(complex<long> data_in, long soft_decision_level, smart_array<long>& viterbi_input);
} // namespace SPUC
#endif
