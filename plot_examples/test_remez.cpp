#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <spuc/fir_coeff.h>
#include <spuc/remez_fir.h>
#include <spuc/fir.h>
#include <spuc/create_remez_lpfir.h>
using namespace SPUC;
//! \brief testing various types of filters
//
//! \ingroup examples
#include "plot_fft.h"
int main(int argv, char* argc[]) {
	const int N=256;
  int i;
  float_type imp;
  int TAPS = 37;
  float_type pass_edge = 0.245;
  float_type stop_edge = 0.30625;

  fir_coeff<float_type> RF(TAPS);
  create_remez_lpfir(RF,pass_edge,stop_edge,1);
	fir<double> RFIR(RF);
	std::vector<double> y(N);

  imp = 1;
  for (i=0;i<N;i++) {
		y[i] = RFIR.clock(imp);
		imp = 0;
  }
	
	plot_fft(y);

  return(1);
}
