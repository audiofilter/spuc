// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_src
#include <iostream>
#include <fstream>
#include <iomanip>
#include <spuc/qpsk_ber_test.h>
#include <spuc/complex.h>
#include <spuc/dsp_functions/spuc_math.h>
namespace SPUC {
void qpsk_ber_test::print_running_ber(void) {
  long sym_int = interval;
  std::cout << "Symbol interval = " << std::setw(8) << sym_int;
  std::cout << "BER = " << running_ber() << '\n';
}
//---------------------------------------------------------------------
//	Determine BER result
//---------------------------------------------------------------------
void qpsk_ber_test::ber_results(long received) {
  // For measuring simulation time
  float_type elapsed_time = 0;
  if ((received % modc == 0) && sync) {
    elapsed_time = difftime(time(NULL), start_time);
    if (received > 512) {
      std::cout << "Symbols = " << received;
      std::cout << " Errors = " << errors;
      std::cout << " BER = " << (float_type)errors / (float_type)received;
      std::cout << " Elpsd Time = " << elapsed_time / 60.0 << "(min)\n";
      std::cout.flush();
    }
    modc <<= 1;
  }
#ifdef KBHITD
  // you need to include some type of conio header file!!!!!!!
  if (kbhit()) {
#else
  // Replaces kbhit from conio.h
  if (std::cin.rdbuf()->in_avail()) {  // get() will not block
#endif
    elapsed_time = difftime(time(NULL), start_time);
    if (received > 512) {
      std::cout << "Symbols = " << received;
      std::cout << " Errors = " << errors;
      std::cout << " BER = " << (float_type)errors / (float_type)received;
      std::cout << " Elpsd Time = " << elapsed_time / 60.0 << "(min)\n";
      std::cout.flush();
    }
    std::cin.get();
  }
}
//**********************************************************************************
// Correlate received signal with reference PN and indicate when
// Synchronization is found by setting sync to +1 or -1.
// When synchronization is first found output is 2,
// otherwise it is the received bit multiplied by the
// reference PN bit.
//
long qpsk_ber_test::synchronize(long* received, complex<long> data) {
  const char thres = 57;  // Threshold for sync
  const char pnlen = 63;
  complex<long> out = 0;

  // Correlate with reference PN
  long tmp = ref.out();
  out = tmp * data;
  corr_sum += out;
  if ((*received % pnlen == 0) && (sync == 0)) {
    if (real(corr_sum) > thres) {
      rotate = complex<long>(1, 0);
      *received = 1;
      interval = 1;
      sync = 1;
    } else if (-real(corr_sum) > thres) {
      rotate = complex<long>(-1, 0);
      *received = 1;
      interval = 1;
      sync = 1;
    } else if (imag(corr_sum) > thres) {
      rotate = complex<long>(0, -1);
      *received = 1;
      interval = 1;
      sync = 1;
    } else if (-imag(corr_sum) > thres) {
      rotate = complex<long>(0, 1);
      *received = 1;
      interval = 1;
      sync = 1;
    } else {
      sync = 0;
      corr_sum = 0;  // Reset sum
      ref.out();     // Clock extra PN sample
      rotate = complex<long>(0, 0);
    }
  }
  // End correlation block
  // Count Errors
  if (sync != 0) errors += (real(out * rotate) == 1) ? 0 : 1;
  interval++;
  return (errors);
}
//**********************************************************************************
// Correlate received signal with reference PN and indicate when
// Synchronization is found by setting sync to +1 or -1.
// When synchronization is first found output is 2,
// otherwise it is the received bit multiplied by the
// reference PN bit.
//
long qpsk_ber_test::synchronise(long received, complex<double> data) {
  const char thres = 57;  // Threshold for sync
  const char pnlen = 63;
  long rcvd = received;
  complex<long> out = 0;

  // Correlate with reference PN
  long tmp = ref.out();
  out = tmp * complex<long>(data);
  corr_sum += out;
  if ((received % pnlen == 0) && (sync == 0)) {
    if (real(corr_sum) > thres) {
      rotate = complex<long>(1, 0);
      rcvd = 1;
      interval = 1;
      sync = 1;
    } else if (-real(corr_sum) > thres) {
      rotate = complex<long>(-1, 0);
      rcvd = 1;
      interval = 1;
      sync = 1;
    } else if (imag(corr_sum) > thres) {
      rotate = complex<long>(0, -1);
      rcvd = 1;
      interval = 1;
      sync = 1;
    } else if (-imag(corr_sum) > thres) {
      rotate = complex<long>(0, 1);
      rcvd = 1;
      interval = 1;
      sync = 1;
    } else {
      sync = 0;
      corr_sum = 0;  // Reset sum
      ref.out();     // Clock extra PN sample
      rotate = complex<long>(0, 0);
    }
  }
  // End correlation block
  // Count Errors
  if (sync != 0) errors += (real(out * rotate) == 1) ? 0 : 1;
  interval++;
  return (rcvd);
}
//
// Final result
//
void qpsk_ber_test::final_results(long received) {
  float_type elapsed_time = 0;
  if (sync != 0) {
    elapsed_time = difftime(time(NULL), start_time);
    std::cout << "Symbols = " << received;
    std::cout << " Errors = " << errors;
    std::cout << " Elpsd Time = " << elapsed_time / 60.0 << "(min)\n";
    std::cout << " BER = " << (float_type)errors / (float_type)received << "\n";
    std::cout.flush();
  } else {
    std::cout << "Synchronization with reference PN not found!\n";
    std::cout.flush();
  }
}
// Tracks the number of errors since last call
// and returns the BER over the interval
//
float_type qpsk_ber_test::running_ber(void) {
  long new_errors = errors - prev_errors;
  prev_errors = new_errors;
  if (interval == 0) return (0);  // Error condition
  float_type rber = new_errors / (float_type)interval;
  interval = 0;  // reset interval counter
  return (rber);
}

}  // namespace SPUC
