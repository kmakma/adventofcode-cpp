//
// Created by MKoni on 02.12.2019.
//

#ifndef ADVENTOFCODE_INPUTPARSER_H
#define ADVENTOFCODE_INPUTPARSER_H

#include <fstream>
#include <functional>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class InputParser {
protected:
    virtual string getPathInInputDir() = 0;

    vector<int> linesToIntVector();

    vector<int> csvLineToIntVector();

private:
    const string defaultInputDir = R"(..\input\)";
    string inputDir = defaultInputDir;

    template<class T>
    vector<T> parseInput(function<vector<T>(ifstream &)> function);

    static vector<int> separateStringToIntVector(const string &);

};

#endif //ADVENTOFCODE_INPUTPARSER_H
