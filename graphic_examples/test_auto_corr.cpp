#include <iostream>
#include <iomanip>
#include <spuc/dsp_functions/auto_corr.h>
#include "cpplot.hpp"
#include <thread>
using namespace std;
using namespace SPUC;
using namespace cpplot;
int main(int argc,char* argv[])
{
  int n=15;
  int i;

  std::vector<double> a(n);
	std::vector<double> x(n),y(n);
	glut::init(argc, argv);
  
  double* z = new double[n];

  cout << "Size of z = " << sizeof(z) << "\n";
  cout << "Size of a = " << sizeof(a) << "\n";

  for (int i=0;i<n;i++) a[i] = -3.3+(double)i;

  for (i=0;i<n;i++) cout << a[i] << " ";
  cout << "\n";

  y = auto_corr(a);
  for (i=0;i<n;i++) {
		cout << y[i] << " ";
	}
  cout << "\n";

	for(int i=0;i<n;++i) x[i]=i;

	plot(x,y);
	while(true) std::this_thread::yield();

  return 0;
 }
