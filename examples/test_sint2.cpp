#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <spuc/sint.h>
#include <spuc/iir_2nd.h>
#include <spuc/iir.h>
#include <spuc/butterworth_iir.h>
#include <spuc/delay.h>
using namespace SPUC;
int main(int argv, char* argc[]) {
  int i;
  long iimp;
  const long N=1;
  const long Order=2;
  const long Bits     =6;
  const long Frac_Bits=4;
  double a0,a1;
  long a0s,a1s;

  delay<int> DDD(5);

#define OK
#ifdef OK

  ofstream ff("imp.dat");
  ofstream tmpf("tmp.dat");

  iir_coeff BPF(Order);
  butterworth_iir(BPF,0.1,true,3.0);
  BPF.quantize(Bits);

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

  iir_2nd<int_s, int_s>       test3;

  test3.set_coeffs(
				   sint<8>(2), sint<3>(2), sint<2>(1),
				   sint<8>(a0s), sint<8>(a1s)
				   );

  test3.fb2.bits = 8;
  test3.set_round_bits(Frac_Bits);


  testb.set_round_bits(Frac_Bits);
  testl.set_round_bits(Frac_Bits);
  test1.set_round_bits(Frac_Bits);
  test2.set_round_bits(Frac_Bits);

  
  test1.print();
  test2.print();

  
  iimp = 1000;
  sint<12> imp_s;
  fpint<8,8> imp_fp;

  for (i=0;i<N;i++) {
	tmpf << testa.clock(iimp) << " ";
	tmpf << testb.clock(iimp) << " ";
	tmpf << testl.clock(iimp) << " ";
	tmpf << test1.clock(iimp) << " ";
	tmpf << test2.clock(iimp) << " ";
	
	imp_s = iimp;
	ff << test3.clock(imp_s) << "\n";

	iimp = 0;
  }

  ff.close();
#endif
  return(1);
}
