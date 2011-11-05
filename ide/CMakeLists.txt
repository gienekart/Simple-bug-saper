cmake_minimum_required(VERSION 2.6)
project(bugper)

set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type (Debug|Release|Test)")
set(src_DIR ${bugper_SOURCE_DIR}/../src)

include_directories(/usr/X11R6/include/)
link_directories(/usr/X11R6/lib)
SET(EXTRA_LIBS GL X11 GLU glut)

include_directories (${include_DIR})
include_directories (/usr/include)

set(HDRS_bugper
  ${src_DIR}/GlEngine.h
)
set(SRCS_bugper
  ${src_DIR}/main.cpp
  ${src_DIR}/GlEngine.cpp
)

add_executable(bugper ${HDRS_bugper} ${SRCS_bugper})
target_link_libraries(bugper ${EXTRA_LIBS})
