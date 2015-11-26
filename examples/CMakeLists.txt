CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE "DEBUG")
ENDIF()
PROJECT("spuc_examples")
message("Project spuc_examples")

SET(TARGETS
  test_ddfse
  test_mlse
  )

# These to make QPSK sync up:" -DNOFREQ -DNOTIME -DNOFREQC -DNORAND "
ADD_DEFINITIONS(" -fPIC -DSPUCBOOST -DNOFREQ -DNOTIME -DNOFREQC -DNORAND ")
INCLUDE_DIRECTORIES(".." "/usr/local/include")
LINK_DIRECTORIES("/usr/local/lib")

FOREACH(mod ${TARGETS})
  SET(SRC ${mod}.cpp)
  ADD_EXECUTABLE(${mod}  ${SRC})
  TARGET_LINK_LIBRARIES(${mod} spuc ${Spuce_LIBRARIES} spuc_types)
  INSTALL(TARGETS ${mod} DESTINATION "$ENV{HOME}/bin")
ENDFOREACH(mod ${EXTS})

ADD_EXECUTABLE(qpsk qpsk_main.cpp)
TARGET_LINK_LIBRARIES(qpsk spuc ${Spuce_LIBRARIES} spuc_types)

set(EXECUTABLE_OUTPUT_PATH ../..)
