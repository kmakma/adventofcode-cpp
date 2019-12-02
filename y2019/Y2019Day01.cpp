//
// Created by MKoni on 01.12.2019.
//

#include "Y2019Day01.h"

Y2019Day01::Y2019Day01() {
    inputVector = linesToIntVector();
}

void Y2019Day01::solve() {
    task1FuelForModules();
    task2FuelForModulesAndFuel();
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

int Y2019Day01::getDay() {
    return 1;
}

string Y2019Day01::getDescriptionTask1() {
    return "Fuel for all modules:";
}

string Y2019Day01::getDescriptionTask2() {
    return "Fuel for all modules and for the fuel itself:";
}

string Y2019Day01::getResultTask1() {
    if (task1FuelForAllModules > 0) {
        return to_string(task1FuelForAllModules);
    }
    return notSolvedString;
}

string Y2019Day01::getResultTask2() {
    if (task2FuelForAllModulesAndFuel > 0) {
        return to_string(task2FuelForAllModulesAndFuel);
    }
    return notSolvedString;
}
