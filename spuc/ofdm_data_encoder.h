#ifndef SPUC_OFDM_DATA_ENCODER
#define SPUC_OFDM_DATA_ENCODER

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
#include <spuc/bit_scrambler.h>
#include <spuc/data_conv_encoder.h>
#include <spuc/qam_mod.h>
#include <spuc/smart_array.h>
namespace SPUC {
//! \file
//! \brief  OFDM/802.11A/G Data Encoder 
//
//! \brief  OFDM/802.11A/G Data Encoder 
//
//!   Uses data_conv_encoder and qam_mod classes
//! \author Tony Kirke
//! \ingroup classes comm
class ofdm_data_encoder 
{
public:
	data_conv_encoder CONV;
	qam_mod QAM;
	long rate_index; // 0 BPSK, Max for highest QAM, etc
	long enc_rate;
	long tx_bits_per_symbol;
	long total_bits;
	long number_symbols;
	long frame;
	long serial;
	long sample;
	long data_index;
	bool raw_bit; // current input data bit
	const long Carriers;
	smart_array<bool> raw_data;
	smart_array<bool> interleaver_in;
	smart_array<bool> interleaved;
	smart_array<bool> interleaver_out;
	smart_array<long> pre_mod;

 private:
	smart_array<bool> interleave(smart_array<bool> data_in); 

 public:
	int coded_bits_per_frame;
	int raw_bits_this_frame;
	bool no_conv;
	
	// Constructor (with default data rate)
	ofdm_data_encoder(int index, int T_fft, int D_carriers,
					  int max_range) :
	  CONV(index, T_fft), QAM(index), Carriers(D_carriers),
	  raw_data(16*T_fft), interleaver_in(max_range*T_fft),
	  interleaved(max_range*T_fft), pre_mod(Carriers)  {
	  rate_index = index;
	}
	// Determine number of OFDM symbol (must be called AFTER set_rate())
    long tx_burst_size(long bytes) {
		number_symbols = (8*bytes+6+coded_bits_per_frame+1)/coded_bits_per_frame;
		total_bits = number_symbols*coded_bits_per_frame;
		return(total_bits);
	}
	void reset() { // clear variables for next burst
		serial = 0;
		sample = 0;
		frame = 0;
		raw_bit=0;
		coded_bits_per_frame=0;
		raw_bits_this_frame=0;
		tx_bits_per_symbol = 0;
		data_index = 0;
	}
	~ofdm_data_encoder() {
	} 
	void set_rate(int mod, int conv_rate) {
		if (conv_rate == 0) no_conv = 1;
		else no_conv = 0;
		enc_rate = conv_rate;
		if (mod>0) tx_bits_per_symbol = 2*mod;
		else tx_bits_per_symbol = 1;
	}
	complex<long> data_map(long rate);
	
	void get_data_frame();
	void serial_to_word_input(bool in);
	long serial_to_word_output(void);
};
} // namespace SPUC
#endif
