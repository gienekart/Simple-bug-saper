cmake_minimum_required(VERSION 2.6)
project(bugper)

set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type (Debug|Release|Test)")
set(src_DIR ${bugper_SOURCE_DIR}/../src)
set(include_DIR ${bugper_SOURCE_DIR}/../include)

include_directories (${include_DIR})
include_directories (/usr/include/GL)

set(HDRS_bugper
  ${include_DIR}/GlEngine.h
)
set(SRCS_bugper
  ${src_DIR}/main.cpp
  ${src_DIR}/GlEngine.cpp
)

add_executable(bugper ${HDRS_bugper} ${SRCS_bugper})
