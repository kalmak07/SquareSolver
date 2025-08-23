#include "MySqrEquation.h"

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

    assert(textColor < )

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
            setColor(RED, BG_BLACK);
            printf("invalid values, attempts left %i\n", attempt);
            setColor(WHITE, BG_BLACK);
        }
        else return true;
        clearInputBuffer();
    }

    setColor(RED, BG_BLACK);
    printf("the program is tired");
    setColor(WHITE, BG_BLACK);

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
            setColor(YELLOW, BG_BLACK);
            printf("No roots\n");
            break;
        case oneRoot:
            setColor(GREEN, BG_BLACK);
            printf("One root:\n x1 = x2 = %lf\n", x1);
            break;
        case twoRoot:
            setColor(GREEN, BG_BLACK);
            printf("Two roots:\n x1 = %lf\n x2 = %lf\n", x1, x2);
            break;
        case infRoot:
            setColor(YELLOW, BG_BLACK);
            printf("Inf roots");
            break;
        default:
            setColor(RED, BG_BLACK);
            printf("Xz");
            break;
    }

    setColor(WHITE, BG_BLACK);

}
