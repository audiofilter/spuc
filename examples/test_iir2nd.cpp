#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <spuc/butterworth_iir.h>
#include <spuc/elliptic_iir.h>
#include <spuc/iir.h>
#include <spuc/iir_2nd.h>
using namespace SPUC;
//! \brief testing various types for 2nd order IIR
//
//! \ingroup examples
int main(int argv, char* argc[]) {
  int i;
  //  double x;
  //  double imp;
  long iimp;
  //  double y;
  //  double pass_edge = 0.08;
  //  double stop_edge = 0.16;

  iir_coeff BPF(2); 
  elliptic_iir(BPF,0.2,true,0.22,40,0.5);
  butterworth_iir(BPF,0.35,true,3);
  iir<double> LPF(BPF);
  LPF.print();

  double dA1 = BPF.get_coeff_a(0);
  double dA2 = BPF.get_coeff_a(1);

  int ROUND_BITS = 8;

  long A1 = (long)floor((1<<(ROUND_BITS-1))*dA1+0.5);
  long A2 = (long)floor((1<<(ROUND_BITS-1))*dA2+0.5);

  ofstream IMP("impulses.dat");

  // REAL TYPEs
  iir_2nd<long, double> test1(dA1,dA2);
  iir_2nd<double, double> test2(dA1,dA2);

  iir_2nd<long, long> test3(1,2,1,A1,A2,ROUND_BITS);
  iir_2nd<double, long> test4(1,2,1,A1,A2,ROUND_BITS);

  // COMPLEX TYPES
  iir_2nd<complex<long>, double> test5(dA1,dA2);
  iir_2nd<complex<double>, double> test6(dA1,dA2);

  iir_2nd<complex<long>, long> test7(1,2,1,A1,A2,ROUND_BITS);
  iir_2nd<complex<double>, long> test8(1,2,1,A1,A2,ROUND_BITS);

  test2.print();
  test3.print();

  //  imp = 1;
  iimp = 100;
  for (i=0;i<100;i++) {
	//	IMP << LPF.clock(imp) << "\n";
	IMP << test1.clock(iimp) << " ";
	IMP << test2.clock(iimp) << "  ";
	IMP << test3.clock(iimp) << "  ";
	IMP << test4.clock(iimp) << "  ";
	IMP << test5.clock(iimp) << " ";
	IMP << test6.clock(iimp) << "  ";
	IMP << test7.clock(iimp) << "  ";
	IMP << test8.clock(iimp) << "  ";
	IMP << "\n";
	//	imp = 0;
	iimp = 0;
  }
  IMP.close();
  return(1);
}
