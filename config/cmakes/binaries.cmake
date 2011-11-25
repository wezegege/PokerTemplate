find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-2.4)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${bin_dir})
set(CMAKE_CXX_COMPILER g++)
add_definitions(-Wall -Wextra -pedantic) # -Weffc++
file(GLOB_RECURSE
  cmakes
  ${source_dir}/exe.cmake)
foreach(file ${cmakes})
  include(${file})
endforeach(file)
