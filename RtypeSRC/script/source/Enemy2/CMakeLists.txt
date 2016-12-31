cmake_minimum_required (VERSION 2.8)

project (Enemy2-Script)

###################### TO MODIFY ##############################################
Set(SCRIPT-NAME "Enemy2")
Set(SCRIPT-FLAGS "-DSCRIPT_ENEMY2 ${CMAKE_SYSTEM_FLAGS}")
Set(SCRIPT-LIB "${SCRIPT-LIB} -lrtype_server")
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

add_dependencies(${SCRIPT-NAME}
  rtype_server
  )

target_link_libraries(${SCRIPT-NAME}
  ${SCRIPT-LIB}
  )