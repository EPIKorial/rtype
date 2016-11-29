cmake_minimum_required (VERSION 2.8)

set(MODULE_NAME "Network")
set(MODULE_SRC "${CMAKE_CURRENT_LIST_DIR}/sockets/Server.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/sockets/Client.cpp"
  )
set(MODULE_INCLUDE ""
  )
set(MODULE_LIB "-lpthread"
  )
set(MODULE_FLAGS "${CMAKE_SYSTEM_FLAGS}"
  )

#include .cmake extend configuration files

include_directories(${MODULE_INCLUDE})

add_library(${MODULE_NAME} SHARED ${MODULE_SRC})

set_target_properties(${MODULE_NAME} PROPERTIES
  COMPILE_FLAGS ${MODULE_FLAGS}
  )

target_link_libraries(${MODULE_NAME}
  ${MODULE_LIB}
  )