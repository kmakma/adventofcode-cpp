//
// Created by MKoni on 02.12.2019.
//

#include "Y2019Day02.h"

string Y2019Day02::getPathInInputDir() {
    return R"(2019\02.txt)";
}

Y2019Day02::Y2019Day02() {
    inputVector = csvLineToIntVector();
}

void Y2019Day02::solve() {
    task1IntcodeProgramRestoreProgram();
    task2IntcodeProgramGravityAssist();
}

void Y2019Day02::printDay() {
    cout << "** Year 2019 - Day 2 **" << endl;
    if (task1Index0OfProgram >= 0) {
        cout << "Task 1; Index of run program:\n" << task1Index0OfProgram << endl;
    } else {
        cout << "Day 2 Task 1 not solved yet!" << endl;
    }
    if (task2InitialParameterCode >= 0) {
        cout << "Task 2; Start parameter for specified output:\n" << task2InitialParameterCode << endl;
    } else {
        cout << "Day 2 Task 2 not solved yet!" << endl;
    }

}

vector<int> Y2019Day02::runIntcodeProgram(vector<int> intcodeProgram) {
    runIntcodeProgram(&intcodeProgram);
    return intcodeProgram;
}

void Y2019Day02::runIntcodeProgram(vector<int> *intcodeProgramPt) {
    vector<int> intcodeProgram = *intcodeProgramPt;
    for (int i = 0; intcodeProgram[i] != 99; i += 4) {
        switch (intcodeProgram[i]) {
            case 1:
                intcodeProgram[intcodeProgram[i + 3]] =
                        intcodeProgram[intcodeProgram[i + 1]] + intcodeProgram[intcodeProgram[i + 2]];
                break;
            case 2:
                intcodeProgram[intcodeProgram[i + 3]] =
                        intcodeProgram[intcodeProgram[i + 1]] * intcodeProgram[intcodeProgram[i + 2]];
                break;
            default:
                cout << "error" << endl;
        }
    }
    *intcodeProgramPt = intcodeProgram;
}

void Y2019Day02::task1IntcodeProgramRestoreProgram() {
    vector<int> intcodeProgram = inputVector;
    intcodeProgram[1] = 12;
    intcodeProgram[2] = 2;
    runIntcodeProgram(&intcodeProgram);
    task1Index0OfProgram = intcodeProgram[0];
}

void Y2019Day02::task2IntcodeProgramGravityAssist() {
    // todo check i=1,2 with n=0..99 until [0]=19690720
    vector<int> gravityAssistIntcodeProgram = determineIntcodeProgramForIndex0(inputVector);
    task2InitialParameterCode = 100 * gravityAssistIntcodeProgram[1] + gravityAssistIntcodeProgram[2];
}

vector<int> Y2019Day02::determineIntcodeProgramForIndex0(vector<int> vec) {
    for (int i1 = 0; i1 <= 100; i1++) {
        vec[1] = i1;
        for (int i2 = 0; i2 <= 100; i2++) {
            vec[2] = i2;
            if (runIntcodeProgram(vec)[0] == 19690720) {
                return vec;
            }
        }
    }
    return vector<int>();
}
