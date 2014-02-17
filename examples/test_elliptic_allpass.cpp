#include <iostream>
#include <fstream>
#include <iomanip>
#include <spuc/iir_allpass1_cascade.h>
using namespace std;
using namespace SPUC;
//! \brief Test bench for IIR as cascaded allpass filters in parallel
//
//! \ingroup examples
int main(int argv, char* argc[]) {

  int i;
  double imp;
  ofstream IMP("ea.dat");
  iir_allpass1_cascade<double> N(0.44,3);
  //  iir_allpass1_cascade<double> N(0.48,6);

  imp = 1.0;
  for (i=0;i<200;i++) {
	IMP	<< N.clock(imp) << " "
	    << "\n";
	imp = 0;
  }
  IMP.close();
  return(1);
}
