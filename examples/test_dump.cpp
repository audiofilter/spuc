#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <spuc/iir_2nd.h>
#include <spuc/iir.h>
#include <spuc/butterworth_iir.h>
#ifdef DUMP
#include <dump.hpp>
#endif
using namespace SPUC;
int main(int argv, char* argc[]) {
  //  int i;
  //  const long N=100;
  const long Order=2;
  const long Bits     =6;
  const long Frac_Bits=4;
  double a0,a1;
  //  long a0s,a1s;

  ofstream ff("imp.dat");

  iir_coeff BPF(Order);
  butterworth_iir(BPF,0.1,true,3.0);
  BPF.quantize(Bits);

  iir<double> LPF(BPF);
  
  LPF.print();

  complex<double> ab = BPF.get_root(0);
  a0 = real(ab);
  a1 = imag(ab);

  //  long gain = (1 << Frac_Bits);
  //  a0s = (long)(a0*gain);
  //  a1s = (long)(a1*gain);

  iir_2nd<long, double>            testx(a0,a1);

  testx.set_round_bits(Frac_Bits);
  
  testx.print();
  
#ifdef DUMP
  dump(testx,"testx");
#endif

  return(1);
}
