#include "MySqrEquation.h"

/**
 * @brief Return stock color
 *
 * @note This func return stock color in windows terminal
 */

void restoreColor() {
    setColor(WHITE, BG_BLACK);
}

/**
 * @brief This func changes color in windows terminal
 *
 * @param[in] textColor changes text color
 * @param[in] bgColor changes background color
 *
 * @note This func changes color in windows terminal. Check number on correspondence windows colors.
 * @warning Text color number always less 16. Background color number write in format: 1 << 4.
 */

void setColor(short textColor, short bgColor) {

    assert(textColor < 16);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //WORD attributes = textColor | bgColor;
    SetConsoleTextAttribute(hConsole, (WORD)(textColor | bgColor));
}

/**
 * @brief This func clear input Buffer
 *
 * @note This func clear input Buffer. Need for correct work scanf.
 */

void clearInputBuffer() {
    int testBuf;
    while ((testBuf = getchar()) != '\n' && testBuf != EOF) { }
}

/**
 * @brief This func get data from terminal
 *
 * @param[out] a Pointer to the first number
 * @param[out] b Pointer to the second number
 * @param[out] c Pointer to the third number
 * @param[in] attempt count attempt on input
 *
 * @note This func changes color in windows terminal. Check number on correspondence windows colors.
 * @warning Text color number always less 16. Background color number write in format: 1 << 4.
 */

bool input(double * a, double * b, double * c, int attempt) {

    for (attempt = attempt; attempt > 0; attempt = attempt - 1) {
        if (scanf("%lf %lf %lf", a, b, c) != 3) {
            Sleep(1);
            COLORED_PRINT(RED, ("invalid values, attempts left %i\n", attempt)); //ERROR!!!
        }
        else return true;
        clearInputBuffer();
    }

    COLORED_PRINT(RED, ("the program is tired"));

    return false;
}

/**
 * @brief This func display data on terminal
 *
 * @param[in] count count roots equation
 * @param[in] x1 first root equation
 * @param[in] x2 second root equation
 *
 * @note This func display data on windows terminal.
 * @warning Check count on correspondence with enum Roots.
 */

void conclusion(short count, double x1, double x2) {
    switch (count) {
        case noRoot:
            COLORED_PRINT(YELLOW, ("No roots\n"));
            break;
        case oneRoot:
            COLORED_PRINT(GREEN, ("One root:\n x1 = x2 = %lf\n", x1));
            break;
        case twoRoot:
            COLORED_PRINT(GREEN, ("Two roots:\n x1 = %lf\n x2 = %lf\n", x1, x2));
            break;
        case infRoot:
            COLORED_PRINT(YELLOW, ("Inf roots"));
            break;
        default:
            setColor(RED, BG_BLACK);
            COLORED_PRINT(RED, ("Xz"));
            break;
    }
}
