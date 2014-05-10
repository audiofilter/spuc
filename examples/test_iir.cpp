#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <spuc/butterworth_iir.h>
#include <spuc/elliptic_iir.h>
#include <spuc/iir.h>
#include <spuc/iir_2nd.h>
#include <spuc/spuc_fp.h>
using namespace SPUC;
//! \brief testing various types for IIR 
//
//! \ingroup examples
int main(int argv, char* argc[]) {
  int i;
  const long N=32;
  const long O=4;
  //  float_type x;
  float_type imp;
  //  float_type y;
  //  float_type pass_edge = 0.2;
  //  float_type stop_edge = 0.22;

  iir_coeff BPF(O); 
  butterworth_iir(BPF,0.1,true,3.0);
  iir<float_type> LPF(BPF);


  iir<spuc_int<16> ,float_type> IPF(BPF);
  iir<float_type ,spuc_fixed<30,15> > SPF(BPF);



  ofstream IMP("impulses.dat");

  LPF.print();
  
  cout << "--------------------------------------\n";
  cout << "Int_s version \n";
  IPF.print();
  cout <<"Int_s version end \n";
  cout << "--------------------------------------\n";

  cout << "--------------------------------------\n";
  cout << "vfixed version \n";
  SPF.print();
  cout <<"vfixed version end \n";
  cout << "--------------------------------------\n";


  cout << "poles = ";
  for (i=0;i<(O+1)/2;i++) cout << BPF.poles[i] << " ";
  cout << "\n";
  cout << "zeros = ";
  for (i=0;i<(O+1)/2;i++) cout << BPF.zeros[i] << " ";
  cout << "\n";
  cout << "A = ";
  for (i=0;i<O+1;i++) cout << BPF.a_tf[i] << " ";
  cout << "\n";
  cout << "B = ";
  for (i=0;i<O+1;i++) cout << BPF.b_tf[i] << " ";
  cout << "\n";

  imp = 100.0;

  //  sint<16> iimp = sint<16>((long)imp);
  //  vfixed fimp = vfixed(imp);

  for (i=0;i<N;i++) { 
	cout << LPF.clock(imp) << " ";
	//	cout << IPF.clock(imp) << " ";
	cout << SPF.clock(imp) << " ";
	cout << "\n";
	imp = 0;
  }
  return(1);
}
