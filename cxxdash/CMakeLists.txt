project(project_cxxdash_lib CXX)

# Load global build settings
set(ENABLE_LOGGING ${ENABLE_LOGGING}
    PARENT_SCOPE)
set(ENABLE_TEST_LOGGING ${ENABLE_TEST_LOGGING}
    PARENT_SCOPE)
set(ENABLE_TRACE_LOGGING ${ENABLE_TRACE_LOGGING}
    PARENT_SCOPE)
set(PYCXX_BASE ${PYCXX_BASE}
    PARENT_SCOPE)

set(PYCXX_INCLUDE_DIR
    ${PYCXX_BASE}/include)
set(PYCXX_LIB_DIR
    ${PYCXX_BASE}/lib)

# Library name
set(CXXDASH_LIBRARY cxxdash)

find_package(PythonLibs)

# Source- and header files to be compiled (OBJ):
file(GLOB_RECURSE CXXDASH_SOURCES "src/*.cxx" "src/*.hxx" "src/*.cc")
file(GLOB_RECURSE CXXDASH_HEADERS "include/*.hxx")

set(CXXDASH_LIBRARY_INCLUDE_DIRS
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Includes
include_directories(
  ${CXXDASH_LIBRARY_INCLUDE_DIRS}
  ${PYCXX_INCLUDE_DIR}
  ${PYTHON_INCLUDE_DIRS}
)
# Library compilation sources
add_library(
  ${CXXDASH_LIBRARY} # library name
  ${CXXDASH_SOURCES} # sources
  ${CXXDASH_HEADERS} # headers
)
# Link dependencies
target_link_libraries(
  ${CXXDASH_LIBRARY}
  ${DART_LIBRARY}
  ${DASH_LIBRARY}
  ${PYTHON_LIBRARIES}
)

# Headers
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/cxxdash
        DESTINATION include FILES_MATCHING PATTERN "*.h")

# Library
install(TARGETS ${CXXDASH_LIBRARY}
        DESTINATION lib
        EXPORT "${CXXDASH_LIBRARY}-targets")

