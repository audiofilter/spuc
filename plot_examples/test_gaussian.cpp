#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <spuc/fir_coeff.h>
#include <spuc/fir.h>
#include <spuc/gaussian_fir.h>
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
  fir_coeff<float_type> GF(TAPS);
  gaussian_fir(GF, 0.25, 8);
	fir<double> GAUSS(GF);
	std::vector<double> y(N);

  imp = 1;
  for (i=0;i<N;i++) {
		y[i] = GAUSS.clock(imp);
		imp = 0;
  }
	
	plot_fft(y);

  return(1);
}
