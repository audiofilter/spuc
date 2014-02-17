// Copyright (c) 1993-2005 Tony Kirke
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <stdlib.h>
#include <spuc/complex.h>
#include <spuc/baud_eq_env.h>
#include <spuc/noise.h>
#include <iomanip>
using namespace SPUC;
#define EQTYPE 0
//! \brief  Baud rate equalization simulation
//
//!  BPSK (real) data is corrupted with a multipath channel
//!  (delay spread = baud rate?) with L (programmable) number of taps
//!  Noise is added and this program generates BER data over a 
//!  range of SNR points with a
//!  MLSE (Viterbi) Equalizer with 2^L states
//! TYPE 1 == DDFSE
//! \ingroup examples
int main(int argc, char *argv[])
{                        
	ofstream resf("res.dat");
#ifdef HIST
	histf("paths.dat");
#endif
	long num;
	long loops=2;
	long delay = 8; // Output delay of path_history
	double delay_spread = 2; // Normalized to sample rate
	long i;
	double snr=101.0;

	long paths=5;

	num = 1000;
	baud_eq_env<complex<double> > ddfse_env(paths);
	//	long rcv_symbols=0;
	long symbols=0;
	ddfse_env.num = num;

	time_t current_time;
	time(&current_time);
	noise random_offset;
	random_offset.set_seed((int)(current_time*10));

	// MAIN LOOP
	for (i=0;i<loops;i++) {
	  snr += 1;
	  ddfse_env.snr = snr;
	  ddfse_env.loop_init(EQTYPE,delay, delay_spread); // 1 DDFSE
	  if (i==0) ddfse_env.multipaths->exp_decay.print();
	  symbols = 0;

	  do {
		ddfse_env.step();
		// Get data output from Chip
		ddfse_env.BER_mon->synchronize(&symbols,ddfse_env.data);
		symbols++;
		if (ddfse_env.rcv_symbols > num && !ddfse_env.BER_mon->found_sync()) break;
	  } while (symbols < num);

	  cout << " SNR = " << snr << " BER = " ;
	  cout << ddfse_env.BER_mon->ber(symbols) << '\n';
	  cout.flush();
	  resf << snr << " " <<  ddfse_env.BER_mon->ber(symbols) << '\n';
	  ddfse_env.BER_mon->final_results(symbols);
	  ddfse_env.loop_end();
#ifdef HIST
	  if (i==0) histf.close();
#endif
	}
	resf.close();
	return(1);
}                                      

