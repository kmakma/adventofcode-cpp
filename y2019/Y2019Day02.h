//
// Created by MKoni on 02.12.2019.
//

#ifndef ADVENTOFCODE_Y2019DAY02_H
#define ADVENTOFCODE_Y2019DAY02_H

#include "Y2019Day.h"

class Y2019Day02 : public Y2019Day {
public:
    Y2019Day02();

    void solve() override;

private:
    vector<int> inputVector;
    int task1Index0OfProgram = -1;
    int task2InitialParameterCode = -1;

    static vector<int> runIntcodeProgram(vector<int>);

    static void runIntcodeProgram(vector<int> *);

    static vector<int> determineIntcodeProgramForIndex0(vector<int> vec);

    void task1IntcodeProgramRestoreProgram();

    void task2IntcodeProgramGravityAssist();

protected:
    int getDay() override;

    string getDescriptionTask1() override;

    string getDescriptionTask2() override;

    string getResultTask1() override;

    string getResultTask2() override;
};

#endif //ADVENTOFCODE_Y2019DAY02_H
