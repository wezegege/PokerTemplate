###########################################################
message(STATUS "Test a window creation")
###########################################################

add_executable(
  testWindow
  ${srcbin_dir}/pokertemplate/windows/tests/windowTest.cpp
  ${srcbin_dir}/pokertemplate/windows/console.h
  ${srcbin_dir}/pokertemplate/windows/console.cpp
  ${srcbin_dir}/pokertemplate/widgets/chat.h
  ${srcbin_dir}/pokertemplate/widgets/chat.cpp
  ${srcbin_dir}/pokertemplate/utils/time.h
  ${srcbin_dir}/pokertemplate/utils/time.cpp
  )
link_directories(${GTKMM_LIBRARY_DIRS})
include_directories(
  ${srcbin_dir}/pokertemplate
  ${GTKMM_INCLUDE_DIRS}
  /usr/lib64)
target_link_libraries(
  testWindow
  ${GTKMM_LIBRARIES}
  stdc++)
add_test(testWindow ${testbin_dir}/testWindow)

###########################################################
message(STATUS "Test of console classes")
###########################################################

add_executable(
  testConsole
  ${srcbin_dir}/pokertemplate/windows/tests/consoleTest.cpp
  ${srcbin_dir}/pokertemplate/widgets/chat.h
  ${srcbin_dir}/pokertemplate/widgets/chat.cpp
  ${srcbin_dir}/pokertemplate/windows/console.h
  ${srcbin_dir}/pokertemplate/windows/console.cpp
  ${srcbin_dir}/pokertemplate/utils/time.h
  ${srcbin_dir}/pokertemplate/utils/time.cpp
  )
link_directories(${GTKMM_LIBRARY_DIRS})
include_directories(
  ${srcbin_dir}/pokertemplate
  ${GTKMM_INCLUDE_DIRS}
  /usr/lib64)
target_link_libraries(
  testConsole
  ${GTKMM_LIBRARIES}
  stdc++)
add_test(testConsole ${testbin_dir}/testConsole)

