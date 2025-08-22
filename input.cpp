#include "MySqrEquation.h"

void clearInputBuffer() {
    int testBuf;
    while ((testBuf = getchar()) != '\n' && testBuf != EOF) { }
}

bool input(double * a, double * b, double * c, int attempt) {

    for (attempt = attempt; attempt > 0; attempt = attempt - 1) {
        if (scanf("%lf %lf %lf", a, b, c) != 3) printf("invalid values, attempts left %i\n", attempt);
        else return true;
        clearInputBuffer();
    }

    printf("the program is tired");
    return false;
}

void conclusion(short count, double x1, double x2) {
    switch (count) {
        case noRoot:
            printf("No roots\n");
            break;
        case oneRoot:
            printf("One root:\n x1 = x2 = %lf\n", x1);
            break;
        case twoRoot:
            printf("Two roots:\n x1 = %lf\n x2 = %lf\n", x1, x2);
            break;
        case infRoot:
            printf("Inf roots");
            break;
        default:
            printf("Xz");
            break;
    }
}
