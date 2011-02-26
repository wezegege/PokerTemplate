# General

set(project_name pokertemplate)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BACKWARDS_COMPATIBILITY 2.6)

# Directories

set(project_dir ${CMAKE_SOURCE_DIR}/..)

set(source_dir ${project_dir}/src)
set(srcbin_dir ${source_dir}/binaries)
set(srclib_dir ${source_dir}/libraries)

set(build_dir ${project_dir}/build)
set(config_dir ${project_dir}/config)

set(bin_dir ${project_dir}/bin)
set(lib_dir ${bin_dir}/libs)
set(doc_dir ${bin_dir}/doc)
set(res_dir ${bin_dir}/resources)

#configuration files

set(doxyfile_in ${config_dir}/Doxyfile.in)
set(doxyfile_out ${config_dir}/Doxyfile)

#libraries

set(include_dirs "")
set(lib_dirs "")
set(link_libraries "")

