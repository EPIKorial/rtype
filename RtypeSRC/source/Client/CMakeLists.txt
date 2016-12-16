cmake_minimum_required (VERSION 2.8)

set(MODULE_NAME "rtype_client")
set(MODULE_SRC  "${CMAKE_CURRENT_LIST_DIR}/main.cpp"
"${CMAKE_CURRENT_LIST_DIR}/ClientTcp.cpp"
  )
set(MODULE_INCLUDE ""
  )
set(MODULE_LIB "-lNetwork"
  )
set(MODULE_FLAGS "${CMAKE_SYSTEM_FLAGS} -g"
  )

#include .cmake extend configuration files
include("${RTYPE_SOURCE_DIR}/Protocol/Protocol.cmake")

include_directories(${MODULE_INCLUDE})

add_executable(${MODULE_NAME} ${MODULE_SRC})

add_dependencies(${MODULE_NAME}
  Network
)

set_target_properties(${MODULE_NAME} PROPERTIES
  COMPILE_FLAGS ${MODULE_FLAGS}
  )

target_link_libraries(${MODULE_NAME}
  ${MODULE_LIB}
  )