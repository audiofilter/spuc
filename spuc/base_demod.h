#ifndef SPUC_BASE_DEMOD
#define SPUC_BASE_DEMOD

// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_real_templates
#include <spuc/spuc_types.h>
#include <spuc/builtin.h>
#include <spuc/fundtype.h>
#include <spuc/complex.h>
namespace SPUC {
//! \file
//! \brief  base class for a demodulator (not currently used?)
//
//! \brief  base class for a demodulator (not currently used?)
//! \author Tony Kirke
//! \ingroup real_templates sim comm
template <class Numeric> class base_demod {
 public:
  typedef typename fundtype<Numeric>::ftype CNumeric;

  virtual ~base_demod() { ; }
  virtual complex<CNumeric> step(complex<CNumeric> x) { return (complex<CNumeric>(0, 0)); }
  virtual bool sym_pulse() { return (0); }
  virtual bool buffer_empty() { return (0); }
  virtual bool get_bits() { return (0); }
  virtual complex<CNumeric> get_taps(int j) { return (complex<CNumeric>(0, 0)); }
  virtual int eq_size() { return (0); }
  bool data_ready;
  complex<CNumeric> sample_value;
  complex<CNumeric> symbol_value;
  char* vers;
};
}  // namespace SPUC
#endif
