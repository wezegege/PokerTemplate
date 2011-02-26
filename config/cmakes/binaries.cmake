set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${bin_dir})

file(
  GLOB
  binaries
  RELATIVE ${srcbin_dir}
  ${srcbin_dir}/*
  )

foreach(binary ${binaries})
  message("Found binary ${binary}")
  file(
    GLOB_RECURSE
    source_files
    ${srcbin_dir}/${binary}/*
    )

  add_executable(
    ${binary}
    ${source_files}
    )

  target_link_libraries(
    ${binary}
    ${link_libraries}
    )       
endforeach(binary)
