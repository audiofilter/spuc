CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE "DEBUG")
ENDIF()
PROJECT("spuc_plot_examples")
message("Project spuc_plot_examples")

execute_process(COMMAND ${CMAKE_CXX_COMPILER} -dumpversion
  OUTPUT_VARIABLE GCC_VERSION)
if (GCC_VERSION VERSION_GREATER 4.8 OR GCC_VERSION VERSION_EQUAL 4.8)
  message(STATUS "GCC Version >=  4.8")
	set(CMAKE_EXE_LINKER_FLAGS "-static-libstdc++")
	set(CMAKE_CXX_FLAGS "-Wall -coverage -std=c++0x ")
endif()

FIND_PACKAGE(PythonLibs REQUIRED)

include_directories(
	${PYTHON_INCLUDE_DIRS}
	)


SET(TARGETS
	iir_allpass1
	butterworth_fir
	chebyshev_iir
	elliptic_iir
	butterworth_iir
	butterworth_iir_hpf
	gaussian
	remez
	interp
	notch
)

ADD_DEFINITIONS(" -fPIC -DSPUCBOOST ")
INCLUDE_DIRECTORIES(".." "/usr/local/include")
LINK_DIRECTORIES("/usr/local/lib")

FOREACH(mod ${TARGETS})
	SET(SRC test_${mod}.cpp plot_fft.cpp)
	ADD_EXECUTABLE(plot_${mod}  ${SRC})
	TARGET_LINK_LIBRARIES(plot_${mod} spuc spuc_filt spuc_types ${PYTHON_LIBRARY})
	INSTALL(TARGETS plot_${mod} DESTINATION "$ENV{HOME}/bin")
ENDFOREACH(mod ${EXTS})

set(EXECUTABLE_OUTPUT_PATH ..)
