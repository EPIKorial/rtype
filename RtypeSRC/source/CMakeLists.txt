cmake_minimum_required (VERSION 2.8)

set(RTYPE_SRC "")
set(RTYPE_INCLUDE "")
set(RTYPE_LIB "")

#include .cmake module
include(${RTYPE_SOURCE_DIR}/Server/server.cmake)

include_directories(${RTYPE_INCLUDE})

add_executable(rtype_server ${RTYPE_SRC})

target_link_libraries(rtype_server
  ${RTYPE_LIB}
  )
