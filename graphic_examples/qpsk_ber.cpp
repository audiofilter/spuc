// Copyright (c) 1993-2005 Tony Kirke
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <spuc/complex.h>
#include <spuc/sim_qpsk.h>
#include <spuc/noise.h>

#include "cpplot.hpp"
#include <thread>
#define SYM_LOOP_ON 10
#define CAR_LOOP_ON 1000
#define WAITSYMBOLS 2900
using namespace cpplot;
using namespace SPUC;
//!
//!  \brief Simulation of QPSK receiver in AWGN
//
//!  \ingroup sim examples
int main(int argc, char *argv[])
{                        
	glut::init(argc, argv);
	const long num=6000000;
	const int num_loops = 10;
	const float_type actual_over=2.00;
	float_type snr=6.0;
	float_type timing_offset=0.0;

	sim_qpsk<float_type> Environment;
	long symbols=0;

	Environment.num = num;
	Environment.snr = snr;

	time_t current_time;
	time(&current_time);
	noise random_offset;
	random_offset.set_seed(123);

	set("k");
	set("-.");
	set("*");
	title("Bit error rate vs SNR (dB)");
	xlabel("SNR (dB)");
	ylabel("Error rate log10");
	for (int i=0;i<num_loops;i++) {
		Environment.time = 0;
		Environment.freq = 0;
		Environment.loop_init(actual_over, timing_offset);
		Environment.BER_mon.init_delay(68); // makes correlation occur earlier
		symbols = 0;
		
		do {
			Environment.step();
			if (Environment.RECEIVER.symclk()==1) {
				if (Environment.rcv_symbols > WAITSYMBOLS )  {                    
					// Get I,Q data output from Chip
					complex<long> data = Environment.RECEIVER.data();  
					Environment.BER_mon.synchronize(&symbols,data);
					// Correlate with reference PN
					if (Environment.BER_mon.found_sync()) Environment.BER_mon.ber_results(symbols++); 
					else symbols++;
				}
			}  				 
			if (Environment.rcv_symbols > num && !Environment.BER_mon.found_sync()) break;
			if (Environment.BER_mon.errors > 100) break;
		} while (symbols < num);

		double ber = Environment.BER_mon.ber(symbols);
		vertex(snr,log10(ber));
    std::chrono::milliseconds msec(10);
		std::this_thread::sleep_for(msec);
		Environment.BER_mon.final_results(symbols);
		Environment.loop_end();
		snr += 1;
		Environment.snr = snr;
	}
	while(true) std::this_thread::yield();
	return(1);
} 
