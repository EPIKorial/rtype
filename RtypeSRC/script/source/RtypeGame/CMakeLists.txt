cmake_minimum_required (VERSION 2.8)

project (RtypeGame-Script)

###################### TO MODIFY ##############################################
Set(SCRIPT-NAME "RtypeGame")
Set(SCRIPT-FLAGS "-DSCRIPT_RTYPEGAME ${CMAKE_SYSTEM_FLAGS}")
############################################################################### 

set(SCRIPT-DIR "${SCRIPT_SOURCE_DIR}/${SCRIPT-NAME}")

set(SCRIPT-SRC "${SCRIPT-DIR}/${SCRIPT-NAME}.cpp"
  )

add_library(${SCRIPT-NAME} SHARED ${SCRIPT-SRC})

#add_dependencies(${SCRIPT-NAME} Rtype)
set_target_properties(${SCRIPT-NAME} PROPERTIES
  LIBRARY_OUTPUT_DIRECTORY ${SCRIPT_BUILD_DIR}
  COMPILE_FLAGS
  ${SCRIPT-FLAGS}
  )

target_link_libraries(${SCRIPT-NAME}
  )