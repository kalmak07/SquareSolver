#include "MySqrEquation.h"

static bool isLog = false;

bool getIsLog() {
    return isLog;
}

void editIsLog(bool localIsLog) {
    isLog = localIsLog;
}

void saveLog(const char * massage) {

    if (getIsLog()) {

        FILE *fLog;

        fLog = fopen("Log.log", "a+");

        fprintf(fLog, "%s:%d massage: %s ", __FILE__, __LINE__, massage);
        fprintf(fLog, "in Func: %s\n", __PRETTY_FUNCTION__);

        fclose(fLog);

    }
}

/**
 * @brief this func definition flags
 *
 * @param[in] argc count flags
 * @param[in] argv array with flags
 * @param[out] stractFlag struct, where are stored flags
 *
 * @note this func definition flags and stored flags
 * @warning This func definition only -h, -t, -f, -a flags
 */

const char * dictFlag[] = {"-h", "--HELP", "-t", "--TEST", "-f", "--FILE", "-a", "--ACCURACY", "-l", "--LOG"};

void flagDefinition(int argc, char * argv[], struct ProgramFlags * stractFlag) {
    int flugNumber;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-') continue;

        if (checkDictFlag(argv[i], &flugNumber)) {
            i += flagByNumber(flugNumber, argv[i], stractFlag) - 1;
        }
    }
}

bool checkDictFlag(char sFlag[], int * fl) {

    for (int i = 0; i < sizeof(sFlag) / sizeof(sFlag[0]); i++) {
        if (strcmp(sFlag, dictFlag)) {
            *fl = i / 2;
            return true;
        }
    }

    return false
}

int flagByNumber(int fl, int argc, char argv[], struct ProgramFlags * stractFlag) {
    switch (fl) {
        case HELP:
            stractFlag->showHelp = true;
            break;
        case RUN_TESTS:
            stractFlag->runTests = true;
            break;
        case IS_FILE:
            stractFlag->isFile = true;
            break;
        case ACCURACY:
            stractFlag->accuracy = true;
            break;
        case LOGGER:
            stractFlag->logger = true;
            break;
        default:
            COLORED_PRINT(RED, ("unknown flag\n"));
    return 1;
    }
}



/**
 * @brief this func write help about starts flags
 *
 * @note This func write only about -h, -t, -f -a
 */

void showHelp() {
    COLORED_PRINT(MAGENTA, ("----------------------------------------\n"));
    COLORED_PRINT(CYAN, ("Flag list:\n\n"));
    COLORED_PRINT(MAGENTA, ("-h - show help\n\n"));
    COLORED_PRINT(MAGENTA, ("-t - run all unit tests. Required for -f\n     Work only in debug mode\n\n"));
    COLORED_PRINT(MAGENTA, ("-f - write all unit tests in csv table\n     Work only in debug mode\n\n"));
    COLORED_PRINT(MAGENTA, ("-a - use accuracy up to 8 digits\n\n"));
    COLORED_PRINT(MAGENTA, ("-l - includes logging\n     Work only in debug mode\n\n\n\n"));
    COLORED_PRINT(MAGENTA, ("----------------------------------------\n"));
}

