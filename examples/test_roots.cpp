#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#define maxiter 500
#define DBL_EPSILON 1e-20
#ifdef GET_ROOTS
#include <spuc/get_roots.h>
#endif
#include <spuc/find_roots.h>
using namespace std;
using namespace SPUC;
int main()
{
  float_type quad[2];
  int n,i;
  smart_array<complex<float_type> > p;
  
  n = 5;

  float_type a[] = {0.20882,  -0.97476,   2.08818,  -1.94952,   1.04409,  -0.19495};
  smart_array<float_type> b(6);
  b[0] = -0.19495;
  b[1] =  1.04409;
  b[2] = -1.94952;
  b[3] =  2.08818;
  b[4] = -0.97476;
  b[5] =  0.20882;


  cout << "Polynomial order = " << n << "\n";
  cout << "Enter coefficients, high order to low order" << endl;
  for (i=0;i<=n;i++) {
	cout << a[i] << " * x^" << n-i << " : ";
  }
  cout << "\n";
  // initialize estimate for 1st root pair 
  quad[0] = 2.71828e-1;
  quad[1] = 3.14159e-1;
  std::cout << quad[0] << " " << quad[1] << "\n";
  // get p 
#ifdef GET_ROOTS
  get_quads(a,n,quad,x);
  int numr = roots(x,n,wr);

  cout << "METHOD 1\n";
  
  cout << endl << "Roots (" << numr << " found):" << endl;
  cout.setf(ios::showpoint);
  cout.precision(15);
  cout.setf(ios::showpos);
  for (i=0;i<n;i++) {
	cout.width(18);
	if ((real(wr[i]) != 0.0) || (imag(wr[i]) != 0.0))
	  cout << wr[i].real() << " " << wr[i].imag() << "I" << endl;
  }

#endif

  p = find_roots(b,n);

  cout << "METHOD 2\n";
  
  //  cout << endl << "Roots (" << numr << " found):" << endl;
  cout.setf(ios::showpoint);
  cout.precision(15);
  cout.setf(ios::showpos);
  for (i=0;i<n;i++) {
	cout.width(18);
	cout << real(p[i]) << " " << imag(p[i]) << "I" << endl;
  }

  return 0;
}
