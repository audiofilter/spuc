#include <iostream>
#include <cstdlib>
#include <spuc/complex.h>
#include <spuc/noise.h>
#include <spuc/baud_eq_env.h>
//! \brief  Baud rate equalization simulation
//
//!  BPSK (real) data is corrupted with a multipath channel
//!  (delay spread = baud rate?) with L+M (programmable) number of taps
//!  Noise is added and this program generates BER data over a 
//!  range of SNR points with a
//!  a)  MLSE (Viterbi) Equalizer with 2^L states
//!  b)  DFSE Equalizer with 2^L states and M feedback decisions
//! \ingroup examples
int main(int argc, char *argv[])
{                        
	ofstream resf("res.dat");
	long num;
	long loops=12;
	long i;
	double snr=11.0;
	long paths=3;

	if (argc!=4) {
	  num = 100000;
	} else {
	  num = ((long)atof(argv[1]));       // Number of symbols simulated 
	  snr = atof(argv[2]);               // SNR dBs
	  paths = ((long)atof(argv[3]));     // Number of multipath paths
	}

	baud_eq_env Environment(paths);
	long rcv_symbols=0;
	long symbols=0;
	Environment.num = num;

	time_t current_time;
	time(&current_time);
	noise random_offset;
	random_offset.set_seed((double)(current_time*10));

	// MAIN LOOP
	for (i=0;i<loops;i++) {
	  snr -= 1;
	  Environment.snr = snr;
	  Environment.loop_init();
	  symbols = 0;

	  do {
		Environment.step();
		// Get data output from Chip
		Environment.BER_mon->synchronize(&symbols,Environment.data);
		// Correlate with reference PN
		if (Environment.BER_mon->found_sync())
		  Environment.BER_mon->ber_results(symbols++); 
		else symbols++;
		if (Environment.rcv_symbols > num && !Environment.BER_mon->found_sync()) break;
	  } while (symbols < num);

	  cout << " SNR = " << snr << " BER = " << Environment.BER_mon->ber(symbols) << '\n';
	  resf << snr << " " <<  Environment.BER_mon->ber(symbols) << '\n';
	  Environment.BER_mon->final_results(symbols);
	  Environment.loop_end();
	}
	resf.close();
	return(1);
}                                      

