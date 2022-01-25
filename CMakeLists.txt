cmake_minimum_required(VERSION 3.6)

set(CMAKE_CXX_STANDARD 11)

project(eigen-cdd LANGUAGES CXX VERSION 0.4.3)
include(CTest)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting default build type to RelWithDebInfo as none was provided")
  set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING "Choose the type of a build" FORCE)
endif()

# Find CDD
if(NOT DEFINED CDD_PREFIX)
  set(CDD_PREFIX ${CMAKE_INSTALL_PREFIX})
endif()
include(cmake/CDD.cmake)

# Find Eigen
find_package(Eigen3 QUIET NO_CMAKE_PACKAGE_REGISTRY)
if(Eigen3_FOUND)
  set(EIGEN_DEPENDENCY "find_package(Eigen3 REQUIRED NO_CMAKE_PACKAGE_REGISTRY)")
else()
  set(EIGEN_DEPENDENCY "find_package(Eigen3 MODULE REQUIRED)")
  find_package(Eigen3 MODULE REQUIRED)
endif()

add_subdirectory(cmake)
add_subdirectory(src)

if(BUILD_TESTING)
  add_subdirectory(tests)
endif()
