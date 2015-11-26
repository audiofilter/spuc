#include <spuc/max_pn.h>
#include <spuc/delay.h>
#include <spuce/filters/fir.h>
#include <spuc/mle.h>
#include <spuc/noise.h>
#include <iostream>
#include <fstream>
#include <iomanip>

#include <chrono>
#include <thread>

#include "cpplot.hpp"
using namespace cpplot;
using namespace SPUC;
//! \brief testing MLSE, plot error rate vs samples as random noise is added at random levels
//
//! \ingroup examples
int main(int argc, char* argv[]) {

	const int n=100;
	glut::init(argc, argv);
	std::vector<double> x(n),y(n),z(n);
	int i;
	max_pn pn(0x006d, 63, -1);  // Maximal length PN sequence for data
	char data=-1;
	char taps=3;
    spuce::fir<float_type,float_type> tx_fir(taps);
	float_type tx_data,rx_data;
	long path_out;
	bool bit_out;
	bool ref_data;
	bool ref_dly;
	long error=0;

	// Necessary to account for delay through MLSE
	delay <bool> delayed_ref(34);

	// "Typical" Channel impulse response
	tx_fir.settap(0,1.0);
	tx_fir.settap(1,-1.5);
	tx_fir.settap(2,0.5);

	// The Equalizer
	mle<float_type> viterbi(taps);
	
	// Pre-set Taps as would occur during 'training'
	for (i=0;i<taps;i++) {
		viterbi.cfir.settap(i,tx_fir.gettap(i));
	}

	// Randomized levels
	noise rando;

	for (i=0;i<20;i++) pn.out();

	for (i=0;i<n;i++) x[i] = i;
	i = 1;
	title("Error rate vs samples");
	xlabel("Samples ");
	ylabel("Error rate ");

	// Start without noise
	float_type noise_gain = 0;

	while (1) {
		data = pn.out(); 
		ref_data = (data == 1) ? 1 : 0;
		ref_dly = delayed_ref.update(ref_data);
		tx_data = tx_fir.update(data);
		rx_data = tx_data + noise_gain*rando.gauss(); // + noise
		path_out = viterbi.mlsd(rx_data);
		bit_out = (path_out & 0x80000000) ? 1 : 0;
		error += (ref_dly != bit_out);
		// Plot setup
		vertex(i,error/double(i));
		set("r");
		axis(i-50,i+50,-0.05,0.25);
		grid(1);
		// fast scrolling but not too fast
    std::chrono::milliseconds sec(10);
		std::this_thread::sleep_for(sec);
		i++;
		// Randomize noise gain
		if (i % 400 == 0) {
			noise_gain = 2.0*rando.uniform();
			//error = 0; reset error rate
			std::cout << "Noise gain = " << noise_gain << "\n";
		}
	}
	return(1);
}
