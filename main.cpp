#include "MySqrEquation.h"
#include "consts.h"

int main(void) {
    setColor(YELLOW, BG_BLACK);

    printf("quadratic equation solver v0.23\n");

    #ifdef _DEBUG
        TestSolver();
    #endif

    setColor(WHITE, BG_BLACK);

    printf("------------------------------\n");
    printf("indicate coefficients A, B, C:\n");


    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;

    if (input(&a, &b, &c, attempts)) {
        short result = solveRoot(a, b, c, &x1, &x2);
        conclusion(result, x1, x2);
    }

    setColor(WHITE, BG_BLACK);

    return 0;
}

