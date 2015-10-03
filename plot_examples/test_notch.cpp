#include <iostream>
#include <fstream>
#include <iomanip>
#include <spuc/notch_iir.h>
#include <spuc/notch_allpass.h>
using namespace std;
using namespace SPUC;
//! \brief testing of notch filter based on allpass section
//
//! \ingroup examples
#include "plot_fft.h"

int main(int argv, char* argc[]) {

	const int N=256;
  int i;
  double imp;
	std::vector<double> y(N);
  notch_allpass<double,double> Notch(0.42822);
  //  allpass_2nd<double,double> A(0.9,0.9*(1.0+0.9));

  imp = 1.0;
  for (i=0;i<N;i++) {
		y[i] = Notch.clock(imp);
		imp = 0;
  }
	plot_fft(y);
	
  return(1);
}
