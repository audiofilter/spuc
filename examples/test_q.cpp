#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
//#define NEW_WAY_A
#define NEW_WAY_B
#include <spuc/equalizer.h>
using namespace SPUC;
//! \brief testing graphic equalizer
//
//! \ingroup examples
int main(int argc, char* argv[]) {
  ofstream IMP("impulses.dat");
  const int N=25;
  const int BANDS=10;
  iir_allpass_variable_cascade<double,double> S;
  double s = 1.0;
  double y;

  int SAMPLES = N*(1<<BANDS);

  S.set_coeffs(0.0,2,4);

  delay<double> D1;
  circ_buffer<double> D2;

  int size = 5;
  D1.set_size(size);
  D2.set_size(size);

  //SAMPLES = 10;
  //  double out,out2;

  for (int i=0;i<SAMPLES;i++) { 
	y = S.clock(s);
	/*
	out = D1.check(size-1);
	D1.input(s);

	out2 = D2.check(size-1);
	D2.input(s);

	std::cout << out << " " << out2 << " "
			  << D1.last() << " " << D2.last() << "\n";
	s+=1;
	*/
	IMP << y << "\n";
	s = 0;
  }
  IMP.close();
  return(1);
}
