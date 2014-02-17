#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <spuc/fpint.h>
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
  const long Int_Bits =4;
  const long Frac_Bits=4;
  double a0,a1;

  ofstream ff("imp.dat");
  ofstream tmpf("tmp.dat");

  iir_coeff BPF(Order);
  butterworth_iir(BPF,0.1,true,3.0);

  iir<double> LPF(BPF);

  LPF.print();

  complex<double> ab = BPF.get_root(0);
  a0 = ab.re;
  a1 = ab.im;

  iir_2nd<long, double>         testa(a0,a1);
 
  iir_2nd<int_fp, int_fp>       test3;

  test3.a2.int_bits = Int_Bits;
  test3.a1.int_bits = Int_Bits;
  test3.b0.int_bits = Int_Bits;
  test3.b1.int_bits = Int_Bits;
  test3.b2.int_bits = Int_Bits;

  test3.a2.frac_bits = Frac_Bits;
  test3.a1.frac_bits = Frac_Bits;
  test3.b0.frac_bits = Frac_Bits;
  test3.b1.frac_bits = Frac_Bits;
  test3.b2.frac_bits = Frac_Bits;

  test3.set_coeffs(
				   fpint<Int_Bits,Frac_Bits>(1), 
				   fpint<Int_Bits,Frac_Bits>(2),
				   fpint<Int_Bits,Frac_Bits>(1),
				   fpint<Int_Bits,Frac_Bits>(a0), 
				   fpint<Int_Bits,Frac_Bits>(a1)
				   );

  test3.print();

  test3.fb2.bits = 8;
  test3.set_round_bits(Frac_Bits);
  
  iimp = 100;
  fpint<8,8> imp_fp;

  for (i=0;i<N;i++) {
	tmpf << testa.clock(iimp) << " ";
	imp_fp = iimp;
	//	ff << test3.clock(imp_s) << "\n";
	iimp = 0;
  }

  ff.close();
  return(1);
}
