//
// Created by MKoni on 02.12.2019.
//

#include "InputParser.h"

vector<int> InputParser::csvLineToIntVector() {
    function<vector<int>(ifstream &)> readCSVLineToIntVector = [](ifstream &inputFile) -> vector<int> {
        string line;
        vector<int> numbers;
        if (inputFile >> line) {
            numbers = csvStringToIntVector(line);
        }
        return numbers;
    };
    return parseInput(readCSVLineToIntVector);
}

vector<vector<string>> InputParser::csvLinesToStringVectors() {
    function<vector<vector<string>>(ifstream &)> readCSVLinesToStringVectors = [](
            ifstream &inputFile) -> vector<vector<string>> {
        vector<vector<string>> stringVectors;
        string line;
        while (inputFile >> line) {
            stringVectors.push_back(csvStringToStringVector(line));
        }
        return stringVectors;
    };
    return parseInput(readCSVLinesToStringVectors);
}

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

vector<int> InputParser::csvStringToIntVector(const string &str) {
    vector<int> numbers;
    stringstream ss(str);
    string word;
    while (getline(ss, word, ',')) {
        numbers.push_back(stoi(word));
    }
    return numbers;
}

vector<string> InputParser::csvStringToStringVector(const string &str) {
    vector<string> strings;
    stringstream ss(str);
    string word;
    while (getline(ss, word, ',')) {
        strings.push_back(word);
    }
    return strings;
}
