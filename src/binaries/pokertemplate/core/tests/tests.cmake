set(testDir ${srcbin_dir}/pokertemplate/core)

set(sourceFiles
  ${testDir}/thread.h
  ${testDir}/cpps/thread.cpp)
CREATE_TEST(${testDir}/tests/testThreadCreation.cc
  "${sourceFiles}")

CREATE_TEST(${testDir}/tests/testThreadCancel.cc
  "${sourceFiles}")
