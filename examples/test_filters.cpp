#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <spuc/fir_coeff.h>
#include <spuc/remez_fir.h>
#include <spuc/gaussian_fir.h>
#include <spuc/butterworth_fir.h>
#include <spuc/create_remez_lpfir.h>
#include <spuc/iir_allpass1.h>
#include <spuc/iir_allpass1_cascade.h>
#include <spuc/freqz.h>
using namespace SPUC;
#define PTS 200
//! \brief testing various types of filters
//
//! \ingroup examples
int main(int argv, char* argc[]) {

  int i;
  float_type imp;
  int TAPS = 36;
  float_type pass_edge = 0.245;
  float_type stop_edge = 0.30625;

  fir_coeff<float_type> BF(TAPS);
  fir_coeff<float_type> RF(TAPS);
  fir_coeff<float_type> GF(TAPS);
  //  allpass_iir<float_type> AF(0.23,0.769,2);
  iir_allpass1_cascade<float_type> AF1(0.4,2);
  iir_allpass1_cascade<float_type> AF2(0.44,3);

  complex<float_type> h[PTS];

  create_remez_lpfir(RF,pass_edge,stop_edge,1);
  butterworth_fir(BF, 0.15);
  gaussian_fir(GF, 0.25, 8);

  RF.print();

  ofstream IMP("impulses.dat");
  ofstream HF("h.dat");

  imp = 1;
  for (i=0;i<40;i++) {
	IMP	<< AF1.clock(imp) << " "
		<< AF2.clock(imp) << " "
	  // << CPF.clock(imp) << " "
	  //		<< EPF.clock(imp) << " "
	  //		<< BPF.clock(imp) << " "
	  //		<< BF.clock(imp) << " "
	  //		<< RF.clock(imp) << " "
	  //	<< GF.clock(imp) << " "
	    << "\n";
	imp = 0;
  }
  IMP.close();

  for (i=0;i<PTS;i++) HF << 20.0*log10(magsq(h[i])) << "\n";
  HF.close();
  return(1);
}
