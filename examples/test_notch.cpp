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
int main(int argv, char* argc[]) {

  int i;
  double imp;
  ofstream IMP("notch.dat");
  notch_allpass<double,double> N(0.42822);
  //  allpass_2nd<double,double> A(0.9,0.9*(1.0+0.9));

  imp = 1.0;
  for (i=0;i<200;i++) {
	IMP	<< N.clock(imp) << " "
	    << "\n";
	imp = 0;
  }
  IMP.close();
  return(1);
}
