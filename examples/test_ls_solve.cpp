#include <itpp/itbase.h>
#include <ostream>
#include <fstream>
using namespace std;
using std::cout;
using std::endl;
using namespace itpp;


#ifdef NO_LAPACK
#define __THIS_PROGRAM_WILL_NOT_RUN__
#endif

#ifdef NO_CBLAS
#define __THIS_PROGRAM_WILL_NOT_RUN__
#endif

#ifdef __THIS_PROGRAM_WILL_NOT_RUN__
int main() { cout << "LAPACK and CBLAS is needed for this test program" << endl; }
#else

#define M_2PI 3.1416

int main()
{
  ofstream rf("r.dat");
  int i,n;
  int M,N;
  
  M = 32;
  N = 4*M;
  
  cout << "Real systems:" << endl << endl;
  mat A, B, X;
  vec b, x;
  double f;
  //  double df;
  //  double delta;
  
  A = randn(N,M);
  b = randn(N);

  // passband
  for (i=0;i<N;i++) {
	f = M_2PI*i/(2*(N-1));
	b(i) = 1.0;
	if (i >= N/2) b(i) = 0;

	b(i) = 0;
	for (n=0;n<M;n++) {	 
	  A(i,n) = cos(n*f);	
	}
  }
  
  cout << "Starting LS SOLVE...";
  x = ls_solve_od(A, b);
  

  cout << "Square system: Ax=b" << endl
	   << "============================" << endl
	   << "A=" << A << endl
	   << "b=" << b << endl
	   << "x=" << x << endl << endl;
  
  for (i=1;i<M;i++) 	  rf << x(M-i) << "\n";
                          rf << 2*x(0) << "\n";
  for (i=1;i<M;i++) 	  rf << x(i) << "\n";

  rf.close();
  return 0;
}

#endif
