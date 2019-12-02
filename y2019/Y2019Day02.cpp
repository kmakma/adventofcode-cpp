//
// Created by MKoni on 02.12.2019.
//

#include "Y2019Day02.h"

Y2019Day02::Y2019Day02() {
    inputVector = csvLineToIntVector();
}

void Y2019Day02::solve() {
    task1IntcodeProgramRestoreProgram();
    task2IntcodeProgramGravityAssist();
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

int Y2019Day02::getDay() {
    return 2;
}

string Y2019Day02::getDescriptionTask1() {
    return "Index 0 for program with set parameter:";
}

string Y2019Day02::getDescriptionTask2() {
    return "Parameter for program with set index:";
}

string Y2019Day02::getResultTask1() {
    if (task1Index0OfProgram >= 0) {
        return to_string(task1Index0OfProgram);
    } else {
        return notSolvedString;
    }
}

string Y2019Day02::getResultTask2() {
    if (task2InitialParameterCode >= 0) {
        return to_string(task2InitialParameterCode);
    } else {
        return notSolvedString;
    }
}
