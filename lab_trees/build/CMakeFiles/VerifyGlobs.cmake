# CMAKE generated file: DO NOT EDIT!
# Generated by CMake Version 3.22
cmake_policy(SET CMP0009 NEW)

# cs225_sources at lib/CMakeLists.txt:12 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/cs225/lab_trees/lib/binarytree/*.cpp")
set(OLD_GLOB
  "/workspaces/cs225/lab_trees/lib/binarytree/coloredout.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/cs225/lab_trees/build/CMakeFiles/cmake.verify_globs")
endif()

# cs225_sources at lib/CMakeLists.txt:18 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/cs225/lab_trees/lib/cs225/*.cpp")
set(OLD_GLOB
  "/workspaces/cs225/lab_trees/lib/cs225/HSLAPixel.cpp"
  "/workspaces/cs225/lab_trees/lib/cs225/PNG.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/cs225/lab_trees/build/CMakeFiles/cmake.verify_globs")
endif()

# lodepng_sources at lib/CMakeLists.txt:6 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/cs225/lab_trees/lib/lodepng/*.cpp")
set(OLD_GLOB
  "/workspaces/cs225/lab_trees/lib/lodepng/lodepng.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/cs225/lab_trees/build/CMakeFiles/cmake.verify_globs")
endif()

# lodepng_sources at lib/CMakeLists.txt:6 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/cs225/lab_trees/lib/lodepng/*.h")
set(OLD_GLOB
  "/workspaces/cs225/lab_trees/lib/lodepng/lodepng.h"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/cs225/lab_trees/build/CMakeFiles/cmake.verify_globs")
endif()

# src_sources at src/CMakeLists.txt:5 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/cs225/lab_trees/src/*.cpp")
set(OLD_GLOB
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/cs225/lab_trees/build/CMakeFiles/cmake.verify_globs")
endif()

# src_sources at src/CMakeLists.txt:5 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/cs225/lab_trees/src/*.hpp")
set(OLD_GLOB
  "/workspaces/cs225/lab_trees/src/binarytree.hpp"
  "/workspaces/cs225/lab_trees/src/binarytree_given.hpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/cs225/lab_trees/build/CMakeFiles/cmake.verify_globs")
endif()

# tests_src at CMakeLists.txt:97 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/cs225/lab_trees/tests/*.cpp")
set(OLD_GLOB
  "/workspaces/cs225/lab_trees/tests/tests.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/cs225/lab_trees/build/CMakeFiles/cmake.verify_globs")
endif()
