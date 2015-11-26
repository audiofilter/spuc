CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE "DEBUG")
ENDIF()
PROJECT("spuc_examples")
message("Project spuc_examples")

find_package(GLUT)
find_package(OpenGL)

SET(TARGETS
auto_corr
mlse
)

INCLUDE_DIRECTORIES(".." "/usr/local/include" "../cpplot/include" ${GLUT_INCLUDE_DIR} )
SET(CMAKE_CXX_FLAGS "-ggdb -Wno-deprecated -fPIC -DGL_DO_NOT_WARN_IF_MULTI_GL_VERSION_HEADERS_INCLUDED -std=c++11")
LINK_DIRECTORIES("/usr/local/lib" )

FOREACH(mod ${TARGETS})
	SET(SRC test_${mod}.cpp)
	ADD_EXECUTABLE(graph_${mod}  ${SRC})
	TARGET_LINK_LIBRARIES(graph_${mod} spuc ${Spuce_LIBRARIES} spuc_types cpplot)
	SET(EXECUTABLE_OUTPUT_PATH ../..)
	INSTALL(TARGETS graph_${mod} DESTINATION "$ENV{HOME}/bin")
ENDFOREACH(mod ${EXTS})


ADD_EXECUTABLE(qpsk_ber qpsk_ber.cpp)
TARGET_LINK_LIBRARIES(qpsk_ber spuc ${Spuce_LIBRARIES} spuc_types cpplot)

ADD_EXECUTABLE(qpsk_scatter qpsk_scatter.cpp)
TARGET_LINK_LIBRARIES(qpsk_scatter spuc ${Spuce_LIBRARIES} spuc_types cpplot)
