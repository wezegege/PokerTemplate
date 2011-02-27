set(cmakes ${CMAKE_SOURCE_DIR}/../config/cmakes)
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${cmakes}")
include(config)

cmake_minimum_required(VERSION ${CMAKE_BACKWARDS_COMPATIBILITY})

project(${project_name})

include_directories(${include_dirs})
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
  include(archive)
endif(${doArchive})

if(${doTests})
  include(tests)
endif(${doTests})

