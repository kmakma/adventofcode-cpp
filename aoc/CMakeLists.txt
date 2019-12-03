project(aoc)

set(SOURCE_HEADER_FILES
        Day.cpp Day.h
        InputParser.cpp InputParser.h
        y2019/IntcodeComputer.cpp y2019/IntcodeComputer.h
        y2019/Y2019Day.h
        y2019/Y2019Day01.cpp y2019/Y2019Day01.h
        y2019/Y2019Day02.cpp y2019/Y2019Day02.h
        y2019/Y2019Day03.cpp y2019/Y2019Day03.h
        y2019/WireGrid.cpp y2019/WireGrid.h)

add_library(aoc STATIC ${SOURCE_HEADER_FILES})