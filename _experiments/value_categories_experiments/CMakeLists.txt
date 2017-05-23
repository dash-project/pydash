project(project_pybind_experiments CXX)


# -- Dependencies --------------------------------------
find_package(Pybind11 REQUIRED)
find_package(Python   REQUIRED)

set(CMAKE_CXX_FLAGS_DEBUG
    "${CMAKE_CXX_FLAGS_DEBUG}   ${PYTHON_FLAGS}")
set(CMAKE_CXX_FLAGS_RELEASE
    "${CMAKE_CXX_FLAGS_RELEASE} ${PYTHON_FLAGS}")

# -- Target --------------------------------------------

set(GOS_LIBRARY gos)

set(PYBIND_EXPERIMENTS_TARGET_NAME ${GOS_LIBRARY})


file(GLOB_RECURSE PYBIND_EXPERIMENTS_SOURCES
     "src/*.c" "src/*.h" "src/*.cc" "src/*.cpp" )
file(GLOB_RECURSE PYBIND_EXPERIMENTS_HEADERS
     "include/*.h")


add_library(
  ${PYBIND_EXPERIMENTS_TARGET_NAME}
# SHARED
  ${PYBIND_EXPERIMENTS_HEADERS}
  ${PYBIND_EXPERIMENTS_SOURCES}
)



target_link_libraries(
  ${DNANTS_LIBGOS_TARGET_NAME}
  ${PYTHON_LIBRARY}
)

set_target_properties(
  ${DNANTS_LIBGOS_TARGET_NAME}
  PROPERTIES 
  CXX_STANDARD 11
)
set_target_properties(
  ${DNANTS_LIBGOS_TARGET_NAME}
  PROPERTIES
  CXX_STANDARD_REQUIRED 11
)

install(
  TARGETS ${DNANTS_LIBGOS_TARGET_NAME}
  EXPORT  libgosConfig
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
)
install(
  DIRECTORY include/
  DESTINATION include
)
install(
  EXPORT libgosConfig
  DESTINATION share/libgos/cmake
)

export(
  TARGETS ${DNANTS_LIBGOS_TARGET_NAME}
  FILE libgosConfig.cmake
)

