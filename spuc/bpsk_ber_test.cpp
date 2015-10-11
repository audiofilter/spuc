// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
//! \author Tony Kirke
// from directory: spuc_src
#include <iostream>
#include <fstream>
#include <iomanip>
#include <spuc/spuc_defines.h>
#include <spuc/bpsk_ber_test.h>
namespace SPUC {
//------------------------------------------------------------------------
//	Determine BER result
//------------------------------------------------------------------------
void bpsk_ber_test::ber_results(long received) {
  // For measuring simulation time

  if ((received % modc == 0) && synced) {
    if (received > 512) {
      std::cout << "Symbols = " << received;
      std::cout << " Errors = " << errors;
      std::cout << " BER = " << (float_type)errors / (float_type)received;
      std::cout << " Elpsd Time = " << difftime(time(NULL), start_time) / 60.0 << "(min)\n";
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
    if (received > 512) {
      std::cout << "Symbols = " << received;
      std::cout << " Errors = " << errors;
      std::cout << " BER = " << (float_type)errors / (float_type)received;
      std::cout << " Elpsd Time = " << difftime(time(NULL), start_time) / 60.0 << "(min)\n";
    }
    std::cin.get();
  }
}
//***********************************************************************************************
// Correlate received signal with reference PN and indicate when
// Synchronization is found by setting sync to +1 or -1.
// When synchronization is first found output is 2,
// otherwise it is the received bit multiplied by the
// reference PN bit.
//*********************************************************************************************
long bpsk_ber_test::synchronize(long* received, long data) {
  const char thres = 55;  // Threshold for sync
  const char pnlen = 63;
  signed char out = 0;

  // Correlate with reference PN
  signed char tmp = ref.out();
  out = (data >= 0) ? tmp : -tmp;
  corr_sum += out;
  if ((*received % pnlen == 0) && (synced == 0)) {
    if (corr_sum > thres) {
      synced = 1;     // Synchronization achieved
      *received = 1;  // Reset number of symbols
      interval = 1;
    } else if (-corr_sum > thres) {
      synced = -1;
      *received = 1;
      interval = 1;
    } else {
      corr_sum = 0;  // Reset sum
      ref.out();     // Clock extra PN sample
    }
  }
  // End correlation block
  // Count Errors
  if (synced != 0) errors += (out == synced) ? 0 : 1;
  interval++;
  return (errors);
}
//
// Final result
//
void bpsk_ber_test::final_results(long received) {
  if (synced != 0) {
    std::cout << "Symbols = " << received;
    std::cout << " Errors = " << errors;
    std::cout << " BER = " << (float_type)errors / (float_type)received;
    std::cout << " Elpsd Time = " << difftime(time(NULL), start_time) / 60.0 << "(min)\n";
  } else {
    std::cout << "Synchronization with reference PN not found!\n";
  }
}
//
// Tracks the number of errors since last invocation and
// returns the BER over the interval
//
float_type bpsk_ber_test::running_ber(void) {
  long new_errors = errors - prev_errors;
  prev_errors = new_errors;
  if (interval == 0) return (0);  // Error condition
  float_type rber = new_errors / (float_type)interval;
  interval = 0;  // reset interval counter
  return (rber);
}

}  // namespace SPUC
