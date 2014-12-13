#ifndef SPUC_MODES_H_
#define SPUC_MODES_H_

#include <spuc/spuc_int.h>
#include <spuc/spuc_uint.h>
#include <spuc/spuc_int_functions.h>
#include <spuc/spuc_uint_functions.h>
#include <spuc/spuc_int_mixed_functions.h>

namespace SPUC {
inline std::string o_mode_string(spuc_o_mode O) {
  switch (O) {
    case SPUC_SAT:
      return ("SPUC_SAT");
      break;
    case SPUC_SAT_SYM:
      return ("SPUC_SAT_SYM");
      break;
    case SPUC_WRAP:
      return ("SPUC_WRAP");
      break;
  }
  return ("ERROR");
}
inline std::string q_mode_string(spuc_q_mode Q) {
  switch (Q) {
    case SPUC_RND:
      return ("SPUC_RND");
      break;
    case SPUC_TRN:
      return ("SPUC_TRN");
      break;
  }
  return ("ERROR");
}
}

#endif
