set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${bin_dir})
file(GLOB_RECURSE
  cmakes
  ${source_dir}/exe.cmake)
foreach(file ${cmakes})
  include(${file})
endforeach(file)
