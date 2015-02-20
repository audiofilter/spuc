#include <iomanip>
#include <spuc/cic.h>
#include "cpplot.hpp"
using namespace std;
using namespace SPUC;
using namespace cpplot;
int main(int argc,char* argv[])
{
  const long O=2;
  int n=100;
  int i;
  cic<long> F(O);
	std::vector<double> x(n),y(n);
	glut::init(argc, argv);
  
	signed char dump = 1;
  long imp = 1;

	for (i=0;i<n;i++) { 
		x[i]=i;
		dump = ((i % 64) == 0);
		y[i] = F.interpolate(imp, dump);
		imp *= -1;
  }
	plot(x,y);
	while(true) std::this_thread::yield();

  return 0;
}
