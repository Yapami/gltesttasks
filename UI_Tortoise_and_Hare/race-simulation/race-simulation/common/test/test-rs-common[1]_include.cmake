if(EXISTS "/home/user/QT_Projects/TRY_5/race-simulation/race-simulation/common/test/test-rs-common[1]_tests.cmake")
  include("/home/user/QT_Projects/TRY_5/race-simulation/race-simulation/common/test/test-rs-common[1]_tests.cmake")
else()
  add_test(test-rs-common_NOT_BUILT test-rs-common_NOT_BUILT)
endif()
