#include "MySqrEquation.h"
#include "consts.h"

int main(void) {
    printf("quadratic equation solver v0.22\n");

    TestSolver();

    printf("------------------------------\n");
    printf("indicate coefficients A, B, C:\n");


    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;

    if (input(&a, &b, &c, attempts)) {
        short result = solveRoot(a, b, c, &x1, &x2);
        conclusion(result, x1, x2);
    }

    return 0;
}

