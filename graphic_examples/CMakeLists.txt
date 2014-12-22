CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE "DEBUG")
ENDIF()
PROJECT("spuc_examples")
message("Project spuc_examples")

find_package(GLUT)
find_package(OpenGL)
find_package(Boost COMPONENTS thread system )

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

INCLUDE_DIRECTORIES(".." "/usr/local/include" "../cpplot/include" ${Boost_INCLUDE_DIRS} ${GLUT_INCLUDE_DIR} )
SET(CMAKE_CXX_FLAGS "-ggdb -Wno-deprecated -fPIC -DGL_DO_NOT_WARN_IF_MULTI_GL_VERSION_HEADERS_INCLUDED")
LINK_DIRECTORIES("/usr/local/lib" ${Boost_LIBRARY_DIRS} )

FOREACH(mod ${TARGETS})
	SET(SRC test_${mod}.cpp)
	ADD_EXECUTABLE(${mod}  ${SRC})
	TARGET_LINK_LIBRARIES(${mod} spuc spuc_filt spuc_types cpplot)
	SET(EXECUTABLE_OUTPUT_PATH ../..)
	INSTALL(TARGETS ${mod} DESTINATION "$ENV{HOME}/bin")
ENDFOREACH(mod ${EXTS})

