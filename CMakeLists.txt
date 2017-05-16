project(project_pydash)

cmake_minimum_required (VERSION 2.8)

if(POLICY CMP0054)
  cmake_policy(SET CMP0054 OLD)
endif(POLICY CMP0054)
if(POLICY CMP0053)
  cmake_policy(SET CMP0053 OLD)
endif(POLICY CMP0053)
if(POLICY CMP0007)
  cmake_policy(SET CMP0007 OLD)
endif(POLICY CMP0007)
if(POLICY CMP0003)
  cmake_policy(SET CMP0003 OLD)
endif(POLICY CMP0003)
if(POLICY CMP0060)
  cmake_policy(SET CMP0060 OLD)
endif(POLICY CMP0060)
if(POLICY CMP0004)
  cmake_policy(SET CMP0004 OLD)
endif(POLICY CMP0004)
if(POLICY CMP0016)
  cmake_policy(SET CMP0016 OLD)
endif(POLICY CMP0016)

option(BUILD_DOCS
       "Whether doxygen documentation should be installed" off)
option(BUILD_EXAMPLES
       "Specify whether to build examples" on)
option(BUILD_TESTS
       "Specify whether to build tests" on)
option(ENABLE_COMPILER_WARNINGS
       "Specify whether strict compiler warnings should be enabled" on)
option(WARNINGS_AS_ERRORS
       "Specify whether warnings should be treated as errors" off)
option(ENABLE_LOGGING
       "Specify whether logging should be enabled" off)
option(ENABLE_TEST_LOGGING
       "Specify whether logging of unit test messages is enabled" on)
option(ENABLE_TRACE_LOGGING
       "Specify whether trace messages should be logged" off)
option(ENABLE_ASSERTIONS
       "Specify whether runtime assertions should be checked" off)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMakeExt)

# include(${CMAKE_SOURCE_DIR}/CMakeExt/MPI.cmake)
include(${CMAKE_SOURCE_DIR}/CMakeExt/MessageColor.cmake)
include(${CMAKE_SOURCE_DIR}/CMakeExt/Doxygen.cmake)
include(${CMAKE_SOURCE_DIR}/CMakeExt/InstallFiles.cmake)
include(${CMAKE_SOURCE_DIR}/CMakeExt/FileSystem.cmake)


## Version number
set(PYDASH_VERSION_MAJOR 0 CACHE STRING "PyDASH major version number.")
set(PYDASH_VERSION_MINOR 1 CACHE STRING "PyDASH minor version number.")
set(PYDASH_VERSION_PATCH 0 CACHE STRING "PyDASH patch version number.")
mark_as_advanced(
  PYDASH_VERSION_MAJOR
  PYDASH_VERSION_MINOR
  PYDASH_VERSION_PATCH)

set(PYDASH_VERSION
    "${PYDASH_VERSION_MAJOR}.${PYDASH_VERSION_MINOR}.${PYDASH_VERSION_PATCH}"
    CACHE STRING INTERNAL FORCE)
set(PYDASH_VERSIONED_PROJECT_NAME
    "pydash-${PYDASH_VERSION_MAJOR}.${PYDASH_VERSION_MINOR}.${PYDASH_VERSION_PATCH}"
    CACHE STRING INTERNAL FORCE)

set(CMAKE_RULE_MESSAGES OFF)
set(CMAKE_VERBOSE_MAKEFILE OFF)
set(CMAKE_COLOR_MAKEFILE ON)

## Install path
if (INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX ${INSTALL_PREFIX})
else()
  set(CMAKE_INSTALL_PREFIX "$ENV{HOME}/opt/")
endif()

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif()

## Begin DASH Libraries -------------------------------------------------

set(DASH_DART_IMPL "MPI")

if("$ENV{DASH_BASE}" STREQUAL "")
  set(DASH_BASE_DIR "$ENV{HOME}/opt/dash-0.3.0")
  message(STATUS "DASH_BASE not set, using ${DASH_BASE_DIR}")
else()
  set(DASH_BASE_DIR $ENV{DASH_BASE})
  message(STATUS "DASH_BASE set to ${DASH_BASE_DIR}")
endif()

if("$ENV{PYBIND11_BASE}" STREQUAL "")
  set(PYBIND11_BASE "$ENV{HOME}/opt/pybind11"
      CACHE STRING "Installation path of pybind11")
else()
  set(PYBIND11_BASE $ENV{PYBIND11_BASE}
      CACHE STRING "Installation path of pybind11")
endif()

set(DASH_BASE_CMAKE_DIR "${DASH_BASE_DIR}/cmake")

find_package("DASH-${DASH_DART_IMPL}"
             REQUIRED
             HINTS ${DASH_BASE_CMAKE_DIR})
find_package(MPI)

message(STATUS "Looking for DASH installation in: ${DASH_BASE_DIR}")
if(DASH-MPI_FOUND)
  message(STATUS "DASH ${DASH_DART_IMPL} found")
endif()

if(DART-MPI_FOUND)
  message(STATUS "DART ${DASH_DART_IMPL} found")
endif()

# message(STATUS "MPI include path: ${MPI_INCLUDE_PATH}")
# message(STATUS "MPI libraries:")
# foreach (MPI_C_LIB ${MPI_C_LIBRARIES})
#   message(STATUS "    " ${MPI_C_LIB})
# endforeach()
# message(STATUS "MPI link flags:")
# foreach (MPI_LINK_FLAG ${MPI_LINK_FLAGS})
#   message(STATUS "   " ${MPI_LINK_FLAG})
# endforeach()
#
# foreach (MPI_INC_ ${MPI_INCLUDE_PATH})
#   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I${MPI_INC_}" )
# endforeach()
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${DASH_CXX_FLAGS} ${CXX_FLAGS}" )

string(TOLOWER ${DASH_DART_IMPL} DASH_DART_IMPL_LC)

## End DASH Libraries ---------------------------------------------------


## Build results output directories

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/shared)

add_subdirectory(bindings)

## Documentation
if (BUILD_DOCS)
  CreateDoxygenTarget()
endif()

message(EMPH "PyDASH version ${PYDASH_VERSION}")
message(EMPH "-----------------------------------------------------------")
message(EMPH "Install prefix:           (INSTALL_PREFIX)                 "
        ${CMAKE_INSTALL_PREFIX})
message(EMPH "Build type:               (CMAKE_BUILD_TYPE)               "
        ${CMAKE_BUILD_TYPE})
message(INFO "Strict compiler warnings: (ENABLE_COMPILER_WARNINGS)       "
        ${ENABLE_COMPILER_WARNINGS})
message(INFO "Debug log messages:       (ENABLE_LOGGING)                 "
        ${ENABLE_LOGGING})
message(INFO "Trace log messages:       (ENABLE_TRACE_LOGGING)           "
        ${ENABLE_TRACE_LOGGING})
message(INFO "Runtime assertions:       (ENABLE_ASSERTIONS)              "
        ${ENABLE_ASSERTIONS})
message(INFO "C   compiler id:          ${CMAKE_C_COMPILER_ID}")
message(INFO "C++ compiler id:          ${CMAKE_CXX_COMPILER_ID}")

