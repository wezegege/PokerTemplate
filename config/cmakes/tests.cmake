
set(WORKING_DITECTORY ${bin_dir})

enable_testing()
include(CTest)

macro(CREATE_TEST testFile sources)
  get_filename_component(exeName ${testFile} NAME_WE)
  get_filename_component(tempFolder ${testFile} PATH)
  file(RELATIVE_PATH subFolder ${source_dir} ${tempFolder})

  message(STATUS "  adding test ${exeName} in module ${subFolder}")
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${testbin_dir}/${subFolder})
  add_executable(${exeName} ${testFile} ${sources})
  target_link_libraries(
    ${exeName}
    ${link_libraries}
    ) 
  add_test(${exeName} ${testbin_dir}/${subFolder}/${exeName})
endmacro(CREATE_TEST testName sources)

file(GLOB_RECURSE 
  test_configs
  ${source_dir}/*/tests.cmake)

foreach(test_config ${test_configs})
  include(${test_config})
endforeach(test_config ${test_configs})
