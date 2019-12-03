//
// Created by MKoni on 03.12.2019.
//

#ifndef ADVENTOFCODE_WIREGRID_H
#define ADVENTOFCODE_WIREGRID_H

#include <string>
#include <tuple>
#include <vector>

using namespace std;

enum Direction {
    horizontal, vertical
};

struct wirePathInstruction {
    Direction direction;
    int length;
};

struct wirePathDot {
    int x;
    int y;

    wirePathDot(int xVar, int yVar) : x(xVar), y(yVar) {};

    int distance() const {
        return abs(x) + abs(y);
    }

//    bool operator<(const wirePathDot &a) {
//        return std::tie(x, y) < std::tie(a.x, a.y);
//    }
    bool operator<(const wirePathDot &a) {
        return x < a.x && y < a.y;
    }
};


class WireGrid {
public:
    void parsePathInstructions(const vector<vector<string>> &stringVectors);

    vector<wirePathDot> getWirePath(int i);

private:
    vector<vector<wirePathInstruction>> wirePathInstructions;
    vector<vector<wirePathDot>> wirePaths;

    static wirePathInstruction parseToPathInstruction(string pathInstruction);

    void buildWirePathInstructions(const vector<vector<string>> &stringVectors);

    void buildWirePaths();

    static vector<wirePathDot> buildWirePath(wirePathInstruction pathInst, wirePathDot lastDot);
};


#endif //ADVENTOFCODE_WIREGRID_H
