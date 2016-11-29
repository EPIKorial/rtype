cmake_minimum_required (VERSION 2.8)

project (Rtype)

if(NOT ${CMAKE_SOURCE_DIR}/lib)
  file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
endif()

set(RTYPE_DIR "${CMAKE_SOURCE_DIR}/..")
set(SCRIPT_DIR "${CMAKE_SOURCE_DIR}/script")
set(CMAKE_CONF_DIR "${CMAKE_SOURCE_DIR}/cmake")
set(RTYPE_LIB_DIR "${CMAKE_SOURCE_DIR}/lib")
set(RTYPE_SOURCE_DIR "${CMAKE_SOURCE_DIR}/source")
set(RTYPE_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

set(CMAKE_SYSTEM_FLAGS "")

include_directories(
  "${RTYPE_INCLUDE_DIR}"
  "${SCRIPT_DIR}/include"
  )

link_directories(
  "${RTYPE_LIB_DIR}"
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