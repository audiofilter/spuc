CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE "DEBUG")
  #SET(CMAKE_BUILD_TYPE "RELEASE")
  #SET(CMAKE_BUILD_TYPE "RELWITHDEBINFO")
  #SET(CMAKE_BUILD_TYPE "MINSIZEREL")
ENDIF()
PROJECT("spuc")
message(STATUS "Project spuc")

IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  set(CMAKE_CXX_FLAGS " -std=c++11 ")
  message(STATUS "Using c++11")
ENDIF()


find_package(SPUCE CONFIG)
if (SPUCE_FOUND)
  message(STATUS "Found Spuce!")
  message(STATUS "Spuce inc dir = ${Spuce_INCLUDE_DIRS}")
  message(STATUS "Spuce libs = ${Spuce_LIBRARIES}")
endif()


SET(TYPE_SRCS 
  spuc/bit.cpp
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
  spuc/utils.cpp
  spuc/xcorr.cpp
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
  spuc/fm_discriminator.cpp
  spuc/root_raised_cosine_quantized.cpp
  spuc/viterbi.cpp
)


########################################################################
# install include files
########################################################################
install(
    DIRECTORY spuc
    DESTINATION include
    COMPONENT spuc_devel
    PATTERN "*.cpp" EXCLUDE
)

option(SPUC_BUILD_ALL "Build everything" OFF)
option(SPUC_BUILD_EXAMPLES "Build examples" OFF)

if (SPUC_BUILD_ALL)
	MESSAGE(STATUS "building everything")
	set(SPUC_BUILD_EXAMPLES ON)
else()
	MESSAGE(STATUS "Not building everything - enable with cmake -DSPUC_BUILD_ALL=ON")
endif()

ADD_DEFINITIONS("-Wall -fPIC")
INCLUDE_DIRECTORIES(${Spuce_INCLUDE_DIRS} "/usr/include/" ".")
ADD_LIBRARY(spuc STATIC ${SPUC_SRCS} ${COMM_SRCS})
ADD_LIBRARY(spuc_types STATIC ${TYPE_SRCS})
INSTALL(TARGETS spuc_types DESTINATION ./lib)
INSTALL(TARGETS spuc DESTINATION ./lib)

if (SPUC_BUILD_EXAMPLES)
MESSAGE(STATUS "building examples")
add_subdirectory(examples)
else()
MESSAGE(STATUS "Not building examples - enable with cmake -DSPUC_BUILD_EXAMPLES=ON")
endif()

