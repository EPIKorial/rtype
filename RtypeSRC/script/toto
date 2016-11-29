cmake_minimum_required (VERSION 2.8)

if(NOT ${SCRIPT_DIR}/binaries)
  file(MAKE_DIRECTORY ${SCRIPT_DIR}/binaries)
endif()

set(SCRIPT_INCLUDE_DIR "${SCRIPT_DIR}/include")
set(SCRIPT_SOURCE_DIR "${SCRIPT_DIR}/source")
set(SCRIPT_BUILD_DIR "${SCRIPT_DIR}/binaries")

link_directories(${SCRIPT_BUILD_DIR})

#include CMakeFiles script
include(${SCRIPT_SOURCE_DIR}/Default/CMakeLists.txt)
