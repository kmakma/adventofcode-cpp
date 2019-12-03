//
// Created by MKoni on 02.12.2019.
//

#include "Y2019Day03.h"

Y2019Day03::Y2019Day03() {
    // todo parse file
    wireGrid.parsePathInstructions(csvLinesToStringVectors());
}

void Y2019Day03::solve() {
    task1DistanceClosestIntersection();
    task2();
}

int Y2019Day03::getDay() {
    return 3;
}

string Y2019Day03::getDescriptionTask1() {
    return "Distance to closest intersection of wires:";
}

string Y2019Day03::getDescriptionTask2() {
    return "unknown task 2"; // todo description 2
}

string Y2019Day03::getResultTask1() {
    if (task1ClosestIntersectionDistance > 0) {
        return to_string(task1ClosestIntersectionDistance);
    }
    // todo result test and return [1]
    return notSolvedString;
}

string Y2019Day03::getResultTask2() {
    // todo result test and return [2]
    return notSolvedString;
}

void Y2019Day03::task1DistanceClosestIntersection() {
    vector<wirePathDot> intersections = wireIntersections(wireGrid.getWirePath(0), wireGrid.getWirePath(1));
    task1ClosestIntersectionDistance = distanceClosestIntersection(intersections);
}

void Y2019Day03::task2() {

}

vector<wirePathDot> Y2019Day03::wireIntersections(vector<wirePathDot> firstWire, vector<wirePathDot> secondWire) {
    vector<wirePathDot> intersections;
    set_intersection(firstWire.begin(), firstWire.end(), secondWire.begin(), secondWire.end(),
                     back_inserter(intersections));
    return intersections;
}

int Y2019Day03::distanceClosestIntersection(const vector<wirePathDot> &intersections) {
    int shortestDistance = intersections[0].distance();
    for (wirePathDot wpd : intersections) {
        int distance = wpd.distance();
        if (distance != 0 && (distance < shortestDistance || shortestDistance == 0)) {
            shortestDistance = distance;
        }
    }
    return shortestDistance;
}
