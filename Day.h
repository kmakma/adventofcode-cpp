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
    virtual void solve() = 0;

    void solveAndPrint();

    void printResults();

protected:
    const string notSolvedString = "task not solved yet!";

    virtual int getYear() = 0;

    virtual int getDay() = 0;

    virtual string getDescriptionTask1() = 0;

    virtual string getDescriptionTask2() = 0;

    virtual string getResultTask1() = 0;

    virtual string getResultTask2() = 0;

    string getPathInInputDir() override;
};

#endif //ADVENTOFCODE_DAY_H
