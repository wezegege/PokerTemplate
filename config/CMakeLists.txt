set(cmakes "cmakes")

include(${cmakes}/config.cmake)

cmake_minimum_required(VERSION ${CMAKE_BACKWARDS_COMPATIBILITY})

project(${project_name})
set(EXECUTABLE_OUTPUT_PATH ../${bin_dir})
set(LIBRARY_OUTPUT_PATH ../${lib_dir})

include_directories(${include_dirs})
link_directories(${lib_dirs})

include(${cmakes}/binaries.cmake)

include(${cmakes}/libraries.cmake)

include(${cmakes}/doxygen.cmake)


