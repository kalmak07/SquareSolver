#include "MySqrEquation.h"

const short countDataInTest = 7;

struct testData {
    char testName[20];
    short testNumber;
    double aTest;
    double bTest;
    double cTest;
    short countRes;
    double x1Res;
    double x2Res;
};

struct testData Tests[] {
    {"infRoots",    0,  0, 0,  0,  infRoot,    0,  0},
    {"1",   1,    0, 0,  1,  noRoot,     0,  0},
    {"1",   2,    1e-20,  1e-20,  1e-20,  infRoot,    0,  0},
    {"1",   3,    0,  2,  1,  oneRoot,    -0.5,  0}
};

void TestSolver() {
    bool  errUnitTest = false;
    unsigned int countTests = sizeof(Tests) / sizeof(Tests[0]);
    unsigned int countGoodTests = countTests;

    for (unsigned int i = 0; i < countTests; i++) {
        double x1Test = 0, x2Test = 0, countRootTest = 0;

        countRootTest = solveRoot(Tests[i].aTest,
                                Tests[i].bTest,
                                Tests[i].cTest,
                                &x1Test, &x2Test);

        if (!(isRavno(countRootTest, Tests[i].countRes) &&
        isRavno(x1Test, Tests[i].x1Res) &&
        isRavno(x2Test, Tests[i].x2Res))) {
            COLORED_PRINT(RED, ("Error in test #%hi, name test: %s\n", Tests[i].testNumber, Tests[i].testName));
            COLORED_PRINT(RED, ("Input: A: %lf B: %lf C: %lf\n", Tests[i].aTest, Tests[i].bTest, Tests[i].cTest));
            COLORED_PRINT(RED, ("Ouput: CountRoots: %lg x1: %lf, x2: %lf, Expected output: CountRoots: %hi x1: %lf, x2: %lf\n", countRootTest, x1Test, x2Test, Tests[i].countRes, Tests[i].x1Res, Tests[i].x2Res));
            COLORED_PRINT(RED, ("----------------------------------------------------------\n"));
            errUnitTest = true;
            countGoodTests --;
        }

    }

    if (countGoodTests == countTests) COLORED_PRINT(GREEN, ("Ok %u/%u Unit tests\n", countGoodTests, countTests));
    else COLORED_PRINT(YELLOW, ("Ok %u/%u Unit tests\n", countGoodTests, countTests));

    assert(!errUnitTest);

}
