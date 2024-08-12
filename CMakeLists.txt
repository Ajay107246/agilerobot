cmake_minimum_required(VERSION 3.5.0)
project(agilerobot VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()
file(GLOB SOURCES "source/*.cpp")
add_executable(agilerobot main.cpp ${SOURCES})

add_custom_command(
    TARGET agilerobot
    POST_BUILD
    COMMAND agilerobot
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Running agilerobot executable...!"
)