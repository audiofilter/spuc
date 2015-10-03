#include <iostream>
#include <fstream>
#include <spuc/farrow_upsampler.h>
using namespace SPUC;
using namespace std;
#include "plot_fft.h"
int main(int argc, char *argv[]) 
{
	const int N=32;
  int i;
  farrow_upsampler INTERP(4);
  double time_inc = 39.0/41.0;
  double x = 1.0;
  int need=0;

  
	std::vector<double> y(N,0);
  for (i=0;i<N;i++) {
		need = INTERP.need_sample(time_inc, x);
		if (need) x = 0;
		y[i] = INTERP.output(time_inc);
  };

	plot_data(y);
  return(1);
}
