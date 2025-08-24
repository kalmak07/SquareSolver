#include "MySqrEquation.h"
#include "consts.h"



int main(void) {

    //atexit(restoreColor);

    COLORED_PRINT(YELLOW, ("quadratic equation solver v0.23\n"));

    #ifdef _DEBUG
        TestSolver();
    #endif

    COLORED_PRINT(WHITE, ("------------------------------\n"));
    COLORED_PRINT(WHITE, ("indicate coefficients A, B, C:\n"));

    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;

    if (input(&a, &b, &c, attempts)) {
        short result = solveRoot(a, b, c, &x1, &x2);
        conclusion(result, x1, x2);
    }

    return 0;
}

