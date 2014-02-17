#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <spuc/sint.h>
#include <spuc/fpint.h>
#include <spuc/iir_2nd.h>
#include <spuc/iir.h>
#include <spuc/butterworth_iir.h>
using namespace SPUC;
int main(int argv, char* argc[]) {
  int i;
  long iimp;
  const long N=100;
  const long Order=2;
  const long Bits     =6;
  const long Frac_Bits=4;
  double a0,a1;
  long a0s,a1s;

  ofstream ff("imp.dat");

  iir_coeff BPF(Order);
  butterworth_iir(BPF,0.1,true,3.0);
  //  BPF.round_ab(Bits);

  iir<double> LPF(BPF);
  
  LPF.print();

  complex<double> ab = BPF.get_root(0);
  a0 = ab.re;
  a1 = ab.im;

  cout << "A = " << a0 << " " << a1 << "\n";

  long gain = (1 << Frac_Bits);
  a0s = (long)(a0*gain);
  a1s = (long)(a1*gain);

  cout << "A scaled = " << a0s << " " << a1s << "\n";

  //  iir_2nd<long, complex<double> >  testb(a0,a1);
  //  iir_2nd<long, complex<long> >    testd(a0s,a1s);

  iir_2nd<long, double>            testa(a0,a1);
  iir_2nd<long, double>            testb(a0s,a1s);

  iir_2nd<long, long>              testl(a0s,a1s);

  iir_2nd<long, sint<Bits> >          test1(a0s,a1s);
  iir_2nd<sint<8>, sint<Bits> >       test2(a0s,a1s);

  iir_2nd<fpint<8,8>, fpint<Bits, Frac_Bits> > testFP(a0,a1);

  testb.set_round_bits(Frac_Bits);
  testl.set_round_bits(Frac_Bits);
  test1.set_round_bits(Frac_Bits);
  test2.set_round_bits(Frac_Bits);
  
  test1.print();
  test2.print();

  
  iimp = 1000;
  for (i=0;i<N;i++) {
	//	cout << testa.clock(iimp) << " ";
	//	cout << testb.clock(iimp) << " ";
	//	cout << "\n";
	/*
		ff << testa.clock(iimp) << " ";
		ff << testb.clock(iimp) << " ";
		ff << testl.clock(iimp) << " ";
		ff << test1.clock(iimp) << " ";
	*/
	ff << test2.clock(iimp) << " ";

	ff << "\n";
	iimp = 0;
  }

  ff.close();
  return(1);
}
