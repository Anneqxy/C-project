# CMAKE generated file: DO NOT EDIT!
# Generated by CMake Version 3.22
cmake_policy(SET CMP0009 NEW)

# cs225_sources at lib/CMakeLists.txt:12 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/cs225/lab_bst/lib/binarytree/*.cpp")
set(OLD_GLOB
  "/workspaces/cs225/lab_bst/lib/binarytree/coloredout.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/cs225/lab_bst/build/CMakeFiles/cmake.verify_globs")
endif()

# cs225_sources at lib/CMakeLists.txt:18 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/cs225/lab_bst/lib/cs225/*.cpp")
set(OLD_GLOB
  "/workspaces/cs225/lab_bst/lib/cs225/HSLAPixel.cpp"
  "/workspaces/cs225/lab_bst/lib/cs225/PNG.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/cs225/lab_bst/build/CMakeFiles/cmake.verify_globs")
endif()

# lodepng_sources at lib/CMakeLists.txt:6 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/cs225/lab_bst/lib/lodepng/*.cpp")
set(OLD_GLOB
  "/workspaces/cs225/lab_bst/lib/lodepng/lodepng.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/cs225/lab_bst/build/CMakeFiles/cmake.verify_globs")
endif()

# lodepng_sources at lib/CMakeLists.txt:6 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/cs225/lab_bst/lib/lodepng/*.h")
set(OLD_GLOB
  "/workspaces/cs225/lab_bst/lib/lodepng/lodepng.h"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/cs225/lab_bst/build/CMakeFiles/cmake.verify_globs")
endif()

# src_sources at src/CMakeLists.txt:5 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/cs225/lab_bst/src/*.cpp")
set(OLD_GLOB
  "/workspaces/cs225/lab_bst/src/utils.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/cs225/lab_bst/build/CMakeFiles/cmake.verify_globs")
endif()

# src_sources at src/CMakeLists.txt:5 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/cs225/lab_bst/src/*.hpp")
set(OLD_GLOB
  "/workspaces/cs225/lab_bst/src/bst.hpp"
  "/workspaces/cs225/lab_bst/src/bst_given.hpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/cs225/lab_bst/build/CMakeFiles/cmake.verify_globs")
endif()

# tests_src at CMakeLists.txt:97 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/cs225/lab_bst/tests/*.cpp")
set(OLD_GLOB
  "/workspaces/cs225/lab_bst/tests/tests.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/cs225/lab_bst/build/CMakeFiles/cmake.verify_globs")
endif()
