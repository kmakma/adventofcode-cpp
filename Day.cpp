//
// Created by MKoni on 01.12.2019.
//

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

vector<int> Day::inputCSVLineToIntVector() {
    function<vector<int>(ifstream &)> readCSVToIntVector = [](ifstream &inputFile) -> vector<int> {
        string line;
        vector<int> numbers;
        if (inputFile >> line) {
            numbers = separateStringToIntVector(line);
        }
        return numbers;
    };
    return parseInput(readCSVToIntVector);
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

vector<int> Day::separateStringToIntVector(const string& str) {
    vector<int> numbers;
    stringstream ss(str);
    string word;
    while (getline(ss, word, ',')) {
        numbers.push_back(stoi(word));
    }
    return numbers;
}

