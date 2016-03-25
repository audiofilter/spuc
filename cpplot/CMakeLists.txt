cmake_minimum_required(VERSION 2.8)
project(CPPLOT)

find_package(GLUT)
find_package(OpenGL)
find_package( Boost COMPONENTS thread system )
link_directories ( ${Boost_LIBRARY_DIRS} )

option(CPPLOT_BUILD_EXAMPLES "Build examples" OFF)

include_directories(${PROJECT_SOURCE_DIR}/src ${PROJECT_SOURCE_DIR}/include ${Boost_INCLUDE_DIRS} ${GLUT_INCLUDE_DIR} )


set(CMAKE_CXX_FLAGS "-ggdb -Wno-deprecated -fPIC -DGL_DO_NOT_WARN_IF_MULTI_GL_VERSION_HEADERS_INCLUDED")

## Build the library
set(LIBRARY_OUTPUT_PATH ..)
set(EXECUTABLE_OUTPUT_PATH ../..)
set(SRC_DIR "src")
add_library(cpplot STATIC ${SRC_DIR}/matplotpp.cpp ${SRC_DIR}/gl2ps.c ${SRC_DIR}/cpplot.cpp ${SRC_DIR}/math.cpp ${SRC_DIR}/glut.cpp ${SRC_DIR}/figure.cpp ${SRC_DIR}/layer.cpp ${SRC_DIR}/axes.cpp ${SRC_DIR}/color.cpp ${SRC_DIR}/drawing.cpp ${SRC_DIR}/line.cpp ${SRC_DIR}/patch.cpp ${SRC_DIR}/surface.cpp ${SRC_DIR}/text.cpp)
target_link_libraries(cpplot
    ${GLUT_LIBRARY}
    ${OPENGL_LIBRARY}
    ${Boost_LIBRARIES})

if(CPPLOT_BUILD_EXAMPLES)
#    add_subdirectory(examples)
endif()
