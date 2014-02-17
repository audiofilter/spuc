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
	float_type snr=9.0;
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
	qpsk<long> Environment;
#else
	cout << "Using Template type DOUBLE/FLOAT\n";
	qpsk<float_type> Environment;
#endif
	long rcv_symbols=0;
	long symbols=0;

	time_t current_time;
	time(&current_time);
	noise random_offset;
	random_offset.set_seed(123);

	symbols = 0;

	Environment.data();

#ifdef _DEBUG
	sampf.close();
	resf.close();
#endif

	return(1);
} 
