//
// Created by MKoni on 01.12.2019.
//

#ifndef ADVENTOFCODE_DAY_H
#define ADVENTOFCODE_DAY_H

#include <iostream>
#include "InputParser.h"

using namespace std;

class Day : protected InputParser {
public:
    virtual void printDay() = 0;

    virtual void solve() = 0;

    void solveAndPrint();
};

#endif //ADVENTOFCODE_DAY_H
