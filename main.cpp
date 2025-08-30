#include "MySqrEquation.h"

int main(int argc, char *argv[]) {

//    printf("%s\n", argv[2]);

    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;
    struct ProgramFlags programFlags;

    flagDefinition(argc, argv, &programFlags);

    signal(SIGINT, signalHandler);  // Ctrl+C
    signal(SIGTERM, signalHandler); // Завершение процесса
    atexit(restoreColor);

    if (programFlags.showHelp) showHelp();

    #ifdef _DEBUG
        if (programFlags.runTests) {
            if (programFlags.isFileTestOut) COLORED_PRINT(BLUE, ("Write unit tests in file\n"));
            else COLORED_PRINT(BLUE, ("Write unit tests in console\n"));
            runTests(programFlags.isFileTestOut);
        }
        if (programFlags.logger) setIsLog(true);
    #endif

    COLORED_PRINT(YELLOW, ("quadratic equation solver v0.4.2\n"));
    COLORED_PRINT(WHITE, ("------------------------------\n"));

    if (programFlags.counts) {
        a = programFlags.A;
        b = programFlags.B;
        c = programFlags.C;
        COLORED_PRINT(WHITE, ("indicate coefficients A, B, C:\n"));
    }else input(&a, &b, &c, attempts);

    short result = solveRoot(a, b, c, &x1, &x2);
    conclusion(result, x1, x2, &programFlags);

    return 0;
}

