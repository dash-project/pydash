
cmake_minimum_required(VERSION 2.8.12)
project(pydash)

set(PYBIND11_BASE ${PYBIND11_BASE} PARENT_SCOPE)

message(STATUS "Looking for pybind11 config in ${PYBIND11_BASE}")

# set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMakeExt)
set(pybind11_DIR ${PYBIND11_BASE}/share/cmake/pybind11)

# include(${CMAKE_SOURCE_DIR}/CMakeExt/FindPybind11.cmake)
# include(${CMAKE_SOURCE_DIR}/CMakeExt/pybind11Tools.cmake)
# include(${CMAKE_SOURCE_DIR}/CMakeExt/pybind11Config.cmake)

find_package(pybind11 CONFIG REQUIRED)

add_library(
  dash MODULE
  src/Init.cc
)

target_link_libraries(
  dash
  pybind11::module
  dart-base
  dart-mpi
  dash-mpi
)

set_target_properties(dart-base PROPERTIES POSITION_INDEPENDENT_CODE TRUE)
set_target_properties(dart-mpi  PROPERTIES POSITION_INDEPENDENT_CODE TRUE)
set_target_properties(dash-mpi  PROPERTIES POSITION_INDEPENDENT_CODE TRUE)


