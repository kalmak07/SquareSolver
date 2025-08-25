#include "MySqrEquation.h"

/**
 * @brief This func run all tests, create csv file and write all data test
 *
 * @param[in] isFile if true, then writes to file, else write in console
 *
 * @note This func run all tests, create csv file and write all data test
 */

void runTests(bool  isFile) {

    FILE *fSolver;

    if (isFile) {

        fSolver = fopen("testsSolver.csv", "w");

        assert(fSolver != NULL);

        fprintf(fSolver, "testNumber, status, testName, aIn, bIn, cIn, \
         expCountRes, CountRes, expX1Res, X1Res, expX2Res, X2Res\n");

    }

    TestSolver(isFile, fSolver);

    //fclose(fSolver);

}
