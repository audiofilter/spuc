CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE "DEBUG")
  #SET(CMAKE_BUILD_TYPE "RELEASE")
  #SET(CMAKE_BUILD_TYPE "RELWITHDEBINFO")
  #SET(CMAKE_BUILD_TYPE "MINSIZEREL")
ENDIF()
PROJECT("spuc")
message(STATUS "Project spuc")

#SET(CMAKE_C_COMPILER "/usr/bin/clang")
#SET(CMAKE_CXX_COMPILER "/usr/bin/clang++")

IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
###set(CMAKE_EXE_LINKER_FLAGS "-static-libstdc++")
#set(CMAKE_CXX_FLAGS "-Werror -std=c++0x ")
set(CMAKE_CXX_FLAGS " -std=c++11 ")
message(STATUS "Using c++11")
ENDIF()

execute_process(COMMAND ${CMAKE_CXX_COMPILER} -dumpversion
                OUTPUT_VARIABLE GCC_VERSION)
if (GCC_VERSION VERSION_GREATER 4.8 OR GCC_VERSION VERSION_EQUAL 4.8)
    message(STATUS "GCC Version >=  4.8, using c++11/libstdc++")
	set(CMAKE_EXE_LINKER_FLAGS "-static-libstdc++")
	set(CMAKE_CXX_FLAGS "-Wall -std=c++0x ")
endif()

#set(CMAKE_CXX_LINK_FLAGS "-L$ENV{SYSTEMC_HOME}/lib-linux")

SET(TYPE_SRCS 
spuc/bit.cpp
)

SET(FILT_SRCS  
spuc/butterworth_iir.cpp
spuc/butterworth_allpass.cpp
spuc/chebyshev_iir.cpp
spuc/elliptic_iir.cpp
spuc/elliptic_allpass.cpp
spuc/allpass_1aq1.cpp
spuc/allpass_1aq2.cpp
spuc/butterworth_fir.cpp
spuc/create_remez_fir.cpp
spuc/create_remez_lpfir.cpp
spuc/farrow_upsampler.cpp
spuc/find_roots.cpp
spuc/fir_coeff.cpp
spuc/fir_inv_dft.cpp
spuc/gaussian_fir.cpp
spuc/iir_coeff.cpp
spuc/raised_cosine_imp.cpp
spuc/root_raised_cosine_imp.cpp
spuc/root_raised_cosine_quantized.cpp
spuc/remez_fir.cpp
spuc/spuc_math.cpp
spuc/shelf_allpass1.cpp
spuc/other_freq.cpp
spuc/equalizer.cpp
spuc/fast_equalizer.cpp
)

SET(SPUC_SRCS 
spuc/bit_scrambler.cpp
spuc/cfft.cpp
spuc/idft.cpp
spuc/fft.cpp
spuc/ifft.cpp
spuc/lib_inst.cpp
spuc/max_pn.cpp
spuc/misc.cpp
spuc/nco.cpp
spuc/noise.cpp
spuc/rv_stat.cpp
spuc/sigma_delta.cpp
spuc/timing_nco.cpp
spuc/vco.cpp
spuc/window.cpp
spuc/utils.cpp
)


SET(COMM_SRCS 
spuc/a_d.cpp
spuc/agc.cpp
spuc/bpsk_ber_test.cpp
spuc/carrier_nco.cpp
spuc/data_conv_encoder.cpp
spuc/dqpsk.cpp
spuc/dvb_conv_encoder.cpp
spuc/fading_channel.cpp
spuc/ofdm_data_encoder.cpp
spuc/qam_conv_decoder.cpp
spuc/qam_mod.cpp
spuc/qam_soft_decision.cpp
spuc/qpsk_ber_test.cpp
spuc/qpsk_discriminators.cpp
spuc/viterbi.cpp
)


FIND_PACKAGE(Boost)
IF(Boost_FOUND)
  IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
	# Mac OS X specific code
	SET(OperatingSystem "Mac OS X")
	SET(Boost_USE_STATIC_LIBS ON)
	SET(Boost_USE_MULTITHREADED ON)
  ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin") 

  SET(Boost_USE_STATIC_RUNTIME OFF)
  FIND_PACKAGE(Boost COMPONENTS python)
  FIND_PACKAGE(PythonLibs REQUIRED)
  INCLUDE_DIRECTORIES("${Boost_INCLUDE_DIRS}" ${PYTHON_INCLUDE_DIRS} "/usr/include")
  LINK_DIRECTORIES(${PYTHON_LIBRARY_DIRS} ${Boost_LIBRARY_DIRS})
  
  EXECUTE_PROCESS( COMMAND python -c "from distutils.sysconfig import get_python_lib; print get_python_lib()" OUTPUT_VARIABLE PYTHON_SITE_PACKAGES OUTPUT_STRIP_TRAILING_WHITESPACE)
 
  ADD_DEFINITIONS(-DSPUCBOOST)
  INCLUDE_DIRECTORIES("/usr/include/" ".")
  ADD_LIBRARY(spuc STATIC ${SPUC_SRCS} ${COMM_SRCS})
  ADD_LIBRARY(spuc_filt STATIC ${FILT_SRCS})
  ADD_LIBRARY(spuc_types STATIC ${TYPE_SRCS})
  INSTALL(TARGETS spuc_filt DESTINATION "/usr/local/lib")
  INSTALL(TARGETS spuc_types DESTINATION "/usr/local/lib")
  INSTALL(TARGETS spuc DESTINATION "/usr/local/lib")
  # not working
  SET_TARGET_PROPERTIES(spuc PROPERTIES LIBRARY_OUTPUT_PATH "/usr/local/lib")
  SET_TARGET_PROPERTIES(spuc_types PROPERTIES LIBRARY_OUTPUT_PATH "/usr/local/lib")
ELSEIF(NOT Boost_FOUND)
  MESSAGE(FATAL_ERROR "Unable to find correct Boost version. Did you set BOOST_ROOT?")
ENDIF()


ADD_DEFINITIONS("-Wall -fPIC -DSPUCBOOST")

option(SPUC_BUILD_PYTHON_EXTENSIONS "Build extensions" OFF)
option(SPUC_BUILD_EXAMPLES "Build examples" OFF)

if (SPUC_BUILD_EXAMPLES)
add_subdirectory(examples)
endif()

if (SPUC_BUILD_PYTHON_EXTENSIONS)
add_subdirectory(../extensions)
endif()