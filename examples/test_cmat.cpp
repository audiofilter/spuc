#include <iostream>
#include <fstream>
#include <iomanip>
//using namespace std;
#include <spuc/vector.h>
#include <spuc/matrix.h>

using namespace SPUC;
int main(int argv, char* argc[]) {

  matrix<complex<double> > P;
  vector<complex<double> > k;
  vector<double> w, u, ut, x;
  complex<double> d;

  matrix<complex<double> > Z = d*P;
  matrix<complex<double> > Y = P*d;
  matrix<complex<double> > X = d+P;
  return(1);
}
