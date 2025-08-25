#include "MySqrEquation.h"

/**
 * @brief this func definition flags
 *
 * @param[in] argc count flags
 * @param[in] argv array with flags
 * @param[out] stractFlag struct, where are stored flags
 *
 * @note this func definition flags and stored flags
 * @warning This func definition only -h, -t, -f flags
 */

void flagDefinition(int argc, char * argv[], struct ProgramFlags * stractFlag) {
    for (int i = 1; i < argc; i++) {
        switch (argv[i][1]) {
            case 'h':
                stractFlag->showHelp = true;
                break;
            case 't':
                stractFlag->runTests = true;
                break;
            case 'f':
                stractFlag->isFile = true;
                break;
            default:
                COLORED_PRINT(RED, ("unknown flag"));
        }
    }
}

/**
 * @brief this func write help about starts flags
 *
 * @note This func write only about -h, -t, -f
 */

void showHelp() {
    COLORED_PRINT(MAGENTA, ("----------------------------------------\n"));
    COLORED_PRINT(CYAN, ("Flag list\n"));
    COLORED_PRINT(MAGENTA, ("-h - show help\n"));
    COLORED_PRINT(MAGENTA, ("-t - run all unit tests. Required for -f\n"));
    COLORED_PRINT(MAGENTA, ("-f - write all unit tests in csv table\n"));
    COLORED_PRINT(MAGENTA, ("----------------------------------------\n"));
}

