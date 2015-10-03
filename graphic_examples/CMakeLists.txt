CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE "DEBUG")
ENDIF()
PROJECT("spuc_examples")
message("Project spuc_examples")

find_package(GLUT)
find_package(OpenGL)

execute_process(COMMAND ${CMAKE_CXX_COMPILER} -dumpversion
                OUTPUT_VARIABLE GCC_VERSION)
if (GCC_VERSION VERSION_GREATER 4.8 OR GCC_VERSION VERSION_EQUAL 4.8)
    message(STATUS "GCC Version >=  4.8")
	set(CMAKE_EXE_LINKER_FLAGS "-static-libstdc++")
	set(CMAKE_CXX_FLAGS "-Wall -coverage -std=c++0x ")
endif()

SET(TARGETS
auto_corr
cic
elliptic_allpass
filters
iir2nd
interp
notch
mlse
)

INCLUDE_DIRECTORIES(".." "/usr/local/include" "../cpplot/include" ${GLUT_INCLUDE_DIR} )
SET(CMAKE_CXX_FLAGS "-ggdb -Wno-deprecated -fPIC -DGL_DO_NOT_WARN_IF_MULTI_GL_VERSION_HEADERS_INCLUDED -std=c++11")
LINK_DIRECTORIES("/usr/local/lib" )

FOREACH(mod ${TARGETS})
	SET(SRC test_${mod}.cpp)
	ADD_EXECUTABLE(gr_${mod}  ${SRC})
	TARGET_LINK_LIBRARIES(gr_${mod} spuc spuc_filt spuc_types cpplot)
	SET(EXECUTABLE_OUTPUT_PATH ../..)
	INSTALL(TARGETS gr_${mod} DESTINATION "$ENV{HOME}/bin")
ENDFOREACH(mod ${EXTS})


ADD_EXECUTABLE(qpsk_ber qpsk_ber.cpp)
TARGET_LINK_LIBRARIES(qpsk_ber spuc spuc_filt spuc_types cpplot)

ADD_EXECUTABLE(qpsk_scatter qpsk_scatter.cpp)
TARGET_LINK_LIBRARIES(qpsk_scatter spuc spuc_filt spuc_types cpplot)
