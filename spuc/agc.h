#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_classes
#include <spuc/spuc_types.h>
#include <spuc/complex.h>
namespace SPUC {
//! \file
//! \brief This is a simple sigma-delta type AGC for the variable rate QPSK example
//
//! \brief This is a simple sigma-delta type AGC for the variable rate QPSK example
//
//! \author Tony Kirke
//! \ingroup classes examples
class agc {
 public:
  long agc_acc;
  long agc_bit;
  long agc_thres;

  agc(long thres = 32);
  long run(complex<long> adc);
};
}  // namespace SPUC
