#ifndef HEDDER_H
#define HEDDER_H

#include <cmath>
#include <stdio.h>
#include <assert.h>
#include <windows.h>
#include "consts.h"

#define COLORED_PRINT(color, message) do { \
    setColor(color, BG_BLACK); \
    printf message; \
    restoreColor(); \
} while(0)

bool isZero(double x);
bool isRavno(double a, double b);
short solveLineRoot(double b, double c, double * x1);
short solveRoot(double a, double b, double c, double * x1, double * x2);
bool input(double * a, double * b, double * c, int attempt);
void conclusion(short count, double x1, double x2);
void setColor(short textColor, short bgColor);
void clearInputBuffer();
void TestSolver();

void restoreColor();
void signalHandler(int signal);

#endif
