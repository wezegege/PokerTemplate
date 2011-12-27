find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-2.4)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${bin_dir})
set(CMAKE_CXX_COMPILER g++)
add_definitions(-Wall -Wextra -pedantic)
#add_definitions(-Weffc++ -Wunreachable-code -Wold-style-cast -Woverloaded-virtual -Wfloat-equal -Wwrite-strings -Wpointer-arith -Wcast-qual -Wcast-align -Wconversion -Wshadow -Wredundant-decls -Wdouble-promotion -Winit-self -Wswitch-default -Wswitch-enum -Wundef -Wlogical-op -Winline)
file(GLOB_RECURSE
  cmakes
  ${source_dir}/exe.cmake)
foreach(file ${cmakes})
  include(${file})
endforeach(file)
