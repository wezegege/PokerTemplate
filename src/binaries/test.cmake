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

###########################################################
message(STATUS "Test a window creation")
###########################################################

add_executable(
  testWindow
  ${srcbin_dir}/pokertemplate/windows/tests/windowTest.cpp
  ${srcbin_dir}/pokertemplate/windows/console.h
  ${srcbin_dir}/pokertemplate/windows/console.cpp
  )
link_directories(${GTKMM_LIBRARY_DIRS})
include_directories(
  ${srcbin_dir}/pokertemplate
  ${GTKMM_INCLUDE_DIRS})
target_link_libraries(
  testWindow
  ${GTKMM_LIBRARIES}
  boost_thread)
add_test(testConsole ${testbin_dir}/testConsole)

###########################################################
message(STATUS "Test of console classes")
###########################################################

add_executable(
  testConsole
  ${srcbin_dir}/pokertemplate/windows/tests/consoleTest.cpp
  ${srcbin_dir}/pokertemplate/windows/console.h
  ${srcbin_dir}/pokertemplate/windows/console.cpp
  )
link_directories(${GTKMM_LIBRARY_DIRS})
include_directories(
  ${srcbin_dir}/pokertemplate
  ${GTKMM_INCLUDE_DIRS})
target_link_libraries(
  testConsole
  ${GTKMM_LIBRARIES}
  boost_thread)
add_test(testConsole ${testbin_dir}/testConsole)
