//
// Created by MKoni on 01.12.2019.
//

#ifndef ADVENTOFCODE_DAY_H
#define ADVENTOFCODE_DAY_H

#include <iostream>
#include <fstream>
#include <functional>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Day {
public:
    virtual void solve() = 0;

    virtual void printDay() = 0;

    void solveAndPrint();

protected:
    virtual string getPathInInputDir() = 0;

    vector<int> inputLinesToIntVector();
    vector<int> inputCSVLineToIntVector();

    static vector<int> separateStringToIntVector(const string& str);
private:

    string inputDir = R"(..\input\)";
    template<class T>
    vector<T> parseInput(function<vector<T>(ifstream &)> function);
};


#endif //ADVENTOFCODE_DAY_H
