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
    {"1",   3,    0,  2,  1,  oneRoot,    -0.5,  0},
    {"123",   4,    -0.00001321,  -1,  3,  twoRoot,    -75703.22698180,  2.99988112}
};

/**
 * @brief This func test function solveRoot. This func supports writing in csv file and writing in console. He work with struct testData.
 *
 * @param[in] isFile if true, then writes to file, else write in console
 * @param[out] * fp file, where it is written data of test
 *
 * @note This func work with array of struct
 * @warning Keep the sequence and types of variables
 */

bool TestSolver(bool isFile, FILE * fp) {
    bool  errUnitTest = false;
    char currentTestStatus[3] = "Ok";
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
            if (!isFile) {
                COLORED_PRINT(RED, ("Error in test #%hi, name test: %s\n", Tests[i].testNumber, Tests[i].testName));
                COLORED_PRINT(RED, ("Input: A: %lf B: %lf C: %lf\n", Tests[i].aTest, Tests[i].bTest, Tests[i].cTest));
                COLORED_PRINT(RED, ("----------------------------------------------------------\n"));
                COLORED_PRINT(RED, ("Ouput: CountRoots: %lg x1: %.8lf, x2: %.8lf, Expected output: CountRoots: %hi x1: %.8lf, x2: %.8lf\n", countRootTest, x1Test, x2Test, Tests[i].countRes, Tests[i].x1Res, Tests[i].x2Res));
            }
            errUnitTest = true;
            countGoodTests --;
            currentTestStatus[0] = 'E';
            currentTestStatus[1] = 'r';
            currentTestStatus[2] = 'r';
        }

        if (isFile) {
            fprintf(fp, "%hi, %s, %s, %lf, %lf, %lf, %hi, %lf, %lf, %lf, %lf, %lf\n", \
             Tests[i].testNumber, currentTestStatus, \
             Tests[i].testName, Tests[i].aTest, Tests[i].bTest, \
             Tests[i].cTest, Tests[i].countRes, countRootTest, \
             Tests[i].x1Res, x1Test, Tests[i].x2Res, x2Test);
        }

        currentTestStatus[0] = 'O';
        currentTestStatus[1] = 'k';

    }

    if (countGoodTests == countTests) COLORED_PRINT(GREEN, ("Ok %u/%u Unit solver tests\n", countGoodTests, countTests));
    else COLORED_PRINT(YELLOW, ("Ok %u/%u Unit solver tests\n", countGoodTests, countTests));

    return errUnitTest;

}
