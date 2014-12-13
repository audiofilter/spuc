//////////////////////////////////////////////////////////////////////////////
// Copyright© 2014. Author : Tony Kirke. All right reserverd.
//////////////////////////////////////////////////////////////////////////////

#ifndef SPUC_FIXED_20140509_CLASS_H_
#define SPUC_FIXED_20140509_CLASS_H_

#include <SPUC/spuc_int_types.h>
#include <SPUC/spuc_fixed_roundsat.h>
namespace SPUC {

/// A fast & lightweight fixed-point class
template <int TOTAL_BITS_, int INT_BITS_, spuc_q_mode SPUC_Q_MODE_ = SPUC_TRN,
          spuc_o_mode SPUC_O_MODE_ = SPUC_WRAP>
class spuc_fixed {
  static_assert(TOTAL_BITS_ < 65, " bitwidth is too large > 64");

 public:  // should be private?
  typedef spuc_int<TOTAL_BITS_> val_type;
  typedef int64_t max_val_type;
  val_type val;
  static const int TOTAL_BITS = TOTAL_BITS_;
  static const int INTEGER_BITS = INT_BITS_;

 public:
  /// constructors
  spuc_fixed() : val(0) {}
  spuc_fixed(double a) { from_double(a); }
  /// built-in types
  template <int W>
  spuc_fixed(const spuc_int<W> &a) {
    from_int(a.to_int());
  }
  template <int W>
  spuc_fixed(const spuc_uint<W> &a) {
    from_uint(a.to_int());
  }

  // Constructors (generated)
  spuc_fixed(int8_t a) { from_int(a); }
  spuc_fixed(int16_t a) { from_int(a); }
  spuc_fixed(int32_t a) { from_int(a); }
  spuc_fixed(int64_t a) { from_int(a); }
  spuc_fixed(uint8_t a) { from_uint(a); }
  spuc_fixed(uint16_t a) { from_uint(a); }
  spuc_fixed(uint32_t a) { from_uint(a); }
  spuc_fixed(uint64_t a) { from_uint(a); }

  /// From exact same type - just copy val
  spuc_fixed(const spuc_fixed &a) : val(a.getVal()) {}
  /// from another spuc_fixed<>
  template <int TOTAL_BITS_1, int INT_BITS_1, spuc_q_mode SPUC_Q_MODE_1,
            spuc_o_mode SPUC_O_MODE_1>
  spuc_fixed(const spuc_fixed<TOTAL_BITS_1, INT_BITS_1, SPUC_Q_MODE_1,
                              SPUC_O_MODE_1> &a) {
    // Combine separate round and saturates
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        spuc_shift_class_function<TOTAL_BITS_ - INT_BITS_,
                                  SPUC_Q_MODE_>::shift_function(a));
  }
  /// from spuc_ufixed<>
  template <int TOTAL_BITS_1, int INT_BITS_1, spuc_q_mode SPUC_Q_MODE_1,
            spuc_o_mode SPUC_O_MODE_1>
  spuc_fixed(const spuc_ufixed<TOTAL_BITS_1, INT_BITS_1, SPUC_Q_MODE_1,
                               SPUC_O_MODE_1> &a) {
    // Combine separate round and saturates
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        spuc_shift_class_function<TOTAL_BITS_ - INT_BITS_,
                                  SPUC_Q_MODE_>::shift_function(a));
  }

  /// should not be needed later
  val_type getVal() const { return (val); }

  /// Conversions
  void from_double(double x) {
    val = (val_type)floor(x * ((max_val_type)1 << (TOTAL_BITS_ - INT_BITS_)) +
                          0.5 * (SPUC_Q_MODE_ == SPUC_RND));
  }

  /// Conversions
  template <typename T_>
  void from_int(T_ x) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        ((max_val_type)x << (TOTAL_BITS_ - INT_BITS_)));
  }

  template <typename T_>
  void from_uint(T_ x) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        ((max_val_type)x << (TOTAL_BITS_ - INT_BITS_)));
  }

  double to_double(void) const {
    double y = ((double)val) / ((uint64_t)1 << (TOTAL_BITS_ - INT_BITS_));
    return (y);
  }
  int64_t to_int(void) const {
    return (int64_t)spuc_round_class_function<SPUC_Q_MODE_>::round(
        val, TOTAL_BITS_ - INT_BITS_);
  }

  /// Allow conversion to double for simulation
  operator double() const { return (to_double()); }
  /// Conversion to int type for comparing to ints
  operator val_type() const { return (val >> (TOTAL_BITS_ - INT_BITS_)); }
  /// conversion to bool
  bool operator!() const { return (val == 0); }
  //////operator bool() const { return(val != 0); }

  spuc_fixed &operator++() {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        val + (1 << (TOTAL_BITS_ - INT_BITS_)));
    return *this;
  }
  spuc_fixed operator++(int) {
    spuc_fixed tmp(*this);
    ++*this;
    return (tmp);
  }
  spuc_fixed &operator--() {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        val - (1 << (TOTAL_BITS_ - INT_BITS_)));
    return *this;
  }
  spuc_fixed operator--(int) {
    spuc_fixed tmp(*this);
    --*this;
    return (tmp);
  }

  /// assignment operator, just copy the only member variable - no checks!
  spuc_fixed &operator=(const spuc_fixed &a) {
    val = a.getVal();
    return *this;
  }

  /// assignment operator from another size, use copy constructor, then copy
  /// val;
  template <int TOTAL_BITS_1, int INT_BITS_1, spuc_q_mode SPUC_Q_MODE_1,
            spuc_o_mode SPUC_O_MODE_1>
  spuc_fixed<TOTAL_BITS_, INT_BITS_, SPUC_Q_MODE_, SPUC_O_MODE_> &operator=(
      const spuc_fixed<TOTAL_BITS_1, INT_BITS_1, SPUC_Q_MODE_1, SPUC_O_MODE_1> &
          a) {
    spuc_fixed<TOTAL_BITS_, INT_BITS_, SPUC_Q_MODE_, SPUC_O_MODE_> temp(a);
    val = temp.getVal();
    return *this;
  }

  ///
  template <int TOTAL_BITS_1, int INT_BITS_1, spuc_q_mode SPUC_Q_MODE_1,
            spuc_o_mode SPUC_O_MODE_1>
  spuc_fixed<TOTAL_BITS_, INT_BITS_, SPUC_Q_MODE_, SPUC_O_MODE_> &operator=(
      const spuc_ufixed<TOTAL_BITS_1, INT_BITS_1, SPUC_Q_MODE_1,
                        SPUC_O_MODE_1> &a) {
    spuc_fixed<TOTAL_BITS_, INT_BITS_, SPUC_Q_MODE_, SPUC_O_MODE_> temp(a);
    val = temp.getVal();
    return *this;
  }
  /// assignment operator from spuc_int
  template <int W_1>
  spuc_fixed<TOTAL_BITS_, INT_BITS_, SPUC_Q_MODE_, SPUC_O_MODE_> &operator=(
      const spuc_int<W_1> &a) {
    // saturates
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        max_int_type(a.to_int()));
    return *this;
  }
  /// assignment operator from spuc_int
  template <int W_1>
  spuc_fixed<TOTAL_BITS_, INT_BITS_, SPUC_Q_MODE_, SPUC_O_MODE_> &operator=(
      const spuc_uint<W_1> &a) {
    // saturates
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        max_int_type(a.to_int()));
    return *this;
  }

  /// sign operator - return spuc_fixed
  spuc_fixed<TOTAL_BITS_ + 1, INT_BITS_ + 1> operator-() const {
    spuc_fixed<TOTAL_BITS_ + 1, INT_BITS_ + 1> tmp;
    tmp.val = val;
    tmp.multm1();
    return tmp;
  }
  /// bit flip
  spuc_fixed operator~() const {
    spuc_fixed tmp(*this);
    tmp.flip();
    return (tmp);
  }
  // Assign from different built-in types
  // Assignment operators of various types
  spuc_fixed &operator=(const int8_t &a) {
    *this = spuc_fixed(a);
    return *this;
  }
  spuc_fixed &operator=(const int16_t &a) {
    *this = spuc_fixed(a);
    return *this;
  }
  spuc_fixed &operator=(const int32_t &a) {
    *this = spuc_fixed(a);
    return *this;
  }
  spuc_fixed &operator=(const int64_t &a) {
    *this = spuc_fixed(a);
    return *this;
  }
  spuc_fixed &operator=(const uint8_t &a) {
    *this = spuc_fixed(a);
    return *this;
  }
  spuc_fixed &operator=(const uint16_t &a) {
    *this = spuc_fixed(a);
    return *this;
  }
  spuc_fixed &operator=(const uint32_t &a) {
    *this = spuc_fixed(a);
    return *this;
  }
  spuc_fixed &operator=(const uint64_t &a) {
    *this = spuc_fixed(a);
    return *this;
  }
  spuc_fixed &operator=(const double &a) {
    *this = spuc_fixed(a);
    return *this;
  }

  template <int TOTAL_BITS_1, int INT_BITS_1, spuc_q_mode SPUC_Q_MODE_1,
            spuc_o_mode SPUC_O_MODE_1>
  spuc_fixed &operator+=(const spuc_fixed<TOTAL_BITS_1, INT_BITS_1,
                                          SPUC_Q_MODE_1, SPUC_O_MODE_1> &a) {
    spuc_fixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1,
                                       INT_BITS_1>::maxval +
                   1,
               Template_Max<INT_BITS_, INT_BITS_1>::maxval + 1, SPUC_Q_MODE_1,
               SPUC_O_MODE_1>
        tmp(*this);  // just extra headroom above and below
    spuc_fixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1,
                                       INT_BITS_1>::maxval +
                   1,
               Template_Max<INT_BITS_, INT_BITS_1>::maxval + 1, SPUC_Q_MODE_1,
               SPUC_O_MODE_1> tmpa(a);  // just extra headroom above and below
    tmpa.val += tmp.val;                // no saturation or rounding yet;
    *this = tmpa;                       // now saturate + round
    return *this;
  }
  template <int TOTAL_BITS_1, int INT_BITS_1, spuc_q_mode SPUC_Q_MODE_1,
            spuc_o_mode SPUC_O_MODE_1>
  spuc_fixed &operator+=(const spuc_ufixed<TOTAL_BITS_1, INT_BITS_1,
                                           SPUC_Q_MODE_1, SPUC_O_MODE_1> &a) {
    spuc_fixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1,
                                       INT_BITS_1>::maxval +
                   2,
               Template_Max<INT_BITS_, INT_BITS_1>::maxval + 2, SPUC_Q_MODE_1,
               SPUC_O_MODE_1>
        tmp(*this);  // just extra headroom above and below
    spuc_fixed<Template_Max_Total_Bits<TOTAL_BITS_, INT_BITS_, TOTAL_BITS_1,
                                       INT_BITS_1>::maxval +
                   2,
               Template_Max<INT_BITS_, INT_BITS_1>::maxval + 2, SPUC_Q_MODE_1,
               SPUC_O_MODE_1> tmpa(a);  // just extra headroom above and below
    tmpa.val += tmp.val;                // no saturation or rounding yet;
    *this = tmpa;                       // now saturate + round
    return *this;
  }

  template <int TOTAL_BITS_1, int INT_BITS_1, spuc_q_mode SPUC_Q_MODE_1,
            spuc_o_mode SPUC_O_MODE_1>
  spuc_fixed &operator-=(const spuc_fixed<TOTAL_BITS_1, INT_BITS_1,
                                          SPUC_Q_MODE_1, SPUC_O_MODE_1> &a) {
    *this += (-a);  // re-use +=
    return *this;
  }
  template <int TOTAL_BITS_1, int INT_BITS_1, spuc_q_mode SPUC_Q_MODE_1,
            spuc_o_mode SPUC_O_MODE_1>
  spuc_fixed &operator-=(const spuc_ufixed<TOTAL_BITS_1, INT_BITS_1,
                                           SPUC_Q_MODE_1, SPUC_O_MODE_1> &a) {
    *this += (-a);  // re-use +=
    return *this;
  }

  template <int TOTAL_BITS_1, int INT_BITS_1, spuc_q_mode SPUC_Q_MODE_1,
            spuc_o_mode SPUC_O_MODE_1>
  spuc_fixed &operator*=(const spuc_fixed<TOTAL_BITS_1, INT_BITS_1,
                                          SPUC_Q_MODE_1, SPUC_O_MODE_1> &b) {
    // first full precision
    spuc_fixed<(TOTAL_BITS_ + TOTAL_BITS_1), (INT_BITS_ + INT_BITS_1),
               SPUC_Q_MODE_, SPUC_O_MODE_> tmp = *this * b;
    // now assign from larger type
    *this = tmp;
    return *this;
  }

  template <int TOTAL_BITS_1, int INT_BITS_1, spuc_q_mode SPUC_Q_MODE_1,
            spuc_o_mode SPUC_O_MODE_1>
  spuc_fixed &operator*=(const spuc_ufixed<TOTAL_BITS_1, INT_BITS_1,
                                           SPUC_Q_MODE_1, SPUC_O_MODE_1> &b) {
    // first full precision
    spuc_fixed<(TOTAL_BITS_ + TOTAL_BITS_1), (INT_BITS_ + INT_BITS_1),
               SPUC_Q_MODE_, SPUC_O_MODE_> tmp = *this * b;
    // now assign from larger type
    *this = tmp;
    return *this;
  }
  /// Divide uses conversion back and forth to double for intermediate values
  template <int TOTAL_BITS_1, int INT_BITS_1>
  spuc_fixed &operator/=(const spuc_fixed<TOTAL_BITS_1, INT_BITS_1> &b) {
    from_double(to_double() / b.to_double);
    return *this;
  }
  /// "+= and -=" from different built-in types

  // More assignment operators for +=,-=
  spuc_fixed &operator+=(const double &a) {
    spuc_fixed tmp(a);
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        val + tmp.getVal());
    return *this;
  }
  spuc_fixed &operator-=(const double &a) {
    spuc_fixed tmp(a);
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        val - tmp.getVal());
    return *this;
  }

  // More assignment operators for +=,-= (other types)
  spuc_fixed &operator+=(const int8_t &a) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        val + (a << (TOTAL_BITS_ - INT_BITS_)));
    return *this;
  }
  spuc_fixed &operator-=(const int8_t &a) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        val - (a << (TOTAL_BITS_ - INT_BITS_)));
    return *this;
  }
  spuc_fixed &operator+=(const int16_t &a) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        val + (a << (TOTAL_BITS_ - INT_BITS_)));
    return *this;
  }
  spuc_fixed &operator-=(const int16_t &a) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        val - (a << (TOTAL_BITS_ - INT_BITS_)));
    return *this;
  }
  spuc_fixed &operator+=(const int32_t &a) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        val + (a << (TOTAL_BITS_ - INT_BITS_)));
    return *this;
  }
  spuc_fixed &operator-=(const int32_t &a) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        val - (a << (TOTAL_BITS_ - INT_BITS_)));
    return *this;
  }
  spuc_fixed &operator+=(const int64_t &a) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        val + (a << (TOTAL_BITS_ - INT_BITS_)));
    return *this;
  }
  spuc_fixed &operator-=(const int64_t &a) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        val - (a << (TOTAL_BITS_ - INT_BITS_)));
    return *this;
  }
  spuc_fixed &operator+=(const uint8_t &a) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        val + (a << (TOTAL_BITS_ - INT_BITS_)));
    return *this;
  }
  spuc_fixed &operator-=(const uint8_t &a) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        val - (a << (TOTAL_BITS_ - INT_BITS_)));
    return *this;
  }
  spuc_fixed &operator+=(const uint16_t &a) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        val + (a << (TOTAL_BITS_ - INT_BITS_)));
    return *this;
  }
  spuc_fixed &operator-=(const uint16_t &a) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        val - (a << (TOTAL_BITS_ - INT_BITS_)));
    return *this;
  }
  spuc_fixed &operator+=(const uint32_t &a) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        val + (a << (TOTAL_BITS_ - INT_BITS_)));
    return *this;
  }
  spuc_fixed &operator-=(const uint32_t &a) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        val - (a << (TOTAL_BITS_ - INT_BITS_)));
    return *this;
  }
  spuc_fixed &operator+=(const uint64_t &a) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        val + (a << (TOTAL_BITS_ - INT_BITS_)));
    return *this;
  }
  spuc_fixed &operator-=(const uint64_t &a) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        val - (a << (TOTAL_BITS_ - INT_BITS_)));
    return *this;
  }

  // Multiply/Divide Assignments
  spuc_fixed &operator*=(const int8_t &a) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        int64_t(floor(val * a + 0.5)));
    return *this;
  }
  spuc_fixed &operator/=(const int8_t &a) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        int64_t(floor(val / a + 0.5)));
    return *this;
  }
  spuc_fixed &operator*=(const int16_t &a) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        int64_t(floor(val * a + 0.5)));
    return *this;
  }
  spuc_fixed &operator/=(const int16_t &a) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        int64_t(floor(val / a + 0.5)));
    return *this;
  }
  spuc_fixed &operator*=(const int32_t &a) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        int64_t(floor(val * a + 0.5)));
    return *this;
  }
  spuc_fixed &operator/=(const int32_t &a) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        int64_t(floor(val / a + 0.5)));
    return *this;
  }
  spuc_fixed &operator*=(const int64_t &a) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        int64_t(floor(val * a + 0.5)));
    return *this;
  }
  spuc_fixed &operator/=(const int64_t &a) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        int64_t(floor(val / a + 0.5)));
    return *this;
  }
  spuc_fixed &operator*=(const uint8_t &a) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        int64_t(floor(val * a + 0.5)));
    return *this;
  }
  spuc_fixed &operator/=(const uint8_t &a) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        int64_t(floor(val / a + 0.5)));
    return *this;
  }
  spuc_fixed &operator*=(const uint16_t &a) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        int64_t(floor(val * a + 0.5)));
    return *this;
  }
  spuc_fixed &operator/=(const uint16_t &a) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        int64_t(floor(val / a + 0.5)));
    return *this;
  }
  spuc_fixed &operator*=(const uint32_t &a) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        int64_t(floor(val * a + 0.5)));
    return *this;
  }
  spuc_fixed &operator/=(const uint32_t &a) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        int64_t(floor(val / a + 0.5)));
    return *this;
  }
  spuc_fixed &operator*=(const uint64_t &a) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        int64_t(floor(val * a + 0.5)));
    return *this;
  }
  spuc_fixed &operator/=(const uint64_t &a) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        int64_t(floor(val / a + 0.5)));
    return *this;
  }
  spuc_fixed &operator*=(const double &a) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        int64_t(floor(val * a + 0.5)));
    return *this;
  }
  spuc_fixed &operator/=(const double &a) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        int64_t(floor(val / a + 0.5)));
    return *this;
  }

  /// Left shifts + assign
  template <int W>
  spuc_fixed &operator<<=(spuc_int<W> shift) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        (max_val_type)val << shift.to_int());
    return *this;
  }
  template <int W>
  spuc_fixed &operator<<=(spuc_uint<W> shift) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        (max_val_type)val << shift.to_int());
    return *this;
  }

  /// Right shifts + assign
  template <int W>
  spuc_fixed &operator>>=(spuc_int<W> shift) {
    val >>= shift.to_int();
    return *this;
  }
  template <int W>
  spuc_fixed &operator>>=(spuc_uint<W> shift) {
    val >>= shift.to_int();
    return *this;
  }

  // Right Shift Assigns other types
  spuc_fixed &operator>>=(const int8_t &shift) {
    val = spuc_round_class_function<SPUC_Q_MODE_>::round(val, shift);
    return *this;
  }
  spuc_fixed &operator>>=(const int16_t &shift) {
    val = spuc_round_class_function<SPUC_Q_MODE_>::round(val, shift);
    return *this;
  }
  spuc_fixed &operator>>=(const int32_t &shift) {
    val = spuc_round_class_function<SPUC_Q_MODE_>::round(val, shift);
    return *this;
  }
  spuc_fixed &operator>>=(const int64_t &shift) {
    val = spuc_round_class_function<SPUC_Q_MODE_>::round(val, shift);
    return *this;
  }
  spuc_fixed &operator>>=(const uint8_t &shift) {
    val = spuc_round_class_function<SPUC_Q_MODE_>::round(val, shift);
    return *this;
  }
  spuc_fixed &operator>>=(const uint16_t &shift) {
    val = spuc_round_class_function<SPUC_Q_MODE_>::round(val, shift);
    return *this;
  }
  spuc_fixed &operator>>=(const uint32_t &shift) {
    val = spuc_round_class_function<SPUC_Q_MODE_>::round(val, shift);
    return *this;
  }
  spuc_fixed &operator>>=(const uint64_t &shift) {
    val = spuc_round_class_function<SPUC_Q_MODE_>::round(val, shift);
    return *this;
  }

  // Left Shift Assigns other types
  spuc_fixed &operator<<=(int8_t shift) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        (max_val_type)val << shift);
    return *this;
  }
  spuc_fixed &operator<<=(int16_t shift) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        (max_val_type)val << shift);
    return *this;
  }
  spuc_fixed &operator<<=(int32_t shift) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        (max_val_type)val << shift);
    return *this;
  }
  spuc_fixed &operator<<=(int64_t shift) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        (max_val_type)val << shift);
    return *this;
  }
  spuc_fixed &operator<<=(uint8_t shift) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        (max_val_type)val << shift);
    return *this;
  }
  spuc_fixed &operator<<=(uint16_t shift) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        (max_val_type)val << shift);
    return *this;
  }
  spuc_fixed &operator<<=(uint32_t shift) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        (max_val_type)val << shift);
    return *this;
  }
  spuc_fixed &operator<<=(uint64_t shift) {
    val = spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(
        (max_val_type)val << shift);
    return *this;
  }

  /// boolean operators for same type
  bool operator==(const spuc_fixed &a) const { return ((val == a.getVal())); }
  bool operator!=(const spuc_fixed &a) const { return ((val != a.getVal())); }
  bool operator<(const spuc_fixed &a) const { return ((val < a.getVal())); }
  bool operator>(const spuc_fixed &a) const { return ((val > a.getVal())); }
  bool operator<=(const spuc_fixed &a) const { return ((val <= a.getVal())); }
  bool operator>=(const spuc_fixed &a) const { return ((val >= a.getVal())); }

  // Misc member functions
  val_type getInt() const { return (val >> (TOTAL_BITS_ - INT_BITS_)); }
  val_type getFrac() const {
    return (val - (getInt() << (TOTAL_BITS_ - INT_BITS_)));
  }
  void init_max() { val = ((val_type)1 << (TOTAL_BITS_ - 1)) - 1; }
  void init_min() { val = -((val_type)1 << (TOTAL_BITS_ - 1)); }

  // Legitimately directly set integer part
  void setVal(int a) { val = val_type(a); }

  void multm1() { val = -val; }
  void flip() {
    val =
        spuc_saturate_class_function<TOTAL_BITS_, SPUC_O_MODE_>::saturate(~val);
  }

  bool is_neg() const { return (val < 0); }
  /// Check for zero
  bool is_zero() const { return (val == 0); }

  /// Return Quantization mode
  spuc_q_mode q_mode() const { return (SPUC_Q_MODE_); }
  /// Return Overflow mode
  spuc_o_mode o_mode() const { return (SPUC_O_MODE_); }

  std::string type_params() {
    std::stringstream s;
    s << "(" << TOTAL_BITS_ << "," << INT_BITS_ << ","
      << q_mode_string(q_mode()) << "," << o_mode_string(o_mode()) << ")";
    return (s.str());
  }

  void print(std::ostream &os = ::std::cout) const { os << to_double(); }

};  // end of class

}  // end of namespace SPUC

#include <SPUC/spuc_fixed_functions.h>
#include <SPUC/spuc_mixed_functions.h>

#endif
