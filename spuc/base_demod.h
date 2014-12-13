#ifndef SPUC_BASE_DEMOD
#define SPUC_BASE_DEMOD

/*
    Copyright (C) 2014 Tony Kirke

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
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
template <class Numeric>
class base_demod {
 public:
  typedef typename fundtype<Numeric>::ftype CNumeric;

  virtual ~base_demod() { ; }
  virtual complex<CNumeric> step(complex<CNumeric> x) {
    return (complex<CNumeric>(0, 0));
  }
  virtual bool sym_pulse() { return (0); }
  virtual bool buffer_empty() { return (0); }
  virtual bool get_bits() { return (0); }
  virtual complex<CNumeric> get_taps(int j) {
    return (complex<CNumeric>(0, 0));
  }
  virtual int eq_size() { return (0); }
  bool data_ready;
  complex<CNumeric> sample_value;
  complex<CNumeric> symbol_value;
  char* vers;
};
}  // namespace SPUC
#endif
