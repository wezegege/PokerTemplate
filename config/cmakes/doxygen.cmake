find_package(Doxygen)
set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES ${doc_dir})
add_custom_target(doc COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile_out}
  "Generating documentation..."
  WORKING_DIRECTORY ${src_dir})
configure_file(${doxyfile_in} ${doxyfile_out} @ONLY)
