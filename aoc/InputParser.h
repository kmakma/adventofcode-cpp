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

    vector<int> csvLineToIntVector();

    vector<vector<string>> csvLinesToStringVectors();

    vector<int> linesToIntVector();

private:
    const string defaultInputDir = R"(..\input\)";
    string inputDir = defaultInputDir;

    template<class T>
    vector<T> parseInput(function<vector<T>(ifstream &)> function);

    static vector<int> csvStringToIntVector(const string & str);

    static vector<string> csvStringToStringVector(const string &str);
};

#endif //ADVENTOFCODE_INPUTPARSER_H
