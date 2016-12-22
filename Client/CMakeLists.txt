cmake_minimum_required(VERSION 3.0)
project(client_rtype)

set(SOURCE_FILES 
${CMAKE_CURRENT_LIST_DIR}/Client/App.cpp
${CMAKE_CURRENT_LIST_DIR}/Client/AState.cpp
${CMAKE_CURRENT_LIST_DIR}/Client/Button.cpp
${CMAKE_CURRENT_LIST_DIR}/Client/EmptyState.cpp
${CMAKE_CURRENT_LIST_DIR}/Client/FontLib.cpp
${CMAKE_CURRENT_LIST_DIR}/Client/InputField.cpp
${CMAKE_CURRENT_LIST_DIR}/Client/IUIComponent.cpp
${CMAKE_CURRENT_LIST_DIR}/Client/Label.cpp
${CMAKE_CURRENT_LIST_DIR}/Client/LobbyState.cpp
${CMAKE_CURRENT_LIST_DIR}/Client/main.cpp
${CMAKE_CURRENT_LIST_DIR}/Client/mainWindows.cpp
${CMAKE_CURRENT_LIST_DIR}/Client/MenuState.cpp
${CMAKE_CURRENT_LIST_DIR}/Client/Palette.cpp
${CMAKE_CURRENT_LIST_DIR}/Client/ScreenHelper.cpp
${CMAKE_CURRENT_LIST_DIR}/Client/sfWindow.cpp)


set(LIBS
"-lsfml-system"
"-lsfml-window"
"-lsfml-graphics"
"-lsfml-audio")

add_executable(client_rtype ${SOURCE_FILES})

set_target_properties(client_rtype PROPERTIES COMPILE_FLAGS "-std=c++11")

target_link_libraries(client_rtype ${LIBS})
