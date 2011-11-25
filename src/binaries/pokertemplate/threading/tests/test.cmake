###########################################################
message(STATUS "Test of engine and engineManager classes")
###########################################################

add_executable(
  testThread
  ${srcbin_dir}/pokertemplate/threading/tests/engineTest.cpp
  ${srcbin_dir}/pokertemplate/threading/engine.cpp
  ${srcbin_dir}/pokertemplate/threading/engine.h
  ${srcbin_dir}/pokertemplate/threading/message.h
  ${srcbin_dir}/pokertemplate/threading/engineManager.cpp
  ${srcbin_dir}/pokertemplate/threading/engineManager.h
  )
include_directories(${srcbin_dir}/pokertemplate)
target_link_libraries(
  testThread
  boost_thread)
add_test(testThread ${testbin_dir}/testThread)

