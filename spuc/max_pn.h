#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_classes
#include <spuc/spuc_types.h>
namespace SPUC {
//!
//! \file
//! \brief Maximal Length Pseudorandom sequence generator
//
//! \brief Maximal Length Pseudorandom sequence generator
//
//!    Simple implementation of a maximal length pseudorandom sequence
//!    used for spread spectrum PN generation, BER testing etc.
//!    G is the generator
//!    Len is the PN length (must be 2^N - 1)
//!    Init is an initialization seed
//!    Two methods supported
//!    out : exclusive or (XOR) shift register with Generator
//!    out1 : feedback with XOR reduction
//!    Note: G, LEN must be correct (need to get from book).
//! \author Tony Kirke
//! \ingroup classes misc
class max_pn {
 protected:
  int lenp1;
  int gen;
  int u;

 public:
  //! Constructor
  //! Constructor
  max_pn(int g = 0x006d, int len = 63, int init = -1) {
    gen = g;
    lenp1 = len + 1;
    u = init;
  }
  //		max_pn(int g=0x074d, int len=1023, int init=-1) : gen(g), lenp1(len+1), u(init) {;}
  //! Reset
  void reset() { u = -1; }
  //! Get output (fast method)
  signed char out();  //! Fast method
  bool get_bit();     //! returns {0,1} instead of {-1,1}
  //! Get output (alternative method)
  signed char out1();
  int state() { return (u); }
};
}  // namespace SPUC
