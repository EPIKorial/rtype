cmake_minimum_required (VERSION 2.8)

set(MODULE_NAME "rtype_server")
set(MODULE_SRC "${CMAKE_CURRENT_LIST_DIR}/Server.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/RoomManager.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/Room.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/RoomClient.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/GameServer.cpp"
#  "${CMAKE_CURRENT_LIST_DIR}/Main.cpp"
  )
set(MODULE_INCLUDE ""
  )
set(MODULE_LIB "-lNetwork"
  )
set(MODULE_FLAGS "${CMAKE_SYSTEM_FLAGS} -g"
  )

#include .cmake extend configuration files
include("${RTYPE_SOURCE_DIR}/Protocol/Protocol.cmake")
include("${RTYPE_SOURCE_DIR}/Rtype/Rtype.cmake")
include("${RTYPE_SOURCE_DIR}/Utils/Utils.cmake")

include_directories(${MODULE_INCLUDE})

add_library(${MODULE_NAME} SHARED ${MODULE_SRC})

add_dependencies(${MODULE_NAME}
  Network
)

set_target_properties(${MODULE_NAME} PROPERTIES
  COMPILE_FLAGS ${MODULE_FLAGS}
  )

target_link_libraries(${MODULE_NAME}
  ${MODULE_LIB}
  )

if (NOT ANDROID)
  add_executable("Rtype_server_exe" "${CMAKE_CURRENT_LIST_DIR}/Main.cpp")


  add_dependencies("Rtype_server_exe"
    ${MODULE_NAME}
    )

  set_target_properties("Rtype_server_exe" PROPERTIES
    COMPILE_FLAGS ${MODULE_FLAGS}
    )

  target_link_libraries("Rtype_server_exe"
    -lrtype_server
    )
endif (NOT ANDROID)