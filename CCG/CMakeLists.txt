cmake_minimum_required(VERSION 3.6)

# Name the project
project(CCGHomework)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin) 
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

if(NOT MSVC)
  set(CMAKE_CXX_FLAGS "-fpermissive")
endif(NOT MSVC)

# Find MeshLib
find_package(MeshLib REQUIRED HINTS "${CMAKE_SOURCE_DIR}/3rdparty")
if (NOT MeshLib_FOUND)
    message(FATAL_ERROR "MeshLib Not Found!")
endif (NOT MeshLib_FOUND)

# Find OpenGL and GLUT
if(MSVC)
  find_package(freeglut REQUIRED HINTS "${CMAKE_SOURCE_DIR}/3rdparty")
  if (NOT freeglut_FOUND)
    message(FATAL_ERROR "freeglut Not Found!")
  endif (NOT freeglut_FOUND)
else(MSVC)
  find_package(OpenGL REQUIRED)
  find_package(GLUT REQUIRED)
endif(MSVC)

# Add module
add_subdirectory("cutgraph")
add_subdirectory("harmonic_map")
add_subdirectory("hodge_decomposition")
add_subdirectory("spherical_harmonic_map")
add_subdirectory("ot_2d")
add_subdirectory("KoebeIteration")