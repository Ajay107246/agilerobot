cmake_minimum_required(VERSION 3.30)
project(agilerobot VERSION 0.1.0 LANGUAGES C CXX)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the build type to Debug
# Compiler generates debug information & disables optimizations. useful for debugging the code
set(CMAKE_BUILD_TYPE Debug)

enable_testing()

# Add coverage flags
if(CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
  DOWNLOAD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

#file(GLOB SOURCES "source/*.cpp")
#file(GLOB SOURCES_TEST "test/*.cpp")

#add_executable(agilerobot main.cpp ${SOURCES})
#add_executable(test_agilerobot ${SOURCES} ${SOURCES_TEST})

add_executable(test_agilerobot source/agileMotorControl.cpp test/test_agileMotorControl.cpp test/test_agileMotorControl_funcPtr.cpp)
#add_subdirectory(test)

target_link_libraries(test_agilerobot gtest_main)

add_custom_command(
    TARGET test_agilerobot
    POST_BUILD
    COMMAND test_agilerobot
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Running test_agilerobot executable...!"
)