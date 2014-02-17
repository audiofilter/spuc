#ifndef SPUC_BAUD_EQ_ENV
#define SPUC_BAUD_EQ_ENV

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
// from directory: spuc_complex_templates
#include <spuc/spuc_types.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <spuc/spuc_math.h>
#include <cmath>
#include <spuc/complex.h>
#include <spuc/max_pn.h>   	
#include <spuc/noise.h>     
#include <spuc/bpsk_ber_test.h>
#include <spuc/fading_channel.h>
#include <spuc/mle.h>
namespace SPUC {
//! \file
//! \brief  Class for doing a simulation of an equalizer running at 1 sample/symbol
//
//! \brief  Class for doing a simulation of an equalizer running at 1 sample/symbol
//
//! \author Tony Kirke
//! \ingroup complex_templates sim equalizers
template <class Numeric> class baud_eq_env
{
public:
  
  bpsk_ber_test* BER_mon;
  max_pn* tx_data_source;
  noise* n;
  mle<Numeric>* DUT;
  fading_channel* multipaths;
  
  long num;
  float_type var;
  float_type snr;
  long data; // output of equalizer
  long output_delay; // Equalizer output delay (for paths to merge)
  long eq_type; // type of equalizer used
  // 0 MLSE, 1 DDFSE
  
  complex<float_type> base; 
  complex<float_type> main; 
  complex<float_type> b_noise;  // Noise
  long rcv_symbols;       // Number of symbols decoded
  long count;  			// index of sample number at input rate
  long paths; // Number of multipaths in channel model
  long phase_acc;

  baud_eq_env(long npaths=1) :  paths(npaths)
  {
	snr = 10.0;
	base = 0;
	rcv_symbols = 0;
	count = 0;
	output_delay = 0;
	eq_type = 0;
#ifdef NEWNOISE
	n = new noise;
#endif
  }
  void loop_init(long equalizer_type, long data_delay,
				 float_type delay_spread) {
	long mlse_len;
	int i;
	fir<Numeric,Numeric> cir(paths);
	output_delay = data_delay;
	eq_type = equalizer_type;
	var = sqrt(2.0)*pow(10.0,-0.05*snr);   // Unfiltered noise std dev	
	BER_mon = new bpsk_ber_test;
	tx_data_source = new max_pn;
	multipaths = new fading_channel(paths,delay_spread);
	mlse_len = paths-1;

	// PICK EQUALIZER Type
	DUT = new mle<Numeric>((char)(mlse_len));
	multipaths->exp_decay.coeff[0] = 0.9;
	multipaths->exp_decay.coeff[1] = 0.1;
	// Copy from multipaths (change type if necessary!!!!!!!!!)
	for (i=0;i<paths;i++) {
	  cir.settap(i,multipaths->exp_decay.coeff[i]);
	}

#ifndef NEWNOISE
	n = new noise;
#endif	
	// initialise CIR from Channel CIR
	DUT->set_cir(cir);
	rcv_symbols=0;  		  // Number of symbols decoded
	count=0;    			 // index of sample number at input rate
	phase_acc=0;
  }
  // STEP
  void step(void) {
  count++;  
  // Get new sample from transmitter
  phase_acc += tx_data_source->out();
  //phase_acc++;
  base = expj(phase_acc*PI/2);
  // Pass through Channel model
  main = multipaths->update(base);
  // Noise term
  b_noise = var*n->Cgauss();
  // Add noise
  main += b_noise;
  // Clock equalizer
  if (count>1) data = DUT->mlsd(main);
  data = (data & MASK_BIT(output_delay)) ? 1 : -1;
  rcv_symbols++;
  }	
  void loop_end()
  {
	delete BER_mon;
	delete tx_data_source;
	delete multipaths;
#ifndef NEWNOISE
	delete n;    
#endif
	delete DUT;
  }                                      
};
} // namespace SPUC
#endif
