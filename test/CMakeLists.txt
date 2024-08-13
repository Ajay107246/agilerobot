cmake_minimum_required(VERSION 3.30)
#project(agilerobot_test)
set(This test_agilerobot)

#file(GLOB SOURCE_TEST "test_agileMotorControl.cpp")
set(
    SOURCE_TEST
    test_agileMotorControl.cpp
)

add_library(test_agilerobot_lib STATIC ${SOURCE_TEST})

add_executable(${This} ${SOURCE_TEST})
target_link_libraries(
    ${This} PUBLIC
    gtest_main
    test_agilerobot_lib
)

add_test(
    NAME ${This}
    COMMAND ${This}
)