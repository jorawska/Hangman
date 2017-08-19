cmake_minimum_required(VERSION 3.7)
project(Hangman)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Game.cpp Game.h)
add_executable (Hangman ${SOURCE_FILES})
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")