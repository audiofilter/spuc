#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_classes
#include <spuc/spuc_types.h>
#include <spuc/complex.h>
namespace SPUC {
//! \file
//! \brief Gaussian noise routine
//
//! \brief Gaussian noise routine
//
//!  Can create (float_type) gaussian white noise,
//!             <p>complex<float_type> gaussian white noise
//!             <p>or (float_type) uniform noise
//!  <p>Requires complex template class
//! \author Tony Kirke
//! \ingroup classes misc random
class noise {
 protected:
  char s;        //! Switch
  float_type x;  //! Saved calculated value
  long idum;     //! Random seed

 public:
  //! Constructor
  noise(float_type i = 1349555.0);  // Constructor
  //! Gaussian noise
  float_type gauss();
  //! complex gaussian noise
  complex<float_type> Cgauss(void);
  //! Uniform noise
  float_type uni();
  //! Uniform noise
  float_type uniform();
  //!  Change seed
  //	void set_seed(float_type i=1349555.0) { idum = (long)i;}
  //!  Change seed
  void set_seed(unsigned i = 1349555) { idum = i; }
};
}  // namespace SPUC
