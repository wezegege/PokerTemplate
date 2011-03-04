set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${bin_dir})

file(
  GLOB_RECURSE
  common_files
  ${srccmn_dir}/*.cpp
  )

file(
  GLOB_RECURSE
  common_headers
  ${srccmn_dir}/*.h
  )

file(
  GLOB
  binaries
  RELATIVE ${srcbin_dir}
  ${srcbin_dir}/*
  )

foreach(binary ${binaries})
  message(STATUS "  Found binary ${binary}")
  file(
    GLOB_RECURSE
    source_files
    ${srcbin_dir}/${binary}/*.cpp
    )

  file(
    GLOB_RECURSE
    header_files
    ${srcbin_dir}/${binary}/*.h
    )

  add_executable(
    ${binary}
    ${source_files}
    ${header_files}
    ${common_files}
    ${common_headers}
    )

  include_directories(${srcbin_dir}/${binary})

  target_link_libraries(
    ${binary}
    ${link_libraries}
    )       
endforeach(binary)
