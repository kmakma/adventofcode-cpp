//
// Created by MKoni on 01.12.2019.
//

#include "Day.h"

void Day::solveAndPrint() {
    solve();
    printResults();
}

void Day::printResults() {
    cout << " ~~~ Year " << getYear() << " - Day " << getDay() << " ~~~\n";
    cout << "  Task 1; " << getDescriptionTask1() << "\n         " << getResultTask1() << "\n";
    cout << "  Task 2; " << getDescriptionTask2() << "\n         " << getResultTask2() << endl;
}

string Day::getPathInInputDir() {
    string day;
    if (getDay() < 10) {
        day = "0" + to_string(getDay());
    } else {
        day = to_string(getDay());
    }
    return to_string(getYear()) + "\\" + day + ".txt";
}
