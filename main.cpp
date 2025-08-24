#include "MySqrEquation.h"

int main(int argc, char *argv[]) {
    struct ProgramFlags programFlags;

    flagDefinition(argc, argv, &programFlags);

    signal(SIGINT, signalHandler);  // Ctrl+C
    signal(SIGTERM, signalHandler); // Завершение процесса
    atexit(restoreColor);

    if (programFlags.showHelp) showHelp();

    #ifdef _DEBUG
        if (programFlags.runTests) {
            if (programFlags.isFile) COLORED_PRINT(BLUE, ("Write unit tests in file\n"));
            else COLORED_PRINT(BLUE, ("Write unit tests in console\n"));
            runTests(programFlags.isFile);
        }
    #endif

    COLORED_PRINT(YELLOW, ("quadratic equation solver v0.23\n"));
    COLORED_PRINT(WHITE, ("------------------------------\n"));
    COLORED_PRINT(WHITE, ("indicate coefficients A, B, C:\n"));

    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;

    if (input(&a, &b, &c, attempts)) {
        short result = solveRoot(a, b, c, &x1, &x2);
        conclusion(result, x1, x2);
    }

    return 0;
}

