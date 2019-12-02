#include <iostream>
#include "Day.h"
#include "y2019/Y2019Day01.h"
#include "y2019/Y2019Day02.h"

// new day = est/utc-5

int main() {
    std::cout << " * * * * * * * * * * * * * * * * * * * * *\n"
                 " *  Welcome to Advent of Code Solutions  *\n"
                 " *       provided to you by kmakma       *\n"
                 " * * * * * * * * * * * * * * * * * * * * *" << std::endl;
    Y2019Day01().solveAndPrint();
    Y2019Day02().solveAndPrint();
    return 0;
}