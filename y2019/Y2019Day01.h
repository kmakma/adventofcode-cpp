//
// Created by MKoni on 01.12.2019.
//

#ifndef ADVENTOFCODE_Y2019DAY01_H
#define ADVENTOFCODE_Y2019DAY01_H

#include <cmath>
#include "Y2019Day.h"

class Y2019Day01 : public Y2019Day {
public:
    Y2019Day01();

    void solve() override;

protected:
    int getDay() override;

    string getDescriptionTask1() override;

    string getDescriptionTask2() override;

    string getResultTask1() override;

    string getResultTask2() override;

private:
    vector<int> inputVector;
    vector<int> taskt1FuelForModules;
    int task1FuelForAllModules = 0;
    int task2FuelForAllModulesAndFuel = 0;

    void task1FuelForModules();

    void task2FuelForModulesAndFuel();

    static int fuelForWeight(int);

    static int fuelForFuel(int);
};

#endif //ADVENTOFCODE_Y2019DAY01_H
