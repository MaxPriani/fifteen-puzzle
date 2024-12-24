cmake_minimum_required(VERSION 3.25)

project(fifteen)

set(CMAKE_C_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${INCLUDE_DIR})

add_executable(fifteen src/fifteen.c src/game.c src/main.c)
