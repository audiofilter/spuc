#ifndef SPUC_UINT
#define SPUC_UINT

// Copyright (c) 2014, Tony Kirke. License: MIT License (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_n_templates
#include <spuc/spuc_types.h>
#include <spuc/int_u.h>
namespace SPUC {
//! \file
//! \brief Template class for unsigned integers (<33 bits).
//
//! \brief Template class for unsigned integers (<33 bits).
//
//! The template parameter
//!   is the number of bits in the integer (default 32)
//!   Derived from base class int_u.
//! \author Tony Kirke
//! \ingroup n_templates base
template <long Bits = 32> class uint : public int_u {
 public:
  bool overflow;

  uint<Bits>() {
    bits = Bits;
    mask = -1 << Bits;
    overflow = 0;
  }
  uint<Bits>(long y) {
    q = y;
    bits = Bits;
    mask = -1 << Bits;
    overflow = 0;
  }
  inline uint<Bits> operator=(const int_u& y) {
    overflow = 0;
    q = y.q;
    if (((mask & q) != mask) || ((mask & q) != 0)) {
      q &= ~mask;
      overflow = 1;
    }
    return *this;
  }
  inline uint<Bits> operator=(const long& y) {
    overflow = 0;
    if (bitpos) {
      if (y)
        q |= MASK_BIT(bitpos);
      else
        q &= ~MASK_BIT(bitpos);
      bitpos = 0;
    } else {
      q = y;
      if (((mask & q) != mask) || ((mask & q) != 0)) {
        q &= ~mask;
        overflow = 1;
      }
    }
    return *this;
  }
  inline uint<Bits> operator()(long i) {
    bitpos = i;
    return *this;
  }
};
// template_instantiations: 5
}  // namespace SPUC
#endif
