cmake_minimum_required(VERSION 3.2)

project(cmake-project-template)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3")

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

set(BRAINFUCK_INSTALL_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(BRAINFUCK_INSTALL_BIN_DIR ${PROJECT_SOURCE_DIR}/bin)
set(BRAINFUCK_INSTALL_LIB_DIR ${PROJECT_SOURCE_DIR}/lib)

set(BRAINFUCK_HEADERS_DIR ${PROJECT_SOURCE_DIR}/src/brainfuck)

include_directories(${BRAINFUCK_INSTALL_INCLUDE_DIR})
include_directories(${BRAINFUCK_HEADERS_DIR})

add_subdirectory(src)
add_subdirectory(test)


