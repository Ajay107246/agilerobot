if(EXISTS "D:/agilerobot/build/test_agilerobot[1]_tests.cmake")
  include("D:/agilerobot/build/test_agilerobot[1]_tests.cmake")
else()
  add_test(test_agilerobot_NOT_BUILT test_agilerobot_NOT_BUILT)
endif()
