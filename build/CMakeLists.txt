cmake_minimum_required(VERSION ${CMAKE_BACKWARDS_COMPATIBILITY})

project(${project_name})
set(EXECUTABLE_OUTPUT_PATH ../${bin_dir})

include_directories(${include_dirs})
link_directories(${lib_dirs})

file(
	GLOB_RECURSE
	source_files
	../${source_dir}/*
)

add_executable(
	${project_name}
	${source_files}
)

target_link_libraries(
	${project_name}
	${link_libraries}
)
