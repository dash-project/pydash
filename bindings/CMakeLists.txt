
cmake_minimum_required(VERSION 2.8.12)
project(pydash)

set(PYBIND11_BASE ${PYBIND11_BASE} PARENT_SCOPE)
set(DASH_BASE     ${DASH_BASE}     PARENT_SCOPE)

# include(${CMAKE_SOURCE_DIR}/CMakeExt/DASH.cmake)
# include_directories(
#   ${DASH_INCLUDE_DIRS}
# )
# link_directories(
#   ${DASH_BASE}/lib
# )


message(STATUS "Looking for DASH config in ${DASH_BASE}")
set(dart-base_DIR ${DASH_BASE}/cmake)
set(dart-mpi_DIR  ${DASH_BASE}/cmake)
set(dash-mpi_DIR  ${DASH_BASE}/cmake)
find_package(dart-base CONFIG REQUIRED)
find_package(dart-mpi  CONFIG REQUIRED)
find_package(dash-mpi  CONFIG REQUIRED)


message(STATUS "Looking for pybind11 config in ${PYBIND11_BASE}")
find_package(pybind11 CONFIG REQUIRED
             HINTS ${PYBIND11_BASE})
message(STATUS "Found pybind11 v${pybind11_VERSION}: "
        ${pybind11_INCLUDE_DIRS})

add_library(
  pydash MODULE
  src/Init.cc
)

target_link_libraries(
  pydash
  pybind11::module
  ${DASH_LIBRARIES}
  ${PYTHON_LIBRARIES}
# ${pybind11_LIBRARIES}
)

set_target_properties(
	pydash
  PROPERTIES PREFIX ""
)

# Install library
install(TARGETS pydash
        DESTINATION lib
        EXPORT "pydash-targets")

# Install exports
install(
  EXPORT "pydash-targets"
  DESTINATION cmake)


