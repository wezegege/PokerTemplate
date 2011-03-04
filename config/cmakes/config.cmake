# General

set(project_name pokertemplate)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BACKWARDS_COMPATIBILITY 2.8)

execute_process(COMMAND git describe --abbrev=4 HEAD
  OUTPUT_VARIABLE VERSION
  OUTPUT_STRIP_TRAILING_WHITESPACE)

# Builders

option(doInstall "Whether to create the install target" OFF)
option(doDocumentation "Whether to create the doc target" ON)
option(doTests "Whether to create the test target" ON)
option(doArchive "Whether to create the archive" OFF)

message(STATUS "  Building install module : ${doInstall}")
message(STATUS "  Building documentation module : ${doDocumentation}")
message(STATUS "  Building tests module : ${doTests}")
message(STATUS "  Building archive module : ${doArchive}")

# Directories

set(project_dir ${CMAKE_SOURCE_DIR}/..)

set(source_dir ${project_dir}/src)
set(srcbin_dir ${source_dir}/binaries)
set(srclib_dir ${source_dir}/libraries)
set(srccmn_dir ${source_dir}/common)

set(build_dir ${project_dir}/build)
set(config_dir ${project_dir}/config)

set(test_dir ${source_dir}/tests)
set(testbin_dir ${build_dir}/tests)

set(bin_dir ${project_dir}/bin)
set(lib_dir ${bin_dir}/libs)
set(doc_dir ${bin_dir}/doc)
set(res_dir ${bin_dir}/resources)

#configuration files

set(doxyfile_in ${config_dir}/Doxyfile.in)
set(doxyfile_out ${build_dir}/Doxyfile)

#libraries

set(include_dirs ${srccmn_dir} /usr/include)
set(lib_dirs /usr/lib)
set(link_libraries pthread)

#documentation

set(doc_html "YES")
set(doc_latex "YES")
set(doc_man "NO")
set(doc_xml "NO")
set(doc_rtf "NO")
