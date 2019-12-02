#include <iostream>
#include "Day.h"
#include "y2019/Y2019Day01.h"

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

void fileTestCsytle() {
    FILE *filePointer = fopen("..\\test.txt", "r");
    if (filePointer == nullptr) return;
    char *line = nullptr;
    size_t len = 0;
    while ((getline(&line, &len, filePointer)) != -1) {
        printf("%s", line);
    }
    fclose(filePointer);
    std::cout<<std::endl;
}

int main() {
    std::cout << "*** Welcome to Advent of Code Solutions ***\n*** Provided to you by kmakma ***" << std::endl;
    Y2019Day01().solveAndPrint();
    return 0;
}