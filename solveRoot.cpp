#include "MySqrEquation.h"

bool isRavno(double a, double b) {
    return (fabs(a-b) < eps);
}

bool isZero(double x) {
    return (fabs(x) < eps);
}

short solveRoot(double a, double b, double c, double * x1, double * x2) {
    if (isRavno(a, 0)) {
        if (isRavno(b, 0)) return noRoot;
        else {
            *x1 = -c / b;
            if (isZero(*x1)) *x1 = 0;
            return oneRoot;
        }
    }

    double d = NAN, sqd = NAN;

    d = b * b - 4 * a * c;

    if (d < 0) return noRoot;

    sqd = sqrt(d);

    *x1 = (-b + sqd) / (2 * a);

    if (isZero(*x1)) *x1 = 0;

    if (isRavno(d, 0))  {
        return oneRoot;
    }
    else {
        *x2 = (-b - sqd) / (2 * a);
        if (isZero(*x2)) *x2 = 0;
        return twoRoot;
    }

}
