#ifndef HEDDER_H
#define HEDDER_H

#include <cmath>
#include <stdio.h>
#include "consts.h"

void clearInputBuffer();
bool input(double * a, double * b, double * c, int attempt);
short solveRoot(double a, double b, double c, double * x1, double * x2);
void conclusion(short count, double x1, double x2);
bool isRavno(double a, double b);
bool isZero(double x);

#endif
