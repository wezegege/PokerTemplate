

message(STATUS "  Making html documentation : ${doc_html}")
message(STATUS "  Making latex documentation : ${doc_latex}")
message(STATUS "  Making man documentation : ${doc_man}")
message(STATUS "  Making xml documentation : ${doc_xml}")
message(STATUS "  Making rtf documentation : ${doc_rtf}")

find_package(Doxygen)
set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES ${doc_dir})
add_custom_target(doc COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile_out}
  "Generating documentation..."
  WORKING_DIRECTORY ${src_dir})
configure_file(${doxyfile_in} ${doxyfile_out} @ONLY)
