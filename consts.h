#ifndef CONSTS_H
#define CONSTS_H

enum Roots {
    noRoot = 0,
    oneRoot = 1,
    twoRoot = 2,
    infRoot = 3
};

enum ConsoleColors{
    // Базовые цвета текста
    BLACK         = 0,   // Чёрный
    DARK_BLUE     = 1,   // Тёмно-синий
    DARK_GREEN    = 2,   // Тёмно-зелёный
    DARK_CYAN     = 3,   // Тёмно-бирюзовый
    DARK_RED      = 4,   // Тёмно-красный
    DARK_MAGENTA  = 5,   // Тёмно-пурпурный
    DARK_YELLOW   = 6,   // Тёмно-желтый (коричневый)
    LIGHT_GRAY    = 7,   // Светло-серый (стандартный)
    DARK_GRAY     = 8,   // Тёмно-серый

    // Яркие цвета текста
    BLUE          = 9,   // Синий
    GREEN         = 10,  // Зелёный
    CYAN          = 11,  // Бирюзовый
    RED           = 12,  // Красный
    MAGENTA       = 13,  // Пурпурный
    YELLOW        = 14,  // Жёлтый
    WHITE         = 15,  // Белый

    // Цвета фона (получаются путем сдвига на 4 бита)
    BG_BLACK         = 0 << 4,   // Чёрный фон
    BG_DARK_BLUE     = 1 << 4,   // Тёмно-синий фон
    BG_DARK_GREEN    = 2 << 4,   // Тёмно-зелёный фон
    BG_DARK_CYAN     = 3 << 4,   // Тёмно-бирюзовый фон
    BG_DARK_RED      = 4 << 4,   // Тёмно-красный фон
    BG_DARK_MAGENTA  = 5 << 4,   // Тёмно-пурпурный фон
    BG_DARK_YELLOW   = 6 << 4,   // Тёмно-желтый фон
    BG_LIGHT_GRAY    = 7 << 4,   // Светло-серый фон
    BG_DARK_GRAY     = 8 << 4,   // Тёмно-серый фон
    BG_BLUE          = 9 << 4,   // Синий фон
    BG_GREEN         = 10 << 4,  // Зелёный фон
    BG_CYAN          = 11 << 4,  // Бирюзовый фон
    BG_RED           = 12 << 4,  // Красный фон
    BG_MAGENTA       = 13 << 4,  // Пурпурный фон
    BG_YELLOW        = 14 << 4,  // Жёлтый фон
    BG_WHITE         = 15 << 4   // Белый фон
};

const int attempts = 10;
const double eps = 1e-8;
const short errInput = -1;

#endif
