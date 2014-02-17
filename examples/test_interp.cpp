#include <iostream>
#include <fstream>
#include <spuc/farrow_upsampler.h>
#include <cmath>
using namespace SPUC;
using namespace std;

int main(int argc, char *argv[]) 
{
  int i;
  farrow_upsampler INTERP(4);
  double time_inc = 36.0/40.0;
  double x = 1.0;
  double y=0;
  int need=0;

  ofstream REF("ref.dat");
  ofstream IMP("interp.dat");
  
  x = sin(2*3.14*0/100);
  for (i=0;i<300;i++) {
	if (need) {
	  x = sin(2*3.14*i/100);
	  REF<< x << "\n";
	}
	need = INTERP.need_sample(time_inc, x);
	y = INTERP.output(time_inc);
	IMP << y << "\n";
  };
  REF.close();
  IMP.close();
  return(1);
}
