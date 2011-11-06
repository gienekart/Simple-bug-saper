cmake_minimum_required(VERSION 2.6)
project(bugper)

set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type (Debug|Release|Test)")
set(src_DIR ${bugper_SOURCE_DIR}/../src)
set(BIN_DIR ${bugper_SOURCE_DIR}/../bin)
set(LIB_DIR ${bugper_SOURCE_DIR}/../lib)

include_directories(/usr/X11R6/include/)
link_directories(/usr/X11R6/lib)
link_directories(/usr/lib)
SET(EXTRA_LIBS GL X11 GLU glut png)

include_directories (${include_DIR})
include_directories (/usr/include)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR}/${CMAKE_BUILD_TYPE})

set(HDRS_bugper
  ${src_DIR}/GlEngine.h
  ${src_DIR}/Object.h
  ${src_DIR}/ObjectMgr.h
  ${src_DIR}/Leaf.h
  ${src_DIR}/load_png.h
)
set(SRCS_bugper
  ${src_DIR}/main.cpp
  ${src_DIR}/Object.cpp
  ${src_DIR}/GlEngine.cpp
  ${src_DIR}/ObjectMgr.cpp
  ${src_DIR}/Leaf.cpp
  ${src_DIR}/load_png.cpp
)

add_executable(bugper ${HDRS_bugper} ${SRCS_bugper})
target_link_libraries(bugper ${EXTRA_LIBS})
