cmake_minimum_required (VERSION 2.8)

set(MODULE_NAME "rtype_server")
set(MODULE_SRC "${CMAKE_CURRENT_LIST_DIR}/server.cpp"
  )
set(MODULE_INCLUDE ""
  )
set(MODULE_LIB ""
  )
set(MODULE_FLAGS "${CMAKE_SYSTEM_FLAGS}"
  )

#include .cmake extend configuration files

include_directories(${MODULE_INCLUDE})

add_executable(${MODULE_NAME} ${MODULE_SRC})

set_target_properties(${MODULE_NAME} PROPERTIES
  COMPILE_FLAGS ${MODULE_FLAGS}
  )

target_link_libraries(${MODULE_NAME}
  ${MODULE_LIB}
  )