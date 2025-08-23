#include "MySqrEquation.h"

void setColor(short textColor, short bgColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //WORD attributes = textColor | bgColor;
    SetConsoleTextAttribute(hConsole, (WORD)(textColor | bgColor));
}

void clearInputBuffer() {
    int testBuf;
    while ((testBuf = getchar()) != '\n' && testBuf != EOF) { }
}

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
