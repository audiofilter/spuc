CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE "DEBUG")
  #SET(CMAKE_BUILD_TYPE "RELEASE")
  #SET(CMAKE_BUILD_TYPE "RELWITHDEBINFO")
  #SET(CMAKE_BUILD_TYPE "MINSIZEREL")
ENDIF()
PROJECT("spuc")
message(STATUS "Project spuc")
include(FeatureSummary)
include(CMakeDependentOption)

IF (${CMAKE_SYSTEM_NAME} MATCHES "Darwin" OR ${CMAKE_SYSTEM_NAME} MATCHES "Linux")
  set(CMAKE_CXX_FLAGS " -std=c++11 ")
  message(STATUS "Using c++11")
ENDIF()

find_package(Spuce CONFIG)
if (Spuce_FOUND)
  message(STATUS "Found Spuce!")
  message(STATUS "Spuce inc dir = ${Spuce_INCLUDE_DIRS}")
  message(STATUS "Spuce libs = ${Spuce_LIBRARIES}")
endif()


SET(TYPE_SRCS 
  spuc/bit.cpp
)

SET(SPUC_SRCS 
  spuc/dsp_functions/cfft.cpp
  spuc/dsp_functions/idft.cpp
  spuc/dsp_functions/fft.cpp
  spuc/dsp_functions/ifft.cpp
  spuc/dsp_functions/xcorr.cpp
  spuc/bit_scrambler.cpp
  spuc/max_pn.cpp
  spuc/misc.cpp
  spuc/nco.cpp
  spuc/noise.cpp
  spuc/rv_stat.cpp
  spuc/sigma_delta.cpp
  spuc/timing_nco.cpp
  spuc/vco.cpp
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


cmake_dependent_option(SPUC_EXAMPLES "Build examples" ON "SPUC_BUILD_ALL" OFF)
cmake_dependent_option(SPUC_GRAPHICS "Build graphic examples" ON "SPUC_BUILD_ALL" OFF)


ADD_DEFINITIONS("-Wall -fPIC")
INCLUDE_DIRECTORIES(${Spuce_INCLUDE_DIRS} "/usr/include/" ".")
ADD_LIBRARY(spuc STATIC ${SPUC_SRCS} ${COMM_SRCS})
ADD_LIBRARY(spuc_types STATIC ${TYPE_SRCS})
INSTALL(TARGETS spuc_types DESTINATION ./lib)
INSTALL(TARGETS spuc DESTINATION ./lib)

if (SPUC_EXAMPLES)
  add_subdirectory(examples)
else()
  MESSAGE(STATUS "Not building examples - enable with cmake -DSPUC_EXAMPLES=ON")
endif()

if (SPUC_GRAPHICS)
  add_subdirectory(cpplot)
  add_subdirectory(graphic_examples)
else()
  MESSAGE(STATUS "Not building graphic examples - enable with cmake -DSPUC_GRAPHIC_EXAMPLES=ON")
endif()

add_feature_info(SPUC_BUILD_ALL SPUC_BUILD_ALL "Build everything")
add_feature_info(SPUC_GRAPHICS SPUC_GRAPHICS "Build graphic examples")
add_feature_info(SPUC_EXAMPLES SPUC_EXAMPLES "Build examples")




#########################################################################
# print features summary
#########################################################################
message(STATUS "######################################################")
message(STATUS "## Enabled features")
message(STATUS "######################################################")
feature_summary(WHAT ENABLED_FEATURES)
message(STATUS "######################################################")
message(STATUS "## Disabled features")
message(STATUS "######################################################")
feature_summary(WHAT DISABLED_FEATURES)
