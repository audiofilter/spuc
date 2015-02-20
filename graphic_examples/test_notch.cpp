#include <iostream>
#include <fstream>
#include <spuc/notch_iir.h>
#include <spuc/notch_allpass.h>
#include "cpplot.hpp"
using namespace SPUC;
using namespace cpplot;
//! \brief testing of notch filter based on allpass section
//
//! \ingroup examples
int main(int argc, char *argv[]) 
{
	const int n=64;
	std::vector<double> x(n),y(n);
  notch_allpass<double,double> N(0.42822);
  double a=1.0;

	glut::init(argc, argv);
	
  for (int i=0;i<n;i++) {
		y[i] = N.clock(a);
		x[i] = i;
  };
	plot(x,y);
	while(true) std::this_thread::yield();
  return(1);
}
