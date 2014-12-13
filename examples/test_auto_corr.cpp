#include <iostream>
#include <iomanip>
#include <spuc/auto_corr.h>
using namespace std;
using namespace SPUC;
int main()
{
  int n=15;
  int i;

  std::vector<double> a(n);
  std::vector<double> b;
  
  double* z = new double[n];

  cout << "Size of z = " << sizeof(z) << "\n";
  cout << "Size of a = " << sizeof(a) << "\n";

  for (int i=0;i<n;i++) a[i] = -3.3+(double)i;

  for (i=0;i<n;i++) cout << a[i] << " ";
  cout << "\n";

  b = auto_corr(a);
  for (i=0;i<n;i++) cout << b[i] << " ";
  cout << "\n";

  return 0;
}
