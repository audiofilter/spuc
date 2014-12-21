#include <iostream>
#include <fstream>
#include <spuc/farrow_upsampler.h>
#include "cpplot.hpp"
using namespace std;
using namespace SPUC;
using namespace cpplot;
int main(int argc, char *argv[]) 
{
	const int n=64;
	std::vector<double> x(n),y(n);
  int i;
  farrow_upsampler INTERP(4);
  double time_inc = 39.0/41.0;
  double a=1.0;
  double b=0;
  int need=0;

	glut::init(argc, argv);
  //ofstream IMP("interp.dat");
  
  for (i=0;i<n;i++) {
		need = INTERP.need_sample(time_inc, a);
		if (need) a = 0;
		b = INTERP.output(time_inc);
		x[i] = i;
		y[i] = b;
		//IMP << y << "\n";
  };
	//  IMP.close();
	plot(x,y);
	while(true) boost::this_thread::yield();
  return(1);
}
