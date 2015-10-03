#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <spuc/chebyshev_iir.h>
#include <spuc/iir.h>
#include <spuc/iir_2nd.h>
using namespace SPUC;
#include "plot_fft.h"

//! \brief testing various types for IIR 
//! \ingroup examples

int main(int argv, char* argc[]) {
  const long N=256;
  const long O=3;
  float_type imp;

  iir_coeff BPF(O); 
  chebyshev_iir(BPF,0.2,false,0.1);
  iir<float_type> LPF(BPF);

	std::vector<double> y(N,0);
	
  imp = 1.0;
	for (unsigned int i = 0; i < N; i++)
	{
		y[i] = LPF.clock(imp);
		imp = 0;
	}

	plot_fft(y);
	return 0;
}
