#ifndef FIXED_INT_CLASSES_H_
#define FIXED_INT_CLASSES_H_

#include <cinttypes>

/// fixed point types: spuc_fixed,spuc_ufixed,spuc_int,spuc_uint
namespace SPUC {

/// Similar to Systemc enums
enum spuc_o_mode { SPUC_SAT, SPUC_SAT_SYM, SPUC_WRAP };
enum spuc_q_mode { SPUC_RND, SPUC_TRN };

/// Template functions to use in Compile-time Template Parameters : Absolute
/// Value
template <int A_>
struct Abs_Func {
  enum { val = (A_ < 0) ? -A_ : A_ };
};

// Template functions to compute Masks for Signed/Unsigned bits
template <int A_>
struct SMask {
  enum { val = (1 << (A_ - 1)) - 1 };
};
template <int A_>
struct UMask {
  enum { val = (1 << A_) - 1 };
};

/// Max compile time calculation
template <int A_, int B_>
struct Template_Max {
  enum { maxval = (A_ > B_) ? A_ : B_ };
};
/// Max Total Bits for spuc_fixed based on Max of two different spuc_fixed
template <int T_, int I_, int T1_, int I1_>
struct Template_Max_Total_Bits {
  enum {
    maxval =
        Template_Max<T_ - I_, T1_ - I1_>::maxval + Template_Max<I_, I1_>::maxval
  };
};

/// Use Template parameter to select int type, default is error, should go to
/// one of the specializations below
template <int S_>
struct int_type_size {
  /// will generate compiler error
  static_assert(S_ < 65, " bitwidth is too large > 64");
  // these are for completeness
  typedef uint64_t uint_type;
  typedef int64_t int_type;
};
/// Specialization for 8 bits
template <>
struct int_type_size<8> {
  typedef int8_t int_type;
  typedef uint8_t uint_type;
};
/// Specialization for 16 bits
template <>
struct int_type_size<16> {
  typedef int16_t int_type;
  typedef uint16_t uint_type;
};
/// Specialization for 32 bits
template <>
struct int_type_size<32> {
  typedef int32_t int_type;
  typedef uint32_t uint_type;
};
/// Specialization for 64 bits
template <>
struct int_type_size<64> {
  typedef int64_t int_type;
  typedef uint64_t uint_type;
};
// Not-supported
template <>
struct int_type_size<128> {
  typedef long long int_type;
};

/// For mapping to minimum integer type size
template <int N_VAL>
struct NEXT_INT_SIZE {
  enum {
    val =
        N_VAL <= 8 ? 8 : N_VAL <= 16 ? 16 : N_VAL <= 32
                                                ? 32
                                                : N_VAL <= 64
                                                      ? 64
                                                      : N_VAL <= 128 ? 128 : 256
  };
};

// Forward int/uint types based on bit-width
template <int S_>
struct int_size_needed {
  typedef typename int_type_size<NEXT_INT_SIZE<S_>::val>::uint_type uint_type;
  typedef typename int_type_size<NEXT_INT_SIZE<S_>::val>::int_type int_type;
  int_type val;
  bool operator[](int i) { return ((val & (1 << i)) ? 1 : 0); }
};

/// Possible ranges for bit-widths
typedef int64_t max_int_type;
typedef uint64_t max_uint_type;
}

#endif
