set(WORKING_DITECTORY ${bin_dir})

enable_testing()
include(CTest)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${testbin_dir})

#TODO: check create_test_sourcelist
#add_executable()
#set_target_property( PROPERTIES RUNTIME_OUTPUT_LIBRARY )
#add_test()
#create_test_sourcelist()

