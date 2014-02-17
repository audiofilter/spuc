#include <cstdlib>
#include <spuc/complex.h>
#include <spuc/sim_equalizer.h>
#include <spuc/noise.h>
#define WAITSYMBOLS 15
int main(int argc, char *argv[])
{                        
    void usage(void);
#ifdef _DEBUG
	ofstream sampf("samp.dat");
	ofstream resf("res.dat");
#endif
	long num;
	double snr=9.0;
	double timing_offset=0.0;

	if (argc<3) {
	  num = 600;
	} else if (argc!=3) {
	  usage();
	} else {
	  num = ((long)atof(argv[1]));       // Number of symbols simulated 
	  snr = atof(argv[2]);   // Unfiltered noise std dev	
	}

	double actual_over=4.00;
	sim_equalizer Environment(4,3);
	long rcv_symbols=0;
	long symbols=0;

	Environment.num = num;
	Environment.snr = snr;

	time_t current_time;
	time(&current_time);
	noise random_offset;
	random_offset.set_seed((double)(current_time*10));

	Environment.loop_init();
//	Environment.BER_mon->init_delay(68); // makes correlation occur earlier
	symbols = 0;

	// MAIN LOOP
	do {
	  Environment.step();
#ifdef _DEBUG
	  sampf.width(4);
	  sampf.setf(ios::fixed);
	  sampf << Environment.base.re << " ";
	  sampf << Environment.base.im << '\n';
#endif

//	  if (Environment.DUT->symclk()==1) {
		if (Environment.rcv_symbols > WAITSYMBOLS )  {                    
		  // Get data output from Chip
		  Environment.BER_mon->synchronize(&symbols,Environment.data);
		  // Correlate with reference PN
		  if (Environment.BER_mon->found_sync()) Environment.BER_mon->ber_results(symbols++); 
		  else symbols++;
		}
//	  }  				 
	  if (Environment.rcv_symbols > num && !Environment.BER_mon->found_sync()) break;
	} while (symbols < num);

	Environment.BER_mon->final_results(symbols);
	Environment.loop_end();

#ifdef _DEBUG
	sampf.close();
	resf.close();
#endif
	return(1);
}                                      
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//	Usage 
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void usage(void)
{
  cout << "Performs  BER simulation.";
  cout << "Usage: EQ <Symbols> <NP>";
  cout << "Where <Symbols> is the number of symbols used for BER measurement";
  cout << "and <NP> is the approximate Es/No at input to A/D dB";
  exit (0);
}

