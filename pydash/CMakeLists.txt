project(project_pydash_lib C)

# Library name
set(PYDASH_LIBRARY pydash)

# -- Dependencies --------------------------------------
find_package(Pybind11 REQUIRED)
find_package(Python   REQUIRED)

set(CMAKE_CXX_FLAGS_DEBUG
    "${CMAKE_CXX_FLAGS_DEBUG}   ${PYTHON_FLAGS}")
set(CMAKE_CXX_FLAGS_RELEASE
    "${CMAKE_CXX_FLAGS_RELEASE} ${PYTHON_FLAGS}")


# Source- and header files to be compiled (OBJ):
file(GLOB_RECURSE PYDASH_SOURCES "src/*.c" "src/*.h" "src/*.cc")
file(GLOB_RECURSE PYDASH_HEADERS "include/*.h")

# Includes
include_directories(
  ${PYDASH_HEADERS}
)
# Library compilation sources
add_library(
  ${PYDASH_LIBRARY} # library name
  ${PYDASH_SOURCES} # sources
  ${PYDASH_HEADERS} # headers
)
# Link dependencies
target_link_libraries(
  ${PYDASH_LIBRARY}
  ${DART_LIBRARY}
)

# Headers
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/pydash
        DESTINATION include FILES_MATCHING PATTERN "*.h")

# Library
install(TARGETS ${PYDASH_LIBRARY}
        DESTINATION lib
        EXPORT "${PYDASH_LIBRARY}-targets")

