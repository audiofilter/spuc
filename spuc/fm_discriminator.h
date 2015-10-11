#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_classes
#include <spuc/spuc_types.h>
#include <spuc/complex.h>
namespace SPUC {
class fm_discriminator {
 public:
  float_type phase;

  fm_discriminator() { phase = 0; }

  //! \brief FM Demodulate a signal
  float_type sample(complex<float_type> in);
};
}  // namespace SPUC
