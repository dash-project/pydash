project(project_cdash_lib CXX)

# Load global build settings
set(ENABLE_LOGGING ${ENABLE_LOGGING}
    PARENT_SCOPE)
set(ENABLE_TEST_LOGGING ${ENABLE_TEST_LOGGING}
    PARENT_SCOPE)
set(ENABLE_TRACE_LOGGING ${ENABLE_TRACE_LOGGING}
    PARENT_SCOPE)

# Library name
set(CDASH_LIBRARY cdash)

# Source- and header files to be compiled (OBJ):
file(GLOB_RECURSE CDASH_SOURCES "src/*.c" "src/*.h" "src/*.cc")
file(GLOB_RECURSE CDASH_HEADERS "include/*.h")

set(CDASH_LIBRARY_INCLUDE_DIRS
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Includes
include_directories(
  ${CDASH_LIBRARY_INCLUDE_DIRS}
)
# Library compilation sources
add_library(
  ${CDASH_LIBRARY} # library name
  ${CDASH_SOURCES} # sources
  ${CDASH_HEADERS} # headers
)
# Link dependencies
target_link_libraries(
  ${CDASH_LIBRARY}
  ${DART_LIBRARY}
  ${DASH_LIBRARY}
)

# Headers
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/cdash
        DESTINATION include FILES_MATCHING PATTERN "*.h")

# Library
install(TARGETS ${CDASH_LIBRARY}
        DESTINATION lib
        EXPORT "${CDASH_LIBRARY}-targets")

