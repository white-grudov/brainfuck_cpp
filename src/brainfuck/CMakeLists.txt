cmake_minimum_required(VERSION 3.2)
project(brainfuck C CXX)

set(SOURCE_FILES
    brainfuck.h brainfuck.cpp
    brainfuck_args.h brainfuck_args.cpp
    brainfuck_exceptions.h
)

add_library(brainfuck SHARED STATIC ${SOURCE_FILES})

install(TARGETS brainfuck DESTINATION ${BRAINFUCK_INSTALL_LIB_DIR})
install(FILES brainfuck.h DESTINATION ${BRAINFUCK_INSTALL_INCLUDE_DIR})