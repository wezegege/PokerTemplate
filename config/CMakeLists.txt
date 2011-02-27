set(cmakes ${CMAKE_SOURCE_DIR}/../config/cmakes)
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${cmakes}")
include(config)

cmake_minimum_required(VERSION ${CMAKE_BACKWARDS_COMPATIBILITY})

project(${project_name})

link_directories(${lib_dirs})

include(binaries)

include(libraries)

if(${doDocumentation})
  include(doxygen)
endif(${doDocumentation})

if(${doInstall})
  include(install)
endif(${doInstall})

if(${doArchive})
  message(STATUS "Making archive target")
  include(archive)
endif(${doArchive})

if(${doTests})
  message(STATUS "Making tests target")
  include(tests)
endif(${doTests})

message(STATUS "--------------------------------------------------")
