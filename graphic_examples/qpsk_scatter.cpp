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
using namespace cpplot;
using namespace SPUC;
//!  \brief Simulation of QPSK receiver in AWGN
//
//!  \ingroup sim examples
int main(int argc, char *argv[])
{                 
	std::string s[] = {"k","r","b","g"};
	glut::init(argc, argv);
	long num = 500;
	int num_loops = 10;
	float_type snr=30.0;
	float_type timing_offset=0.0;
	double scatter_gain = 32.0;
	float_type actual_over=2.00;
	sim_qpsk<float_type> Environment;
	long symbols=0;

	Environment.num = num;
	Environment.snr = snr;

	time_t current_time;
	time(&current_time);
	noise random_offset;

	random_offset.set_seed(123);
	// Only use positive timing offsets for now
	timing_offset = 0.5*random_offset.uni()*actual_over;
	Environment.time = 1;
	Environment.freq = 0;

	set(s[0]);
	set("*");
	for (int i=0;i<num_loops;i++) {
		Environment.loop_init(actual_over, timing_offset);
		symbols = 0;
		// MAIN LOOP
		do {
			Environment.step();
			if (Environment.rcv_symbols == SYM_LOOP_ON) Environment.RECEIVER.symbol_loop_filter.k0_en = 1;
#ifndef NOFREQC
			if (Environment.rcv_symbols == CAR_LOOP_ON) {
				Environment.RECEIVER.carrier_loop_filter.k1_en = 
					Environment.RECEIVER.carrier_loop_filter.k0_en = 1;
			}
#endif
			if (Environment.RECEIVER.symclk()==1) {
				//g1 = (Environment.RECEIVER.carrier_error);
				//g1 = (Environment.RECEIVER.carrier_loop_out);
				//g1 = (Environment.RECEIVER.symbol_loop_out);
				double gx = scatter_gain*real(Environment.RECEIVER.final_baseband);
				double gy = scatter_gain*imag(Environment.RECEIVER.final_baseband);
				vertex(gx,gy);
				axis(-2,2,-2,2);
				std::chrono::milliseconds msec(10);
				std::this_thread::sleep_for(msec);
				symbols++;
			}  				 
		} while (symbols < num);
		
		Environment.loop_end();
		std::cout << "SNR = " << snr << " " << s[(i+1)%4] << "\n";
		snr -= 4;
		Environment.snr = snr;
		set(s[(i+1) % 4]);
	}

	return(1);
} 
