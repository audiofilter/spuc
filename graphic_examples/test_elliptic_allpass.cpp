#include <spuc/iir_allpass1_cascade.h>
#include "cpplot.hpp"
using namespace std;
using namespace SPUC;
using namespace cpplot;
//! \brief Test bench for IIR as cascaded allpass filters in parallel
int main(int argc,char* argv[])
{
  int n=200;
  int i;
  iir_allpass1_cascade<double> N(0.44,3);
	std::vector<double> x(n),y(n);
	glut::init(argc, argv);
  
  double imp = 1.0;

	for (i=0;i<n;i++) { 
		x[i]=i;
		y[i] = N.clock(imp);
		imp = 0; 
  }
	plot(x,y);
	while(true) std::this_thread::yield();

  return 0;
}
