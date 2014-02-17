// Copyright (c) 1993-2005 Tony Kirke
/*
 * SPUC - Signal processing using C++ - A DSP library
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
*/
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <spuc/complex.h>
#include <spuc/sim_qpsk.h>
#include <spuc/noise.h>
#ifdef DUMP
#include <spuc/dump.hpp>
#endif

#define SYM_LOOP_ON 10
#define CAR_LOOP_ON 1000
#define WAITSYMBOLS 2900
using namespace std;
using namespace SPUC;
//!
//!  \brief Simulation of QPSK receiver in AWGN
//
//!  \ingroup sim examples
int main(int argc, char *argv[])
{                        
#ifdef _DEBUG
	ofstream sampf("samp.dat");
	ofstream resf("res.dat");
#endif
	long num;
	float_type snr=12.0;
	float_type timing_offset=0.0;

	if (argc<3) {
	  num = 60000;
	} else if (argc!=3) {
	  cout << "Performs QPSK BER simulation\n.";
	  cout << "Usage: QPSK <Symbols> <NP>\n";
	  cout << "Where <Symbols> is the number of symbols used for BER measurement\n";
	  cout << "and <NP> is the approximate Es/No at input to A/D dB\n";
	  exit (0);
	} else {
	  num = ((long)atof(argv[1]));       // Number of symbols simulated 
	  snr = atof(argv[2]);   // Unfiltered noise std dev	
	}

	float_type actual_over=2.00;
#ifdef USEFP
	cout << "Using Template type LONG\n";
	sim_qpsk<long> Environment;
#else
	cout << "Using Template type DOUBLE/FLOAT\n";
	sim_qpsk<float_type> Environment;
#endif
	//	long rcv_symbols=0;
	long symbols=0;

	Environment.num = num;
	Environment.snr = snr;

	time_t current_time;
	time(&current_time);
	noise random_offset;
#ifdef NORAND
	random_offset.set_seed(123);
#else
	random_offset.set_seed((long)(current_time*10));
#endif
#ifndef NOOFFSET
	// Only use positive timing offsets for now
	timing_offset = 0.5*random_offset.uni()*actual_over;
	//	timing_offset = 0.1;
#endif

#ifndef NOTIME
	Environment.time = 1;
#else
	Environment.time = 0;
#endif
#ifndef NOFREQ
	Environment.freq = 1;
#else
	Environment.freq = 0;
#endif

	Environment.loop_init(actual_over, timing_offset);
	Environment.BER_mon.init_delay(68); // makes correlation occur earlier
	symbols = 0;

	// MAIN LOOP
	do {
	  Environment.step();

#ifdef _DEBUG
	  resf << real(Environment.RECEIVER.baseband) << '\n';
#endif

#ifndef NOTIME
	  if (Environment.rcv_symbols == SYM_LOOP_ON) 
		Environment.RECEIVER.symbol_loop_filter.k0_en = 1;
#endif
#ifndef NOFREQC
	  if (Environment.rcv_symbols == CAR_LOOP_ON) {
		Environment.RECEIVER.carrier_loop_filter.k1_en = 
		  Environment.RECEIVER.carrier_loop_filter.k0_en = 1;
	  }
#endif

	  if (Environment.RECEIVER.symclk()==1) {
		if (Environment.rcv_symbols > WAITSYMBOLS )  {                    
		  // Get I,Q data output from Chip
		  complex<long> data = Environment.RECEIVER.data();  
		  Environment.BER_mon.synchronize(&symbols,data);
		  // Correlate with reference PN
		  if (Environment.BER_mon.found_sync()) Environment.BER_mon.ber_results(symbols++); 
		  else symbols++;
		}
		// DEBUG		
#ifdef _DEBUG	
		sampf << (Environment.RECEIVER.carrier_error) << ' ';
		sampf << (Environment.RECEIVER.carrier_loop_out) << ' ';
		sampf << (Environment.RECEIVER.symbol_loop_out) << ' ';
		sampf << real(Environment.RECEIVER.final_baseband) << ' ';
		sampf << '\n';
#endif
		// END DEBUG
	  }  				 
	  if (Environment.rcv_symbols > num && !Environment.BER_mon.found_sync()) break;
	} while (symbols < num);

	Environment.BER_mon.final_results(symbols);
	Environment.loop_end();

#ifdef _DEBUG
	sampf.close();
	resf.close();
#endif

#ifdef DUMP
	dump(Environment,"Environment");
#endif

	return(1);
} 
