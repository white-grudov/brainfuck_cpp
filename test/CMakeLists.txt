cmake_minimum_required(VERSION 3.2)
project(brainfuck_tests)

add_subdirectory(lib/googletest)

include_directories(${BRAINFUCK_HEADERS_DIR})
include_directories(lib/googletest/googletest/include)

set(SOURCE_FILES main.cpp src/brainfuck_tests.cpp)

add_executable(brainfuck_tests ${SOURCE_FILES})
target_link_libraries(brainfuck_tests brainfuck gtest)
install(TARGETS brainfuck_tests DESTINATION bin)

