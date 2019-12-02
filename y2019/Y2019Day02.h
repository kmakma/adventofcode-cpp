//
// Created by MKoni on 02.12.2019.
//

#ifndef ADVENTOFCODE_Y2019DAY02_H
#define ADVENTOFCODE_Y2019DAY02_H


#include "../Day.h"

class Y2019Day02 : public Day {
public:
    Y2019Day02();

    void solve() override;

    void printDay() override;

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
    string getPathInInputDir() override;
};

#endif //ADVENTOFCODE_Y2019DAY02_H
