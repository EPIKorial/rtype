set(MODULE_SRC "${MODULE_SRC}"
  "${CMAKE_CURRENT_LIST_DIR}/GameManager.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/GameObject.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/GameObjectManager.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/PrefabCreator.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/LibraryLoader.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/IndieParser.cpp"
  )

set(MODULE_LIB "${MODULE_LIB}"
  "-ldl"
  )