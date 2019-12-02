//
// Created by MKoni on 02.12.2019.
//

#ifndef ADVENTOFCODE_Y2019DAY03_H
#define ADVENTOFCODE_Y2019DAY03_H


#include "Y2019Day.h"

class Y2019Day03 : public Y2019Day {
public:
    Y2019Day03();
    void solve() override;

protected:
    int getDay() override;

    string getDescriptionTask1() override;

    string getDescriptionTask2() override;

    string getResultTask1() override;

    string getResultTask2() override;
};


#endif //ADVENTOFCODE_Y2019DAY03_H
