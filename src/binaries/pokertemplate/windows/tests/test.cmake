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

