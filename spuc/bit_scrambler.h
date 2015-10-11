#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_classes
#include <spuc/spuc_types.h>
namespace SPUC {
//! \file
//! \brief Data scrambler
//
//! \brief Data scrambler
//
//! Does scrambling function on input bits
//! \author Tony Kirke
//! \ingroup classes comm
class bit_scrambler {
 public:
  unsigned long g;
  long span;

 public:
  unsigned long u;
  bit_scrambler(long gen = 0x48, long bits = 7, long uinit = -1) : g(gen), span(bits), u(uinit) { ; }
  void reset() { u = ~0; }
  bool scramble(bool data_in);
  //! Exclusive or reduction
  bool xor_bits(long x);
};
}  // namespace SPUC
