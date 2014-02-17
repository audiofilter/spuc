#include <iostream>
#include <fstream>
#include <iomanip>
//using namespace std;
#include <spuc/vector.h>
#include <spuc/matrix.h>

using namespace SPUC;
int main(int argv, char* argc[]) {

  const int n = 5;
  matrix<double> P(n,n);
  vector<double> k(n);
  vector<double> w(n), u(n), ut(n), x(n);
  double ialpha=0;
  matrix<double> d(n,n);
  matrix<double> X(n,n);
  double y=0;

  P = 0.01;
  k = 0.0;

  double e = y-dot(w,u);
  w = w + e*k;
  d = k*(ut*P);
  P = ialpha*(P - d);
  return(1);
}
