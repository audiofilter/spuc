#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <spuc/smart_array.h>

using namespace SPUC;
int main(int argv, char* argc[]) {

  long n=5;

  smart_array<long> a(n);
  //  boost::shared_array<long> b(new long[n]);

  //  for (int i=0;i<n;i++) b[i] = (long)i;
  for (int i=0;i<n;i++) a[i] = -(long)i;

  //  for (int i=0;i<n;i++) cout << "b[" << i << "] = " << b[i] << "\n";

  for (int i=0;i<a.len();i++)	cout << "a[" << i << "] = " << a[i] << "\n";

  a.resize(3);

  for (int i=0;i<a.len();i++)	cout << "a[" << i << "] = " << a[i] << "\n";

  return(1);
}
