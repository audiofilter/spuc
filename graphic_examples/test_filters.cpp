#include <iostream>
#include <fstream>
#include <iomanip>
#include <spuc/complex.h>
#include <spuc/fir.h>
#include <spuc/fir_coeff.h>
#include <spuc/remez_fir.h>
#include <spuc/gaussian_fir.h>
#include <spuc/butterworth_fir.h>
#include <spuc/create_remez_lpfir.h>
#include <spuc/iir_allpass1.h>
#include <spuc/iir_allpass1_cascade.h>
#include <spuc/freqz.h>
#include "cpplot.hpp"
#define PTS 200
using namespace SPUC;
using namespace cpplot;
int main(int argc,char* argv[])
{
  int n=40;
  int i;
  int TAPS = 36;
  float_type pass_edge = 0.245;
  float_type stop_edge = 0.30625;

  fir_coeff<float_type> RF(TAPS/2);
  fir_coeff<float_type> BF(TAPS);
  fir_coeff<float_type> GF(TAPS);
  //  allpass_iir<float_type> AF(0.23,0.769,2);
  iir_allpass1_cascade<float_type> AF1(0.4,2);
  iir_allpass1_cascade<float_type> AF2(0.44,3);

	//  complex<float_type> h[PTS];
	create_remez_lpfir(RF,pass_edge,stop_edge,1);
  butterworth_fir(BF, 0.15);
  gaussian_fir(GF, 0.25, 8);

  fir<double> fir_r(TAPS/2);
  fir<double> fir_b(TAPS);
  fir<double> fir_g(TAPS);
	fir_r.settaps(RF);
	fir_b.settaps(BF);
	fir_g.settaps(GF);
	fir_r.normalize_gain();
	fir_b.normalize_gain();
	fir_g.normalize_gain();

	std::vector<double> x(n),a(n),b(n),c(n),d(n),e(n);
	glut::init(argc, argv);
  
  double imp = 1.0;

	for (i=0;i<n;i++) { 
		x[i]=i;
		a[i] = AF1.clock(imp);
		b[i] = AF2.clock(imp);
		c[i] = fir_b.clock(imp);
		d[i] = fir_g.clock(imp);
		e[i] = fir_r.clock(imp);
		imp = 0; 
  }
	//  for (i=0;i<PTS;i++) HF << 20.0*log10(magsq(h[i])) << "\n";
	plot(x,a);set("r"); set("-");
	plot(x,b);set("g");
	plot(x,c);set("b");
	plot(x,d);set("c");
	plot(x,e);set("y");
	while(true) std::this_thread::yield();

  return 0;
}
