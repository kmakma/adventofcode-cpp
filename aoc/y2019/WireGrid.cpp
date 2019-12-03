//
// Created by MKoni on 03.12.2019.
//

#include "WireGrid.h"

void WireGrid::parsePathInstructions(const vector<vector<string>> &stringVectors) {
    buildWirePathInstructions(stringVectors);
    buildWirePaths();
}

vector<wirePathDot> WireGrid::getWirePath(int i) {
    return wirePaths[i];
}

wirePathInstruction WireGrid::parseToPathInstruction(string pathInstruction) {
    wirePathInstruction wirePathInst = wirePathInstruction();
    switch (pathInstruction[0]) {
        case 'U':
            wirePathInst.direction = Direction::vertical;
            wirePathInst.length = stoi(pathInstruction.substr(1));
            break;
        case 'D':
            wirePathInst.direction = Direction::vertical;
            wirePathInst.length = -1 * stoi(pathInstruction.substr(1));
            break;
        case 'R':
            wirePathInst.direction = Direction::horizontal;
            wirePathInst.length = stoi(pathInstruction.substr(1));
            break;
        case 'L':
            wirePathInst.direction = Direction::horizontal;
            wirePathInst.length = -1 * stoi(pathInstruction.substr(1));
            break;
    }
    return wirePathInst;
}

void WireGrid::buildWirePathInstructions(const vector<vector<string>> &stringVectors) {
    for (const vector<string> &stringVector : stringVectors) {
        vector<wirePathInstruction> pathInstructions;
        pathInstructions.reserve(stringVector.size());
        for (const string &strInstruction : stringVector) {
            pathInstructions.push_back(parseToPathInstruction(strInstruction));
        }
        wirePathInstructions.push_back(pathInstructions);
    }
}

void WireGrid::buildWirePaths() {
    for (const vector<wirePathInstruction> &wirePathInsrts:wirePathInstructions) {
        vector<wirePathDot> wirePathDots;
        wirePathDots.emplace_back(0, 0);
        for (const wirePathInstruction wirePathInstr:wirePathInsrts) {
            vector<wirePathDot> nextWirePathDots;
            nextWirePathDots = buildWirePath(wirePathInstr, wirePathDots.back());
            wirePathDots.insert(wirePathDots.end(), nextWirePathDots.begin(), nextWirePathDots.end());
        }
        wirePaths.push_back(wirePathDots);
    }
}

vector<wirePathDot> WireGrid::buildWirePath(wirePathInstruction pathInst, wirePathDot lastDot) {
    vector<wirePathDot> wirePath;
    int x = lastDot.x;
    int y = lastDot.y;
    int *changePt;
    if (pathInst.direction == Direction::horizontal) {
        changePt = &x;
    } else {
        changePt = &y;
    }
    int changeBy;
    if (0 > pathInst.length) {
        changeBy = -1;
    } else {
        changeBy = +1;
    }
    int changedBy = 0;
    do {
        *changePt += changeBy;
        changedBy += changeBy;
        wirePath.emplace_back(x, y);
    } while (changedBy < pathInst.length);
    return wirePath;
}
