
// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_vector
using namespace std;
#include <spuc/matrix.h>
namespace SPUC {

template matrix<double> operator+(const matrix<double> &m1, const matrix<double> &m2);
template matrix<double> operator+(const matrix<double> &m, double t);
template matrix<double> operator+(double t, const matrix<double> &m);
template matrix<double> operator-(const matrix<double> &m1, const matrix<double> &m2);
template matrix<double> operator-(const matrix<double> &m, double t);
template matrix<double> operator-(double t, const matrix<double> &m);
template matrix<double> operator-(const matrix<double> &m);
template matrix<double> operator*(const matrix<double> &m, double t);
template matrix<double> operator*(double t, const matrix<double> &m);

}  // namespace SPUC
