cmake_minimum_required(VERSION 2.6)
project(bugperProject)

set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type (Debug|Release|Test)")
set(top_DIR ${bugperProject_SOURCE_DIR}/..)
set(engine_src_DIR ${top_DIR}/src/Engine)
set(game_src_DIR ${top_DIR}/src/Game)
set(include_DIR ${top_DIR}/src)
set(BIN_DIR ${top_DIR}/bin)
set(LIB_DIR ${top_DIR}/lib)

include_directories(/usr/X11R6/include/)
link_directories(/usr/X11R6/lib)
link_directories(/usr/lib)
SET(EXTRA_LIBS GL X11 GLU glut png glee)

include_directories (${include_DIR})
include_directories (/usr/include)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR}/${CMAKE_BUILD_TYPE})

set(HDRS_bugper
  ${game_src_DIR}/Leaf.h
  ${game_src_DIR}/button.h
  ${game_src_DIR}/button1.h
  ${game_src_DIR}/ladybug.h
)
set(SRCS_bugper
  ${game_src_DIR}/main.cpp
  ${game_src_DIR}/Leaf.cpp
  ${game_src_DIR}/button.cpp
  ${game_src_DIR}/button1.cpp
  ${game_src_DIR}/ladybug.cpp
)

set(HDRS_littleGLEngine
  ${engine_src_DIR}/GlEngine.h
  ${engine_src_DIR}/Object.h
  ${engine_src_DIR}/ObjectMgr.h
  ${engine_src_DIR}/load_png.h
  ${engine_src_DIR}/Resource.h
  ${engine_src_DIR}/Mesh.h
  ${engine_src_DIR}/Material.h
  ${engine_src_DIR}/Shader.h
  ${engine_src_DIR}/Texture.h
  ${engine_src_DIR}/ResourceMgr.h
  ${engine_src_DIR}/MeshMgr.h
  ${engine_src_DIR}/MaterialMgr.h
  ${engine_src_DIR}/ShaderMgr.h
  ${engine_src_DIR}/TextureMgr.h
  ${engine_src_DIR}/Timer.h
  ${engine_src_DIR}/GLHelpers.h
  ${engine_src_DIR}/InputHandler.h
)
set(SRCS_littleGLEngine
  ${engine_src_DIR}/Object.cpp
  ${engine_src_DIR}/GlEngine.cpp
  ${engine_src_DIR}/ObjectMgr.cpp
  ${engine_src_DIR}/load_png.cpp
  ${engine_src_DIR}/Mesh.cpp
  ${engine_src_DIR}/Material.cpp
  ${engine_src_DIR}/Shader.cpp
  ${engine_src_DIR}/Texture.cpp
  ${engine_src_DIR}/ResourceMgr.cpp
  ${engine_src_DIR}/MeshMgr.cpp
  ${engine_src_DIR}/MaterialMgr.cpp
  ${engine_src_DIR}/ShaderMgr.cpp
  ${engine_src_DIR}/TextureMgr.cpp
  ${engine_src_DIR}/Timer.cpp
  ${engine_src_DIR}/GLHelpers.cpp
  ${engine_src_DIR}/InputHandler.cpp
)

add_library(littleGLEngine ${HDRS_littleGLEngine} ${SRCS_littleGLEngine})
target_link_libraries(littleGLEngine ${EXTRA_LIBS})

add_executable(bugper ${HDRS_bugper} ${SRCS_bugper})
target_link_libraries(bugper ${EXTRA_LIBS} littleGLEngine)
