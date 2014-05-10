//////////////////////////////////////////////////////////////////////////////
// Copyright© 2014. Original Author : Tony Kirke. All rights reserved.

//////////////////////////////////////////////////////////////////////////////
#ifndef SPUC_FIXED_20140509_ROUNDSAT_H_
#define SPUC_FIXED_20140509_ROUNDSAT_H_

// Type for smallest intX_t type needed for B bits such as int16_t for 12 bits
// rounding helper class - specialized for each round TYPE
// saturation helper class - specialized for each sat TYPE
// these allow generic use within spuc_fixed class

namespace SPUC {

// forward declaration
#ifndef DOXYGEN_SHOULD_SKIP_THIS
template <int TOTAL_BITS_, int FRAC_BITS_, spuc_q_mode SPUC_Q_MODE_,
          spuc_o_mode SPUC_O_MODE_>
class spuc_fixed;
template <int TOTAL_BITS_, int FRAC_BITS_, spuc_q_mode SPUC_Q_MODE_,
          spuc_o_mode SPUC_O_MODE_>
class spuc_ufixed;
#endif

/// A template class to wrap "round" functions that can be specialized for
/// fixed-point types
template <spuc_q_mode Q_> class spuc_round_class_function {
public:
  // Default round function is truncate!!!
  template <typename T_, typename TS_> T_ round(const T_ &a, const TS_ &shift) {
    T_ x = a >> shift;
    return (x);
  }
}; // end of class
/// round return type one extra bit to avoid overflow,specialize other forms as
/// needed
template <> class spuc_round_class_function<SPUC_RND> {
public:
  /// Specialized round function for SPUC_RND
  template <typename T_, typename TS_>
  static T_ round(const T_ &a, const TS_ &shift) {
    T_ x = a >> shift;
    if (shift > 0)
      x += (a >> (shift - 1)) & 0x1;
    return (x);
  }
};
/// Specialization for SPUC_TRN
template <> class spuc_round_class_function<SPUC_TRN> {
public:
  /// Specialized round function for SPUC_TRN
  template <typename T_, typename TS_>
  static T_ round(const T_ &a, const TS_ &shift) {
    T_ x = a >> shift;
    return (x);
  }
};

/// A template class to wrap "shift" functions that can be specialized for
/// fixed-point types
template <int FRAC_BITS_, spuc_q_mode Q_> class spuc_shift_class_function {
public:
  /// Default shift function is truncate!!!
  template <int TOTAL_BITS_1, int INT_BITS_1, spuc_q_mode SPUC_Q_MODE_1,
            spuc_o_mode SPUC_O_MODE_1>
  static typename int_size_needed<
      INT_BITS_1 +
      Template_Max<TOTAL_BITS_1 - INT_BITS_1, FRAC_BITS_>::maxval>::int_type
  shift_function(const spuc_fixed<TOTAL_BITS_1, INT_BITS_1, SPUC_Q_MODE_1,
                                  SPUC_O_MODE_1> &a) {
    typename int_size_needed<INT_BITS_1 +
                             Template_Max<TOTAL_BITS_1 - INT_BITS_1,
                                          FRAC_BITS_>::maxval>::int_type x;
    if (TOTAL_BITS_1 - INT_BITS_1 > FRAC_BITS_) {
      x = (a.getVal() >>
           (int)Abs_Func<TOTAL_BITS_1 - INT_BITS_1 - FRAC_BITS_>::val);
    } else {
      x = (a.getVal() << (int)
           Abs_Func<TOTAL_BITS_1 - INT_BITS_1 - FRAC_BITS_>::val);
    }
    return (x);
  }
  template <int TOTAL_BITS_1, int INT_BITS_1, spuc_q_mode SPUC_Q_MODE_1,
            spuc_o_mode SPUC_O_MODE_1>
  static typename int_size_needed<
      INT_BITS_1 +
      Template_Max<TOTAL_BITS_1 - INT_BITS_1, FRAC_BITS_>::maxval>::int_type
  shift_function(const spuc_ufixed<TOTAL_BITS_1, INT_BITS_1, SPUC_Q_MODE_1,
                                   SPUC_O_MODE_1> &a) {
    typename int_size_needed<INT_BITS_1 +
                             Template_Max<TOTAL_BITS_1 - INT_BITS_1,
                                          FRAC_BITS_>::maxval>::int_type x;
    if (TOTAL_BITS_1 - INT_BITS_1 > FRAC_BITS_) {
      x = (a.getVal() >>
           (int)Abs_Func<TOTAL_BITS_1 - INT_BITS_1 - FRAC_BITS_>::val);
    } else {
      x = (a.getVal() << (int)
           Abs_Func<TOTAL_BITS_1 - INT_BITS_1 - FRAC_BITS_>::val);
    }
    return (x);
  }
}; // end of class
/// Specialize for SPUC_RND shift return type one extra bit to avoid overflow,
template <int FRAC_BITS_>
class spuc_shift_class_function<FRAC_BITS_, SPUC_RND> {
public:
  /// Specialized shift function for SPUC_RND
  template <int TOTAL_BITS_1, int INT_BITS_1, spuc_q_mode SPUC_Q_MODE_1,
            spuc_o_mode SPUC_O_MODE_1>
  static typename int_size_needed<
      INT_BITS_1 +
      Template_Max<TOTAL_BITS_1 - INT_BITS_1, FRAC_BITS_>::maxval>::int_type
  shift_function(const spuc_fixed<TOTAL_BITS_1, INT_BITS_1, SPUC_Q_MODE_1,
                                  SPUC_O_MODE_1> &a) {
    typename int_size_needed<INT_BITS_1 +
                             Template_Max<TOTAL_BITS_1 - INT_BITS_1,
                                          FRAC_BITS_>::maxval>::int_type x;
    if (TOTAL_BITS_1 - INT_BITS_1 > FRAC_BITS_) {
      x = (a.getVal() >>
           (int)Abs_Func<TOTAL_BITS_1 - INT_BITS_1 - FRAC_BITS_>::val);
      if ((TOTAL_BITS_1 - INT_BITS_1) > FRAC_BITS_)
        x += (a.getVal() >>
              (int)Abs_Func<TOTAL_BITS_1 - INT_BITS_1 - FRAC_BITS_ - 1>::val) &
             0x1;
    } else {
      x = (a.getVal() << (int)
           Abs_Func<TOTAL_BITS_1 - INT_BITS_1 - FRAC_BITS_>::val);
    }
    return (x);
  }
  template <int TOTAL_BITS_1, int INT_BITS_1, spuc_q_mode SPUC_Q_MODE_1,
            spuc_o_mode SPUC_O_MODE_1>
  static typename int_size_needed<
      INT_BITS_1 +
      Template_Max<TOTAL_BITS_1 - INT_BITS_1, FRAC_BITS_>::maxval>::int_type
  shift_function(const spuc_ufixed<TOTAL_BITS_1, INT_BITS_1, SPUC_Q_MODE_1,
                                   SPUC_O_MODE_1> &a) {
    typename int_size_needed<INT_BITS_1 +
                             Template_Max<TOTAL_BITS_1 - INT_BITS_1,
                                          FRAC_BITS_>::maxval>::int_type x;
    if (TOTAL_BITS_1 - INT_BITS_1 > FRAC_BITS_) {
      x = (a.getVal() >>
           (int)Abs_Func<TOTAL_BITS_1 - INT_BITS_1 - FRAC_BITS_>::val);
      if ((TOTAL_BITS_1 - INT_BITS_1) > FRAC_BITS_)
        x += (a.getVal() >>
              (int)Abs_Func<TOTAL_BITS_1 - INT_BITS_1 - FRAC_BITS_ - 1>::val) &
             0x1;
    } else {
      x = (a.getVal() << (int)
           Abs_Func<TOTAL_BITS_1 - INT_BITS_1 - FRAC_BITS_>::val);
    }
    return (x);
  }
};
/// Specialize for SPUC_TRN shift return type one extra bit to avoid overflow,
template <int FRAC_BITS_>
class spuc_shift_class_function<FRAC_BITS_, SPUC_TRN> {
public:
  // Specialized shift function for SPUC_TRN
  template <int TOTAL_BITS_1, int INT_BITS_1, spuc_q_mode SPUC_Q_MODE_1,
            spuc_o_mode SPUC_O_MODE_1>
  static typename int_size_needed<
      INT_BITS_1 +
      Template_Max<TOTAL_BITS_1 - INT_BITS_1, FRAC_BITS_>::maxval>::int_type
  shift_function(const spuc_fixed<TOTAL_BITS_1, INT_BITS_1, SPUC_Q_MODE_1,
                                  SPUC_O_MODE_1> &a) {
    typename int_size_needed<INT_BITS_1 +
                             Template_Max<TOTAL_BITS_1 - INT_BITS_1,
                                          FRAC_BITS_>::maxval>::int_type x;
    if (TOTAL_BITS_1 - INT_BITS_1 > FRAC_BITS_) {
      x = (a.getVal() >>
           (int)Abs_Func<TOTAL_BITS_1 - INT_BITS_1 - FRAC_BITS_>::val);
    } else {
      x = (a.getVal() << (int)
           Abs_Func<TOTAL_BITS_1 - INT_BITS_1 - FRAC_BITS_>::val);
    }
    //				std::cout << " Shift_func " << a.getVal() << " -> " << (int)x <<
    //"\n";
    return (x);
  }
  template <int TOTAL_BITS_1, int INT_BITS_1, spuc_q_mode SPUC_Q_MODE_1,
            spuc_o_mode SPUC_O_MODE_1>
  static typename int_size_needed<
      INT_BITS_1 +
      Template_Max<TOTAL_BITS_1 - INT_BITS_1, FRAC_BITS_>::maxval>::int_type
  shift_function(const spuc_ufixed<TOTAL_BITS_1, INT_BITS_1, SPUC_Q_MODE_1,
                                   SPUC_O_MODE_1> &a) {
    typename int_size_needed<INT_BITS_1 +
                             Template_Max<TOTAL_BITS_1 - INT_BITS_1,
                                          FRAC_BITS_>::maxval>::int_type x;
    if (TOTAL_BITS_1 - INT_BITS_1 > FRAC_BITS_) {
      x = (a.getVal() >>
           (int)Abs_Func<TOTAL_BITS_1 - INT_BITS_1 - FRAC_BITS_>::val);
    } else {
      x = (a.getVal() << (int)
           Abs_Func<TOTAL_BITS_1 - INT_BITS_1 - FRAC_BITS_>::val);
    }
    return (x);
  }
};

/// A template class to wrap "saturate" functions that can be specialized for
/// fixed-point types
template <int TOTAL_BITS_, spuc_o_mode SPUC_O_MODE_>
class spuc_saturate_class_function {
public:
  /// Default saturate function is wrap!
  template <int TOTAL_BITS_1, int INT_BITS_1, spuc_q_mode SPUC_Q_MODE_1,
            spuc_o_mode SPUC_O_MODE_1>
  static typename int_size_needed<TOTAL_BITS_>::int_type
  saturate_sfixed(const spuc_fixed<TOTAL_BITS_1, INT_BITS_1, SPUC_Q_MODE_1,
                                   SPUC_O_MODE_1> &a) {
    typename int_size_needed<TOTAL_BITS_>::int_type x;
    x = a.getVal() & ((max_int_type(1) << (TOTAL_BITS_ - 1)) - 1);
    return (x);
  }
  template <int TOTAL_BITS_1, int INT_BITS_1, spuc_q_mode SPUC_Q_MODE_1,
            spuc_o_mode SPUC_O_MODE_1>
  static typename int_size_needed<TOTAL_BITS_>::int_type
  saturate_sfixed(const spuc_ufixed<TOTAL_BITS_1, INT_BITS_1, SPUC_Q_MODE_1,
                                    SPUC_O_MODE_1> &a) {
    typename int_size_needed<TOTAL_BITS_>::int_type x;
    x = a.getVal() & ((max_int_type(1) << (TOTAL_BITS_)) - 1);
    return (x);
  }
  static typename int_size_needed<TOTAL_BITS_>::int_type
  saturate(const max_int_type &a) {
    typename int_size_needed<TOTAL_BITS_>::int_type x;
    if (a > ((max_int_type(1) << (TOTAL_BITS_ - 1)) - 1))
      x = ((max_int_type(1) << (TOTAL_BITS_ - 1)) - 1);
    else if (a < ((max_int_type(-1) << (TOTAL_BITS_ - 1))))
      x = ((max_int_type(-1) << (TOTAL_BITS_ - 1)));
    else
      x = a;
    return (x);
  }
  static typename int_size_needed<TOTAL_BITS_>::int_type
  usaturate(const max_int_type &a) {
    typename int_size_needed<TOTAL_BITS_>::int_type x;
    if (a > ((max_int_type(1) << TOTAL_BITS_) - 1))
      x = ((max_int_type(1) << TOTAL_BITS_) - 1);
    else
      x = a;
    return (x);
  }
}; // end of class

/// Specialized for SPUC_SAT
template <int TOTAL_BITS_>
class spuc_saturate_class_function<TOTAL_BITS_, SPUC_SAT> {
public:
  /// Specialized Saturate function for SPUC_SAT
  template <int TOTAL_BITS_1, int INT_BITS_1, spuc_q_mode SPUC_Q_MODE_1,
            spuc_o_mode SPUC_O_MODE_1>
  static typename int_size_needed<TOTAL_BITS_>::int_type
  saturate_function(const spuc_fixed<TOTAL_BITS_1, INT_BITS_1, SPUC_Q_MODE_1,
                                     SPUC_O_MODE_1> &a) {

    typename int_size_needed<TOTAL_BITS_>::int_type x;
    x = (a.getVal() > ((max_int_type(1) << (TOTAL_BITS_ - 1)) - 1))
            ? ((max_int_type(1) << (TOTAL_BITS_ - 1)) - 1)
            : (a.getVal() < ((max_int_type(-1) << (TOTAL_BITS_ - 1))))
                  ? ((max_int_type(-1) << (TOTAL_BITS_ - 1)))
                  : a.getVal();
    //					std::cout << " Saturate_func " << a.getVal() << " -> " << (int)x
    //<< "\n";
    //					std::cout << "\n saturate_func " << (int)a << " -> " << (int)x
    //<< "\n";
    return (x);
  }
  /// Specialized Saturate function for SPUC_SAT
  template <int TOTAL_BITS_1, int INT_BITS_1, spuc_q_mode SPUC_Q_MODE_1,
            spuc_o_mode SPUC_O_MODE_1>
  static typename int_size_needed<TOTAL_BITS_>::int_type
  saturate_function(const spuc_ufixed<TOTAL_BITS_1, INT_BITS_1, SPUC_Q_MODE_1,
                                      SPUC_O_MODE_1> &a) {

    typename int_size_needed<TOTAL_BITS_>::int_type x;
    x = (a.getVal() > ((max_int_type(1) << (TOTAL_BITS_)) - 1))
            ? ((max_int_type(1) << (TOTAL_BITS_)) - 1)
            : a.getVal();
    return (x);
  }
  static typename int_size_needed<TOTAL_BITS_>::int_type
  saturate(const max_int_type &a) {
    typename int_size_needed<TOTAL_BITS_>::int_type x;
    x = (a > ((max_int_type(1) << (TOTAL_BITS_ - 1)) - 1))
            ? ((max_int_type(1) << (TOTAL_BITS_ - 1)) - 1)
            : (a < ((max_int_type(-1) << (TOTAL_BITS_ - 1))))
                  ? ((max_int_type(-1) << (TOTAL_BITS_ - 1)))
                  : a;
    //					std::cout << "\n saturate_func " << (int)a << " -> " << (int)x
    //<< "\n";
    return (x);
  }
  static typename int_size_needed<TOTAL_BITS_>::uint_type
  usaturate(const max_int_type &a) {
    typename int_size_needed<TOTAL_BITS_>::uint_type x;
    x = (a > ((max_int_type(1) << TOTAL_BITS_) - 1))
            ? ((max_int_type(1) << TOTAL_BITS_) - 1)
            : (a < 0) ? 0 : a;
    return (x);
  }
};
/// Specialized for SPUC_SAT_SYM
template <int TOTAL_BITS_>
class spuc_saturate_class_function<TOTAL_BITS_, SPUC_SAT_SYM> {
public:
  /// Specialized Saturate function for SPUC_SAT_SYM
  template <int TOTAL_BITS_1, int INT_BITS_1, spuc_q_mode SPUC_Q_MODE_1,
            spuc_o_mode SPUC_O_MODE_1>
  static typename int_size_needed<TOTAL_BITS_>::int_type
  saturate_function(const spuc_fixed<TOTAL_BITS_1, INT_BITS_1, SPUC_Q_MODE_1,
                                     SPUC_O_MODE_1> &a) {

    typename int_size_needed<TOTAL_BITS_>::int_type x;
    x = (a.getVal() > ((max_int_type(1) << (TOTAL_BITS_ - 1)) - 1))
            ? ((max_int_type(1) << (TOTAL_BITS_ - 1)) - 1)
            : (a.getVal() < ((max_int_type(-1) << (TOTAL_BITS_ - 1)) + 1))
                  ? ((max_int_type(-1) << (TOTAL_BITS_ - 1)) + 1)
                  : a.getVal();
    return (x);
  }
  /// Specialized Saturate function for SPUC_SAT_SYM
  template <int TOTAL_BITS_1, int INT_BITS_1, spuc_q_mode SPUC_Q_MODE_1,
            spuc_o_mode SPUC_O_MODE_1>
  static typename int_size_needed<TOTAL_BITS_>::int_type
  saturate_function(const spuc_ufixed<TOTAL_BITS_1, INT_BITS_1, SPUC_Q_MODE_1,
                                      SPUC_O_MODE_1> &a) {

    typename int_size_needed<TOTAL_BITS_>::int_type x;
    x = (a.getVal() > ((max_int_type(1) << (TOTAL_BITS_)) - 1))
            ? ((max_int_type(1) << (TOTAL_BITS_)) - 1)
            : a.getVal();
    return (x);
  }
  static typename int_size_needed<TOTAL_BITS_>::int_type
  saturate(const max_int_type &a) {
    typename int_size_needed<TOTAL_BITS_>::int_type x;
    x = (a > ((max_int_type(1) << (TOTAL_BITS_ - 1)) - 1))
            ? ((max_int_type(1) << (TOTAL_BITS_ - 1)) - 1)
            : (a < ((max_int_type(-1) << (TOTAL_BITS_ - 1)) + 1))
                  ? ((max_int_type(-1) << (TOTAL_BITS_ - 1)) + 1)
                  : a;
    //					std::cout << "\n saturate_func " << (int)a << " -> " << (int)x
    //<< "\n";
    return (x);
  }
  static typename int_size_needed<TOTAL_BITS_>::uint_type
  usaturate(const max_int_type &a) {
    typename int_size_needed<TOTAL_BITS_>::uint_type x;
    x = (a > ((max_int_type(1) << TOTAL_BITS_) - 1))
            ? ((max_int_type(1) << TOTAL_BITS_) - 1)
            : (a < 0) ? 0 : a;
    return (x);
  }
};
} // end namespace SPUC

#endif
