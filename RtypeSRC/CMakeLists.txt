cmake_minimum_required (VERSION 2.8)

project (Rtype)

set(RTYPE_DIR "${CMAKE_SOURCE_DIR}/..")
set(SCRIPT_DIR "${CMAKE_SOURCE_DIR}/script")
set(CMAKE_CONF_DIR "${CMAKE_SOURCE_DIR}/cmake")
set(RTYPE_SOURCE_DIR "${CMAKE_SOURCE_DIR}/source")
set(RTYPE_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

include_directories(
  "${RTYPE_INCLUDE_DIR}"
  "${SCRIPT_DIR}/include"
  )

if (UNIX AND NOT ANDROID)
  include(${CMAKE_CONF_DIR}/system/SystemLinux.cmake)
elseif (ANDROID)
  include(${CMAKE_CONF_DIR}/system/SystemAndroid.cmake)
else ()
  include(${CMAKE_CONF_DIR}/system/SystemWindows.cmake)
endif (UNIX AND NOT ANDROID)

include(${SCRIPT_DIR}/CMakeLists.txt)
include(${RTYPE_SOURCE_DIR}/CMakeLists.txt)