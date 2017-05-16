
cmake_minimum_required(VERSION 2.8.12)
project(pydash)

set(PYBIND11_BASE ${PYBIND11_BASE} PARENT_SCOPE)
set(DASH_BASE     ${DASH_BASE}     PARENT_SCOPE)

# include(${CMAKE_SOURCE_DIR}/CMakeExt/DASH.cmake)

include_directories(
  ${DASH_BASE}/include
# ${DASH_INCLUDE_DIRS}
)

link_directories(
  ${DASH_BASE}/lib
)

message(STATUS "Looking for pybind11 config in ${PYBIND11_BASE}")

set(pybind11_DIR ${PYBIND11_BASE}/share/cmake/pybind11)

find_package(pybind11 CONFIG REQUIRED)

add_library(
  pydash MODULE
  src/Init.cc
)

target_link_libraries(
  pydash
  pybind11::module
# ${DASH_LIBRARIES}
  libdash-mpi.a
  libdart-mpi.a
  libdart-base.a
)

# Install library
install(TARGETS pydash
        DESTINATION lib
        EXPORT "pydash-targets")

# Install exports
install(
  EXPORT "pydash-targets"
  DESTINATION cmake)


