//#include "MySqrEquation.h"

const short countDataInTest = 7;

double matrixTests[][countDataInTest] = {
//  №   A,  B,  C,  count,  x1Res,  x2Res
    {0, 0, 0,  0,  infRoot,    0,  0},
    {1, 1, 0,  1,  noRoot,     0,  0},
    {2, 1e-20,  1e-20,  1e-20,  infRoot,    0,  0}
};

enum TestsConst {
    TestNumber = 0,
    aTest = 1,
    bTest = 2,
    cTest = 3,
    countRes = 4,
    x1Res = 5,
    x2Res = 6,
};

void TestSolver() {
    bool  errUnitTest = false;
    unsigned int countTests = sizeof(matrixTests) / sizeof(matrixTests[0][0]) / countDataInTest;

    for(unsigned int i = 0; i < countTests; i++) {
        double x1Test = 0, x2Test = 0, countRootTest = 0;

        countRootTest = solveRoot(matrixTests[i][aTest],
                                matrixTests[i][bTest],
                                matrixTests[i][cTest],
                                &x1Test, &x2Test);

        if (!(isRavno(countRootTest, matrixTests[i][countRes]) &&
        isRavno(x1Test, matrixTests[i][x1Res]) &&
        isRavno(x2Test, matrixTests[i][x2Res]))) {
            printf("Error in test #%lg\n", matrixTests[i][TestNumber]);
            printf("Input: A: %lf B: %lf C: %lf\n", matrixTests[i][aTest], matrixTests[i][bTest], matrixTests[i][cTest]);
            printf("Ouput: CountRoots: %lg x1: %lf, x2: %lf, Expected output: CountRoots: %lg x1: %lf, x2: %lf\n", countRootTest, x1Test, x2Test, matrixTests[i][countRes], matrixTests[i][x1Res], matrixTests[i][x2Res]);
            printf("----------------------------------------------------------\n");
            errUnitTest = true;
        }

    }

    assert(!errUnitTest);

    printf("Ok %u Unit tests\n", countTests);
}
