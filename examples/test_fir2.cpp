#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <spuc/fir.h>
using namespace SPUC;
//! \brief testing various types for short FIR
//
//! \ingroup examples
int main(int argv, char* argc[]) {
  int i;
  //  float_type x;
  //  float_type imp;
  long iimp;
  //  float_type y;
  //  float_type pass_edge = 0.08;
  //  float_type stop_edge = 0.16;

  ofstream IMP("impulses.dat");


  fir<long, float_type> test1(3);
  fir<complex<long>, float_type> test2(3);
  fir<float_type, float_type> test3(3);
  fir<complex<float_type>, float_type> test4(3);
  fir<long, long> test5(3);
  fir<complex<long>, long> test6(3);
  fir<float_type, long> test7(3);
  fir<complex<float_type>, long> test8(3);

  //  test2.print();
  //  LPF.print();

  //#ifdef XXX
  //  imp = 1;
  iimp = 1;
  for (i=0;i<100;i++) {
	IMP << test1.clock(iimp) << "\n";
	IMP << test2.clock(iimp) << "\n";
	IMP << test3.clock(iimp) << "\n";
	IMP << test4.clock(iimp) << "\n";
	IMP << test5.clock(iimp) << "\n";
	IMP << test6.clock(iimp) << "\n";
	IMP << test7.clock(iimp) << "\n";
	IMP << test8.clock(iimp) << "\n";
	//	imp = 0;
	iimp = 0;
  }
  IMP.close();
  //#endif
  return(1);
}
