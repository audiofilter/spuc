#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_functions
#include <spuc/spuc_types.h>
#include <cmath>
#include <spuc/complex.h>
#include <vector>
namespace SPUC {
//! \file
//! \brief  Soft-decision QAM Demapper (used in 802.11A)
//
//! \brief  Soft-decision QAM Demapper (used in 802.11A)
//
//! Returns an array of soft decision bits, array size is dependant on modulation type
//! \author Tony Kirke
//!  \ingroup functions comm
void qam_data_demap(long rate_index, complex<long> data_in, long soft_decision_level, std::vector<long>& viterbi_input);
//! \brief BPSK data demapping
//! \author Tony Kirke
//!  \ingroup functions comm
void bpsk_soft_decision(complex<long> data_in, std::vector<long>& viterbi_input);
//! \brief QPSK data demapping
//! \author Tony Kirke
//! \ingroup functions comm
void qpsk_soft_decision(complex<long> data_in, std::vector<long>& viterbi_input);
//! \brief 16-QAM data demapping
//! \author Tony Kirke
//! \ingroup functions comm
void qam16_soft_decision(complex<long> data_in, long soft_decision_level, std::vector<long>& viterbi_input);
//! \brief 64-QAM data demapping
//! \author Tony Kirke
//! \ingroup functions comm
void qam64_soft_decision(complex<long> data_in, long soft_decision_level, std::vector<long>& viterbi_input);
}  // namespace SPUC
