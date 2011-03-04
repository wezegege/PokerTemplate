set(testDir ${srcbin_dir}/pokertemplate/core)

set(threadFiles
  ${testDir}/thread.h
  ${testDir}/cpps/thread.cpp)
CREATE_TEST(${testDir}/tests/testThreadCreation.cc
  "${threadFiles}")

CREATE_TEST(${testDir}/tests/testThreadCancel.cc
  "${threadFiles}")


set(threadManagerFiles
  ${testDir}/threadManager.h
  ${testDir}/cpps/threadManager.cpp)
set(engineFiles
  ${testDir}/engine.h
  ${testDir}/cpps/engine.cpp)
CREATE_TEST(${testDir}/tests/testEngineJoin.cc
  "${threadFiles};${engineFiles};${threadManagerFiles}")

CREATE_TEST(${testDir}/tests/testEngineDestroy.cc
  "${threadFiles};${engineFiles};${threadManagerFiles}")

set(moduleFiles
  ${testDir}/module.h
  ${testDir}/cpps/module.cpp)
CREATE_TEST(${testDir}/tests/testModuleJoin.cc
  "${threadFiles};${moduleFiles};${threadManagerFiles}")

CREATE_TEST(${testDir}/tests/testModuleDestroy.cc
  "${threadFiles};${moduleFiles};${threadManagerFiles}")
