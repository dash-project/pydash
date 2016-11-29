project(project_cdash_lib CXX)

# Library name
set(CDASH_LIBRARY cdash)

# Source- and header files to be compiled (OBJ):
file(GLOB_RECURSE CDASH_SOURCES "src/*.c" "src/*.h" "src/*.cc")
file(GLOB_RECURSE CDASH_HEADERS "include/*.h")

# Includes
include_directories(
  ${CDASH_HEADERS}
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
)

# Headers
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/cdash
        DESTINATION include FILES_MATCHING PATTERN "*.h")

# Library
install(TARGETS ${CDASH_LIBRARY}
        DESTINATION lib
        EXPORT "${CDASH_LIBRARY}-targets")

