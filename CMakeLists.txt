cmake_minimum_required(VERSION 3.15)
project(adventOfCode)

set(CMAKE_CXX_STANDARD 14)

add_executable(adventOfCode main.cpp Day.cpp Day.h y2019/Y2019Day01.cpp y2019/Y2019Day01.h y2019/Y2019Day02.cpp y2019/Y2019Day02.h InputParser.cpp InputParser.h y2019/IntcodeComputer.cpp y2019/IntcodeComputer.h)