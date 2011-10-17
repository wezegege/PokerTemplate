
set(WORKING_DITECTORY ${bin_dir})

enable_testing()
include(CTest)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${testbin_dir})
file(GLOB_RECURSE
  cmakes
  ${source_dir}/test.cmake)
foreach(file ${cmakes})
  include(${file})
endforeach(file)
