#include <spuc/butterworth_iir.h>
#include <spuc/elliptic_iir.h>
#include <spuc/iir.h>
#include <spuc/iir_2nd.h>
#include "cpplot.hpp"
#define PTS 200
using namespace SPUC;
using namespace cpplot;
//! \brief testing various types for 2nd order IIR
//
//! \ingroup examples
int main(int argc, char* argv[]) {
  int i;
  long iimp;

  iir_coeff BPF(2); 
  elliptic_iir(BPF,0.2,true,0.22,40,0.5);
  butterworth_iir(BPF,0.35,true,3);
  iir<double> LPF(BPF);

  double dA1 = BPF.get_coeff_a(0);
  double dA2 = BPF.get_coeff_a(1);

  int ROUND_BITS = 8;

  long A1 = (long)floor((1<<(ROUND_BITS-1))*dA1+0.5);
  long A2 = (long)floor((1<<(ROUND_BITS-1))*dA2+0.5);

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

	const int n=100;
	std::vector<double> x(n),a(n),b(n),c(n),d(n);
	std::vector<complex<double> > e(n),f(n),g(n),h(n);
	glut::init(argc, argv);

  iimp = 100;
  for (i=0;i<n;i++) {
		x[i] = i;
		a[i] = test1.clock(iimp); 
		b[i] = test2.clock(iimp);
		//		c[i] = test3.clock(iimp);
		//		d[i] = test4.clock(iimp);
		e[i] = test5.clock(iimp);
		f[i] = test6.clock(iimp);
		//		g[i] = test7.clock(iimp);
		//		h[i] = test8.clock(iimp);
		iimp = 0;
  }
	plot(x,a);set("r"); set("-");
	plot(x,b);set("g");
	//plot(x,c);set("b");
	//	plot(x,d);set("c");
	//	plot(x,e);set("y");

	while(true) boost::this_thread::yield();


  return(1);
}
