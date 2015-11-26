#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
#include <spuc/spuc_types.h>
#include <spuc/builtin.h>
#include <spuc/complex.h>
namespace SPUC {
//! \file
//! \brief  base class for a demodulator (not currently used?)
//! \author Tony Kirke
//! \ingroup real_templates sim comm
template <class Numeric> class base_demod {
 public:
  virtual ~base_demod() { ; }
  virtual complex<Numeric> step(complex<Numeric> x) { return (complex<Numeric>(0, 0)); }
  virtual bool sym_pulse() { return (0); }
  virtual bool buffer_empty() { return (0); }
  virtual bool get_bits() { return (0); }
  virtual complex<Numeric> get_taps(int j) { return (complex<Numeric>(0, 0)); }
  virtual int eq_size() { return (0); }
  bool data_ready;
  complex<Numeric> sample_value;
  complex<Numeric> symbol_value;
  char* vers;
};
}  // namespace SPUC
