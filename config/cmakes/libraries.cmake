file(
  GLOB
  modules
  RELATIVE ${srclib_dir}
  ${srclib_dir}/*
  )

foreach(module ${modules})

  file(
    GLOB
    libraries
    RELATIVE ${srclib_dir}/${module}
    ${srclib_dir}/${module}/*
    )

  foreach(library ${libraries})
    file(
      GLOB_RECURSE
      source_files
      ${srclib_dir}/${module}/${library}/*
      )

    add_library(
      ${library}
      SHARED
      ${source_files}
      )

    target_link_libraries(
      ${library}
      ${link_libraries}
      )       

    set_target_properties(${library} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${lib_dir}/${module})
  endforeach(library)

endforeach(module)
