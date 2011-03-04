set(cmakes ${CMAKE_SOURCE_DIR}/../config/cmakes)
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${cmakes}")

set(separator "--------------------------------------------------")
message(STATUS ${separator})
message(STATUS "Configuring ${project_name} ${VERSION}")

include(config)

message(STATUS "Making tests target")
cmake_minimum_required(VERSION ${CMAKE_BACKWARDS_COMPATIBILITY})

project(${project_name})

include_directories(${include_dirs})
link_directories(${lib_dirs})

message(STATUS ${separator})
message(STATUS "Creating executables")
include(binaries)

message(STATUS ${separator})
message(STATUS "Creating libraries")
include(libraries)

if(${doDocumentation})
  message(STATUS ${separator})
  message(STATUS "Making documentation target")
  include(doxygen)
endif(${doDocumentation})

if(${doInstall})
  include(install)
endif(${doInstall})

if(${doArchive})
  include(archive)
endif(${doArchive})

if(${doTests})
  message(STATUS ${separator})
  message(STATUS "Making tests target")
  include(tests)
endif(${doTests})

message(STATUS ${separator})
