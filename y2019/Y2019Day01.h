//
// Created by MKoni on 01.12.2019.
//

#ifndef ADVENTOFCODE_Y2019DAY01_H
#define ADVENTOFCODE_Y2019DAY01_H

#include <cmath>
#include "../Day.h"

class Y2019Day01 : public Day {
public:
    Y2019Day01();

    void solve() override;

    void printDay() override;

private:
    vector<int> inputVector;
    vector<int> taskt1FuelForModules;
    int task1FuelForAllModules = 0;
    int task2FuelForAllModulesAndFuel = 0;

    void task1FuelForModules();

    void task2FuelForModulesAndFuel();

    static int fuelForWeight(int);

    static int fuelForFuel(int);

protected:
    string getPathInInputDir() override;


};


#endif //ADVENTOFCODE_Y2019DAY01_H
