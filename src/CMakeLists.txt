cmake_minimum_required(VERSION 3.2)
project(brainfuck_cpp)

add_subdirectory(brainfuck)
set(SOURCE_FILES main.cpp)

add_executable(brainfuck_cpp ${SOURCE_FILES})
target_link_libraries(brainfuck_cpp brainfuck)
install(TARGETS brainfuck_cpp DESTINATION ${DIVISIBLE_INSTALL_BIN_DIR})
