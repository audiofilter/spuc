#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_classes
#include <spuc/spuc_types.h>
namespace SPUC {
//!
//! \file
//! \brief Simple 1st order All-digital Sigma Delta converter
//
//! \brief Simple 1st order All-digital Sigma Delta converter
//
//!    All-digital sigma delta converter
//!    Performs Sigma Delta function in digital domain
//!    for use when output will go to a (nbit_out) D/A converter.
//!    Default is 8 bits in, 1 bit out.
//!    After construction, call single() to get output.
//!    Multirate performed by calling single() with same input
//!    at the higher sampling rate.
//! \author Tony Kirke
//! \ingroup classes misc
class sigma_delta {
 protected:
  signed long in;
  signed long acc;
  unsigned long mask;

 public:
  unsigned char nbit_out;
  unsigned char nbit_in;

  //! Constructor
  sigma_delta(char nin = 8, char nout = 1);
  //! Output <= 8 bits
  signed char single(signed long in);
};
}  // namespace SPUC
