//
// Created by MKoni on 01.12.2019.
//

//#include <fstream>
//#include <iostream>
//#include <vector>
#include "Day.h"

void Day::solveAndPrint() {
    solve();
    printDay();
}
vector<int> Day::inputLinesToIntVector() {
    function<vector<int>(ifstream &)> readLinesToIntVector = [](ifstream &inputFile) -> vector<int> {
        int currentNumber = 0;
        vector<int> numbers;
        while (inputFile >> currentNumber) {
            numbers.push_back(currentNumber);
        }
        return numbers;
    };
    return parseInput(readLinesToIntVector);
}

template<class T>
vector<T> Day::parseInput(function<vector<T>(ifstream &)> function) {
    string inputPath = inputDir + getPathInInputDir(); // TODO make protected inputPath function
    ifstream inputFile(inputPath);
    if (inputFile.good()) {
        vector<T> returnVector = function(inputFile);
        inputFile.close();
        return returnVector;
    } else {
        return vector<T>();
    }
}
