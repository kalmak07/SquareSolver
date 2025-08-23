#include "MySqrEquation.h"

/**
 * @brief Compares two numbers
 *
 * @param[in] a Thirst compared number
 * @param[in] b Second compared number
 *
 * @note Compares two numbers. The accuracy is determined by the const eps.
 * @warning Check number on type double.
 */

bool isRavno(double a, double b) {
    return (fabs(a-b) < eps);
}

/**
 * @brief Compares numbers with zero
 *
 * @param[in] x Compared number
 *
 * @note Compares number with zero. The accuracy is determined by the const eps.
 * @warning Check number on type double.
 */

bool isZero(double x) {
    return (fabs(x) < eps);
}

/**
 * @brief Solve linear equations ax^2 + bx + c = 0
 *
 * @param[in] b Coefficient at x
 * @param[in] c Free member
 * @param[out] x1 Pointer to the first root
 * @param[out] x2 Pointer to the second root
 * @return short count of real roots:
 *               - 0: no roots
 *               - 1: one root
 *               - -1: infinity roots
 *
 * @note To work with complex roots and linear equations, use a different function.
 * @warning Check pointers for NULL before using them
 */

short solveLineRoot(double b, double c, double * x1) {
    if (isRavno(b, 0)) {
        if (isRavno(c, 0)) return infRoot;
        else return noRoot;
    }

    else {
        *x1 = -c / b;
        if (isZero(*x1)) *x1 = 0;
        return oneRoot;
    }
}

/**
 * @brief Solve square equations ax^2 + bx + c = 0
 *
 * @param[in] a Coefficient at x^2
 * @param[in] b Coefficient at x
 * @param[in] c Free member
 * @param[out] x1 Pointer to the first root
 * @param[out] x2 Pointer to the second root
 * @return short count of real roots:
 *               - 0: no roots
 *               - 1: one root
 *               - 2: two roots
 *               - -1: infinity roots
 *
 * @note To work with complex roots, use a different function.
 * @warning Check pointers for NULL before using them
 */

short solveRoot(double a, double b, double c, double * x1, double * x2) {
    if (isRavno(a, 0)) {
        return solveLineRoot(b, c, x1);
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
