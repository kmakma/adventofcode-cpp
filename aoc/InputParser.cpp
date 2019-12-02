//
// Created by MKoni on 02.12.2019.
//

#include "InputParser.h"

vector<int> InputParser::linesToIntVector() {
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

vector<int> InputParser::csvLineToIntVector() {
    function<vector<int>(ifstream &)> readCSVLineToIntVector = [](ifstream &inputFile) -> vector<int> {
        string line;
        vector<int> numbers;
        if (inputFile >> line) {
            numbers = separateStringToIntVector(line);
        }
        return numbers;
    };
    return parseInput(readCSVLineToIntVector);
}

template<class T>
vector<T> InputParser::parseInput(function<vector<T>(ifstream &)> function) {
    string inputPath = inputDir + getPathInInputDir();
    ifstream inputFile(inputPath);
    if (inputFile.good()) {
        vector<T> returnVector = function(inputFile);
        inputFile.close();
        return returnVector;
    } else {
        inputFile.close();
        return vector<T>();
    }
}

vector<int> InputParser::separateStringToIntVector(const string &str) {
    vector<int> numbers;
    stringstream ss(str);
    string word;
    while (getline(ss, word, ',')) {
        numbers.push_back(stoi(word));
    }
    return numbers;
}
