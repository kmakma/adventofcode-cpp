#include <iostream>
#include "Day.h"
#include "y2019/Y2019Day01.h"
#include "y2019/Y2019Day02.h"

/* how to solve y2019d1t1:
 * - sum fuel consumption += fuel consumption each line
 * - fuel consumption each line:
 * - - read file, for each line do:
 * - - - int line / 3 - 2 (dont use floats/doubles!)
 *
 * Day > dayX
 */


void loadYear(int year = 2018) {
    // yearXcontroller.start()
}

void loadInputYear() {

}

// new day = est/utc-5

int main() {
    std::cout << "*** Welcome to Advent of Code Solutions ***\n*** Provided to you by kmakma ***" << std::endl;
//    Y2019Day01().solveAndPrint();
    Y2019Day02().solveAndPrint();
    return 0;
}