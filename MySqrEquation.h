#ifndef HEDDER_H
#define HEDDER_H

#include <cmath>
#include <stdio.h>
#include <assert.h>
#include <windows.h>
#include <signal.h>

#include <cstring>

//#include "TXLib.h"
#include "consts.h"

#ifndef EXTENDED_DEBUG_MODE
#define EXTENDED_DEBUG_MODE 1
#endif

#define COLORED_PRINT(color, message) \
do { \
    setColor(color, BG_BLACK); \
    printf message; \
    restoreColor(); \
} while(0)

#define MEGA_ASSERT(trigger) \
do { \
    if (trigger) { printf("This is trigger%s\n", #trigger);\
    printf("[%s:%d]\n", __FILE__, __LINE__); \
    printf("in Func: %s", __PRETTY_FUNCTION__); \
    saveLog("MEGA_ASSERT"); \
    }\
} while(0)

void editIsLog(bool localIsLog);
bool getIsLog();
void saveLog(const char * massage);

bool checkDictFlag(char sFlag[], int * fl);
int flagByNumber(int fl, int argc, char argv[], struct ProgramFlags * stractFlag);
void flagDefinition(int argc, char * argv[], struct ProgramFlags * stractFlag);
void showHelp();

bool isZero(double x);
bool isRavno(double a, double b);
short solveLineRoot(double b, double c, double * x1);
short solveRoot(double a, double b, double c, double * x1, double * x2);

void runTests(bool  isFile);
bool TestSolver(bool isFile, FILE * fp);

bool input(double * a, double * b, double * c, int attempt);
void clearInputBuffer();
void conclusion(short count, double x1, double x2, struct ProgramFlags * stractFlag);

void setColor(short textColor, short bgColor);
void restoreColor();
void signalHandler(int signal);

#endif
