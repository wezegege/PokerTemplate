
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
  modules
  RELATIVE ${srclib_dir}
  ${srclib_dir}/*
  )

foreach(module ${modules})

  message(STATUS "  Found module ${module}")

  file(
    GLOB
    libraries
    RELATIVE ${srclib_dir}/${module}
    ${srclib_dir}/${module}/*
    )

  foreach(library ${libraries})

    message(STATUS "    Found library ${library} in module ${module}")

    file(
      GLOB_RECURSE
      source_files
      ${srclib_dir}/${module}/${library}/*
      )

    file(
      GLOB_RECURSE
      headers_files
      ${srclib_dir}/${module}/${library}/*
      )

    add_library(
      ${library}
      SHARED
      ${source_files}
      ${headers_files}
      ${common_files}
      ${common_headers}
     )


    target_link_libraries(
      ${library}
      ${link_libraries}
      )       

    set_target_properties(${library} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${lib_dir}/${module})
  endforeach(library)

endforeach(module)
