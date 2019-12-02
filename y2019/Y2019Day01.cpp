//
// Created by MKoni on 01.12.2019.
//

#include "Y2019Day01.h"

string Y2019Day01::getPathInInputDir() {
    return R"(2019\01.txt)";
}

Y2019Day01::Y2019Day01() {
    inputVector = inputLinesToIntVector();
}

void Y2019Day01::solve() {
    task1FuelForModules();
    task2FuelForModulesAndFuel();
}

void Y2019Day01::printDay() {
    cout << "** Year 2019 - Day 1 **" << endl;
    if (task1FuelForAllModules > 0) {
        cout << "Task 1; Fuel for all modules:\n" << task1FuelForAllModules << endl;
    } else {
        cout << "Day 1 not solved yet!" << endl;
        return;
    }
    if (task2FuelForAllModulesAndFuel > 0) {
        cout << "Task 2; Fuel for all modules and the fuel itself:\n" << task2FuelForAllModulesAndFuel << endl;
    } else {
        cout << "Day 1 Task 2 not solved yet!" << endl;
    }
}

void Y2019Day01::task1FuelForModules() {
    vector<int> fuelForModules;
    task1FuelForAllModules = 0;
    int fuelForModule = 0;
    for (auto module: inputVector) {
        fuelForModule = fuelForWeight(module);
        fuelForModules.push_back(fuelForModule);
        task1FuelForAllModules += fuelForModule;
    }
    taskt1FuelForModules = fuelForModules;
}

void Y2019Day01::task2FuelForModulesAndFuel() {
    task2FuelForAllModulesAndFuel = 0;
    for (auto fuelForModule: taskt1FuelForModules) {
        task2FuelForAllModulesAndFuel += fuelForFuel(fuelForModule);
    }
    task2FuelForAllModulesAndFuel += task1FuelForAllModules;
}

int Y2019Day01::fuelForWeight(int weight) {
    return weight / 3 - 2;
}

int Y2019Day01::fuelForFuel(int fuelWeight) {
    int fuelForFuel = 0;
    int partialFuel = fuelForWeight(fuelWeight);
    while (partialFuel > 0) {
        fuelForFuel += partialFuel;
        partialFuel = fuelForWeight(partialFuel);
    }
    return fuelForFuel;
}
