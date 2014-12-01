CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE "DEBUG")
ENDIF()
PROJECT("spuc_examples")
message("Project spuc_examples")

#SET(CMAKE_C_COMPILER "/usr/bin/clang")
#SET(CMAKE_CXX_COMPILER "/usr/bin/clang++")

execute_process(COMMAND ${CMAKE_CXX_COMPILER} -dumpversion
                OUTPUT_VARIABLE GCC_VERSION)
if (GCC_VERSION VERSION_GREATER 4.8 OR GCC_VERSION VERSION_EQUAL 4.8)
    message(STATUS "GCC Version >=  4.8")
	set(CMAKE_EXE_LINKER_FLAGS "-static-libstdc++")
	set(CMAKE_CXX_FLAGS "-Wall -coverage -std=c++0x ")
endif()

SET(TARGETS
test_cic
test_auto_corr
test_ddfse
test_elliptic_allpass
test_filters
test_fir2

#test_spuc_int
#test_spuc_int_types
#test_spuc_fixed
#test_spuc_fixed_types
#test_speed

test_iir2nd
test_iir
test_interp

test_notch
test_dump
test_mlse
test_roots
test_smart_test

test_q
test_rls
#test_sint2
#test_sint
test_cmat
)

#SET_TARGET_PROPERTIES(spuc PROPERTIES LIBRARY_OUTPUT_PATH ".")
#SET_TARGET_PROPERTIES(types PROPERTIES LIBRARY_OUTPUT_PATH ".")
#ADD_DEFINITIONS("-Werror -fPIC -DSPUCBOOST")
# These to make QPSK sync up:" -DNOFREQ -DNOTIME -DNOFREQC -DNORAND "
ADD_DEFINITIONS(" -fPIC -DSPUCBOOST -DNOFREQ -DNOTIME -DNOFREQC -DNORAND ")
INCLUDE_DIRECTORIES(".." "/usr/local/include")
LINK_DIRECTORIES("/usr/local/lib")

FOREACH(mod ${TARGETS})
SET(SRC ${mod}.cpp)
ADD_EXECUTABLE(${mod}  ${SRC})
TARGET_LINK_LIBRARIES(${mod} spuc spuc_filt spuc_types)
INSTALL(TARGETS ${mod} DESTINATION "$ENV{HOME}/bin")
ENDFOREACH(mod ${EXTS})

ADD_EXECUTABLE(qpsk qpsk_main.cpp)
TARGET_LINK_LIBRARIES(qpsk spuc spuc_filt spuc_types)

ADD_EXECUTABLE(qpsk_v qpsk_variable_main.cpp)
TARGET_LINK_LIBRARIES(qpsk_v spuc spuc_filt spuc_types)

# These require "audiofile.h" (libaudiofile-dev) and itpp packages to be installed
IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
  ADD_EXECUTABLE(test_ls_solve test_ls_solve.cpp)
  TARGET_LINK_LIBRARIES(test_ls_solve itpp)
ENDIF()

set(EXECUTABLE_OUTPUT_PATH ../..)
