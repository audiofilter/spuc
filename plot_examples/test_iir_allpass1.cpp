#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <spuc/fir_coeff.h>
#include <spuc/iir_allpass1_cascade.h>
using namespace SPUC;
//! \brief testing various types of filters
//
//! \ingroup examples
#include "plot_fft.h"
int main(int argv, char* argc[]) {
	const int N=256;
  int i;
  float_type imp;
  iir_allpass1_cascade<float_type> AF1(0.4,2);
	std::vector<double> y(N,0);

  imp = 1;
  for (i=0;i<N;i++) {
		y[i] = AF1.clock(imp);
		imp = 0;
  }
	
	plot_fft(y);

  return(1);
}
