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
#include <stdio.h>
//#include <stdlib.h>
#include <spuc/spuc_math.h>
#include <spuc/sim_qpsk_variable.h>
#include <spuc/noise.h>
#define SYM_LOOP_ON 10
#define CAR_LOOP_ON 1000
#define WAITSYMBOLS 15000
using ::std::ofstream;
using ::std::cout;
//using SPUC::sim_qpsk_variable;
//using SPUC::noise;
//using SPUC::complex;
using namespace SPUC;
int main(int argc, char *argv[])
{                        
#ifdef _DEBUG
  ofstream resultf("result.dat");
  ofstream sampf("samp.dat");
#endif
  long num;
  double snr=9.0;
  double timing_offset=0.0;

  if (argc<3) {
	num = 60000;
  } else if (argc!=3) {
	cout << "Performs QPSK BER simulation.";
	cout << "Usage: QPSK <Symbols> <NP>";
	cout << "Where <Symbols> is the number of symbols used for BER measurement";
	cout << "and <NP> is the approximate Es/No at input to A/D dB";
	exit (0);
  } else {
	num = ((long)atof(argv[1]));       // Number of symbols simulated 
	snr = atof(argv[2]);   // Unfiltered noise std dev	
  }

  // Test & I/O setup
  sim_qpsk_variable<long> Environment;
  double actual_over;
  //  long rcv_symbols=0;
  long symbols=0;
  long sig=0;
  long QPSK_symbol_locked=0;
  
  Environment.num = num;
  Environment.snr = snr;

  time_t current_time;
  time(&current_time);
  noise random_offset;
  random_offset.set_seed((unsigned)(current_time*10));
	
  actual_over = 2.1;

#ifdef _DEBUG
  printf("rate\toffset\tEs/No\tBER\tSymbols\tErrors\tTime\n"); 
#else
  printf("rate\toffset\tBER\tSymbols\tErrors\tTime\n"); 
#endif

  sig = 0;
#ifndef NOOFFSET
  // Only use positive timing offsets for now
  timing_offset = 0.5*random_offset.uni()*actual_over;
#endif

  Environment.loop_init(actual_over, timing_offset);
  Environment.BER_mon->init_delay(69); // makes correlation occur earlier

  symbols = 0;
  //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  //			BEGIN MAIN LOOP
  //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  do {
	Environment.step();
#ifdef _xDEBUG
	sampf << real(Environment.base) << ' ';
	sampf << real(Environment.RECEIVER->adc_out) << ' ';
	sampf << Environment.agc_scale << '\n';
#endif

	if (Environment.RECEIVER->symbol_locked != QPSK_symbol_locked) {
	  if (QPSK_symbol_locked) {
		std::cout << "Loss of symbol lock at symbol " << Environment.rcv_symbols;
	  } else {
		std::cout << "Symbol lock declared at symbol " << Environment.rcv_symbols;
	  }
	  QPSK_symbol_locked = Environment.RECEIVER->symbol_locked;
	}
	
#ifndef NOTIME
	  if (Environment.rcv_symbols == SYM_LOOP_ON) 
		Environment.RECEIVER->symbol_loop_filter.k0_en = 1;
#endif
#ifndef NOFREQ
	if (Environment.rcv_symbols == CAR_LOOP_ON) {
	  Environment.RECEIVER->carrier_loop_filter.k0_en = 
		Environment.RECEIVER->carrier_loop_filter.k1_en = 1;
	}
#endif

	if (Environment.RECEIVER->symclk()==1) {
#ifdef _xDEBUG
	  if (Environment.RECEIVER->symbol_lock_detect.count == 0) {
		resultf << Environment.RECEIVER->symbol_lock_detect.output() << '\n';
	  }
#endif
	  if (Environment.rcv_symbols > WAITSYMBOLS
		  || Environment.BER_mon->found_sync())  {                    
		complex<long> data = Environment.RECEIVER->data();  
		// Get I,Q data output from Chip
		Environment.BER_mon->synchronize(&Environment.rcv_symbols,data);
		// Correlate with reference PN
		if (Environment.BER_mon->found_sync()) {		
		  if (actual_over > .8) Environment.BER_mon->ber_results(symbols++); 
		}
	  }
	  // DEBUG		
#ifdef _wDEBUG	
		sampf << (Environment.RECEIVER->timing_error) << ' ';
		sampf << (Environment.RECEIVER->nda_timing_error) << ' ';
		sampf << (Environment.RECEIVER->symbol_loop_out) << ' ';
		sampf << re(Environment.RECEIVER->resampled) << ' ';
		//	sampf << re(Environment.RECEIVER->mf_out) << ' ';
		sampf << (Environment.RECEIVER->carrier_error) << ' ';
		sampf << (Environment.RECEIVER->carrier_loop_out) << ' ';
		sampf << (Environment.RECEIVER->symbol_loop_out) << ' ';
		sampf << real(Environment.RECEIVER->final_baseband) << ' ';
		sampf << '\n';
#endif
	  if (symbols > WAITSYMBOLS) {
		sig += magsq(Environment.RECEIVER->final_baseband);
	  }
	  // END DEBUG
	}  				 
	if (Environment.rcv_symbols > num && !Environment.BER_mon->found_sync()) break;
  } while (symbols < num);

  printf("%g\t%5.3f",actual_over,timing_offset); 
#ifdef _DEBUG
  printf("\t%4.2f",10*log10(4.0*Environment.sum_s/(2.0*Environment.sum_n))); 
#endif
  Environment.BER_mon->final_results(symbols);
  Environment.loop_end();
  printf("Sig level = %g\n",::sqrt((double)0.5*sig/(symbols-WAITSYMBOLS)));

#ifdef _DEBUG
  resultf.close();
  sampf.close();
#endif
	return(1);
} // namespace SPUC
