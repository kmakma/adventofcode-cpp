//
// Created by MKoni on 02.12.2019.
//

#ifndef ADVENTOFCODE_Y2019DAY03_H
#define ADVENTOFCODE_Y2019DAY03_H

#include <algorithm>
#include "Y2019Day.h"
#include "WireGrid.h"

class Y2019Day03 : public Y2019Day {
public:
    Y2019Day03();

    void solve() override;

protected:
    int getDay() override;

    WireGrid wireGrid = WireGrid();

    string getDescriptionTask1() override;

    string getDescriptionTask2() override;

    string getResultTask1() override;

    string getResultTask2() override;

private:
    int task1ClosestIntersectionDistance = -1;
    void task1DistanceClosestIntersection();

    void task2();

    static vector<wirePathDot> wireIntersections(vector<wirePathDot> firstWire, vector<wirePathDot> secondWire);

    static int distanceClosestIntersection(const vector<wirePathDot>& intersections);
};

#endif //ADVENTOFCODE_Y2019DAY03_H
