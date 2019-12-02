cmake_minimum_required(VERSION 3.15)
project(adventOfCode)

add_definitions(-std=c++11)

set(SOURCE_FILES main.cpp)
add_executable(aoc_run ${SOURCE_FILES})

include_directories(aoc)

add_subdirectory(aoc)
#add_subdirectory(aoc_tests)

target_link_libraries(aoc_run aoc)
