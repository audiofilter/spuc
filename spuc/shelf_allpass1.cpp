
// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_src
#include <spuc/shelf_allpass1.h>
#include <spuc/complex.h>
#include <spuc/spuc_math.h>
namespace SPUC {

double z_freqz_db(bool hpf, double f, double a, double h, double l) {
  double wf = f * PI;
  complex<double> hf;
  if (!hpf) { hf = h + l * (1 + (1.0 + polar(a, -wf)) / (a + polar(1.0, -wf))); } else {
    a = 1.0 / a;
    hf = h + l * (1 - (1.0 + polar(a, -wf)) / (a + polar(1.0, -wf)));
  }
  double db = 10.0 * log(magsq(hf)) / log(10.0);
  return (db);
}
double find_a(bool hpf, double f, double des_gain, double h, double l) {
  // Need to check starting with low values of "l"....
  double a = 0.0001;
  double a_inc = -0.1;
  const double tol = 0.1;  // error tolerance in dBs
  double g = z_freqz_db(hpf, f, a, h, l);
  double new_error = (g - des_gain);
  double prev_error;
  int count = 0;
  // std::cout << " a = " << a << " db = " << g << " " << new_error << "\n";
  while ((fabs(new_error) > tol) && (count < 100)) {
    prev_error = new_error;
    a = a + a_inc;
    g = z_freqz_db(hpf, f, a, h, l);
    new_error = (g - des_gain);
    if (((new_error < 0) && (prev_error > 0)) || ((new_error > 0) && (prev_error < 0))) {
      // sign change in error
      a_inc = -a_inc / 2;
    } else if (fabs(new_error) > fabs(prev_error)) {
      // error is growing
      a_inc = -a_inc / 2;
    }
    if (a >= 0) {
      a = 0.0001;
      a_inc = -fabs(a_inc / 2);
    }
    if (a < -1.01) {
      a = -0.1001;
      a_inc = fabs(a_inc / 2);
    }
    count++;
  }
  // force val
  if (count == 100) {
    if (hpf)
      return (0.0);
    else
      return (-1);
  }
  return (a);
}

}  // namespace SPUC
