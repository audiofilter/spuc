#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <spuc/cic.h>
using namespace SPUC;
//! \ingroup examples
int main(int argv, char* argc[]) {
  int i;
  const long O=2;
  long imp;

  cic<long> F(O);
  ofstream IMP("impulses.dat");
  
  imp = 1;
	signed char dump = 1;
  for (i=0;i<100;i++) { 
		dump = ((i % 64) == 0);
		cout << F.interpolate(imp, dump) << "\n";
		imp *= -1;
  }
  return(1);
}
