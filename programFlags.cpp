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

void flagDefinition(int argc, char * argv[], struct ProgramFlags * stractFlag) {
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-') {
            continue;
        }

        if (argv[i][0] != '-') {
            continue;
        }

        if (argv[i][1] == '-') {
            if (strcmp(argv[i], "--help") == 0) {
                stractFlag->showHelp = true;
            }
            else if (strcmp(argv[i], "--test") == 0) {
                stractFlag->runTests = true;
            }
            else if (strcmp(argv[i], "--file") == 0) {
                stractFlag->isFile = true;
            }
            else if (strcmp(argv[i], "--accuracy") == 0) {
                stractFlag->accuracy = true;
            }
            else if (strcmp(argv[i], "--log") == 0) {
                stractFlag->logger = true;
            }
            else {
                COLORED_PRINT(RED, ("unknown flag\n"));
            }
        } else {
            if (argv[i][0] == '-') {
                switch (argv[i][1]) {
                    case '-':
                        if (strcmp(argv[i], "--HELP")) break;
                    case 'h':
                        stractFlag->showHelp = true;
                        break;
                    case 't':
                        stractFlag->runTests = true;
                        break;
                    case 'f':
                        stractFlag->isFile = true;
                        break;
                    case 'a':
                        stractFlag->accuracy = true;
                        break;
                    case 'l':
                        stractFlag->logger = true;
                        break;
                    default:
                        COLORED_PRINT(RED, ("unknown flag\n"));
                }
            }
        }
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

