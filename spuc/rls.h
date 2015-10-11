#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_templates
#include <spuc/spuc_types.h>
#include <spuc/vector.h>
#include <spuc/matrix.h>
#include <spuc/fir.h>
#include <spuc/conj.h>
#include <spuc/signbit.h>
#include <spuc/magsq.h>
namespace SPUC {
//!
//! \file
//! \brief Recursive Least Squares Algorithm
//
//! \brief Recursive Least Squares Algorithm
//
//! \author Tony Kirke
//! \ingroup templates equalizers
//! \author Tony Kirke
//! \ingroup templates comm
template <class Numeric> class rls {
 private:
  int n, m;
  matrix<Numeric> P;
  vector<Numeric> k;
  vector<Numeric> w, u, ut, x;
  float_type ialpha;
  fir<Numeric, Numeric> cfir;
  typedef typename mixed_type<Numeric, float_type>::dtype k_type;

 public:
  /// Destructor
  ~rls() {}
  /// Constructor
  rls(const int n, float_type alpha) : P(n, n), k(n), w(n), u(n), ut(n), x(n), cfir(n) {
    ialpha = 1.0 / alpha;
    P = (Numeric)0.01;
    k = (Numeric)0;
    w = (Numeric)0;
    u = (Numeric)0;
    ut = (Numeric)0;
    x = (Numeric)0;
  }
  /// Process input sample
  Numeric update(Numeric y) {
    Numeric out = cfir.update(y);
    w = to_vector(get_taps(cfir));
    u = to_vector(get_input(cfir));
    return (out);
  }
  /// Adapt filter
  void adapt(Numeric y) {
    //  k = ialpha*P*u/(1+ialpha*ut*P*u);
    //  w += k*conj(e);
    //  P = ialpha*(P-k*ut*P);
    matrix<Numeric> d;
    vector<Numeric> Pu = P * u;
    Numeric dp = dot(ut, Pu);
    Numeric dwu = dot(w, u);
    k_type den = ialpha * dp;
    k_type denp1 = den + (k_type)(1.0);
    k_type oden = ((k_type)1.0) / denp1;
    k_type k_gain = ialpha * oden;
    k = ((Numeric)k_gain) * (Pu);  // check this!!!!!!!!!!1
    Numeric e = y - dwu;
    w = w + conj(e) * k;
    d = k * (ut * P);
    P = ((Numeric)ialpha) * (P - d);
  }
};
}  // namespace SPUC
