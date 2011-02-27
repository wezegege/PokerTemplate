# General

set(project_name pokertemplate)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BACKWARDS_COMPATIBILITY 2.8)

set(MAJOR_VERSION 0)
set(MINOR_VERSION 0)
set(PATCH 1)

set(VERSION "v${MAJOR_VERSION}.${MINOR_VERSION}.${PATCH}")

set(separator "--------------------------------------------------")
message(STATUS ${separator})
message(STATUS "Configuring ${project_name} ${VERSION}")

# Builders

option(doInstall "Whether to create the install target" OFF)
option(doDocumentation "Whether to create the doc target" ON)
option(doTests "Whether to create the test target" OFF)
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

set(test_dir ${project_dir}/tests)
set(tstbin_dir ${test_dir}/binaries)
set(tstlib_dir ${test_dir}/libraries)

set(bin_dir ${project_dir}/bin)
set(lib_dir ${bin_dir}/libs)
set(doc_dir ${bin_dir}/doc)
set(res_dir ${bin_dir}/resources)

#configuration files

set(doxyfile_in ${config_dir}/Doxyfile.in)
set(doxyfile_out ${build_dir}/Doxyfile)

#libraries

set(include_dirs "")
set(lib_dirs "")
set(link_libraries "")

#documentation

set(doc_html "YES")
set(doc_latex "YES")
set(doc_man "NO")
set(doc_xml "NO")
set(doc_rtf "NO")
