cmake_minimum_required(VERSION 2.8)

project(client_rtype)

include_directories("${CMAKE_CURRENT_LIST_DIR}/lib/include")

set(SOURCE_FILES 
${CMAKE_CURRENT_LIST_DIR}/Client/App.cpp
${CMAKE_CURRENT_LIST_DIR}/Client/AState.cpp
${CMAKE_CURRENT_LIST_DIR}/Client/Button.cpp
${CMAKE_CURRENT_LIST_DIR}/Client/CreationState.cpp
${CMAKE_CURRENT_LIST_DIR}/Client/EmptyState.cpp
${CMAKE_CURRENT_LIST_DIR}/Client/Entity.cpp
${CMAKE_CURRENT_LIST_DIR}/Client/FontLib.cpp
${CMAKE_CURRENT_LIST_DIR}/Client/GameState.cpp
${CMAKE_CURRENT_LIST_DIR}/Client/InputField.cpp
${CMAKE_CURRENT_LIST_DIR}/Client/IUIComponent.cpp
${CMAKE_CURRENT_LIST_DIR}/Client/Jukebox.cpp
${CMAKE_CURRENT_LIST_DIR}/Client/Label.cpp
${CMAKE_CURRENT_LIST_DIR}/Client/LobbyState.cpp
${CMAKE_CURRENT_LIST_DIR}/Client/main.cpp
${CMAKE_CURRENT_LIST_DIR}/Client/mainWindows.cpp
${CMAKE_CURRENT_LIST_DIR}/Client/MenuState.cpp
${CMAKE_CURRENT_LIST_DIR}/Client/MobLib.cpp
${CMAKE_CURRENT_LIST_DIR}/Client/Palette.cpp
${CMAKE_CURRENT_LIST_DIR}/Client/PlayerController.cpp
${CMAKE_CURRENT_LIST_DIR}/Client/ReadyState.cpp
${CMAKE_CURRENT_LIST_DIR}/Client/ScreenHelper.cpp
${CMAKE_CURRENT_LIST_DIR}/Client/ScrollingBack.cpp
${CMAKE_CURRENT_LIST_DIR}/Client/SelectionState.cpp
${CMAKE_CURRENT_LIST_DIR}/Client/sfWindow.cpp
)

link_directories("${CMAKE_CURRENT_LIST_DIR}/lib/bin")

set(LIBS
"-lsfml-system"
"-lsfml-window"
"-lsfml-graphics"
"-lsfml-audio")

add_executable(client_rtype ${SOURCE_FILES})

set_target_properties(client_rtype PROPERTIES COMPILE_FLAGS "-std=c++14")

target_link_libraries(client_rtype ${LIBS})
