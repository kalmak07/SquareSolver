PROJECT_NAME = myApp.exe
VERSION = 1.0.0

CC = g++
CFLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline \
-Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default \
-Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy \
-Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op \
-Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith \
-Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits \
-Wwrite-strings -Werror=vla -D_EJUDGE_CLIENT_SIDE
LDFLAGS = -static-libgcc -static-libstdc++ -mconsole

# Флаги для Windows API
ifeq ($(OS),Windows_NT)
    CFLAGS += -D_WIN32_WINNT=0x0600
    LDFLAGS += -luser32 -lgdi32
endif

ifeq ($(BUILD),release)
#    CFLAGS += -O2 -DNDEBUG
    BUILD_TYPE = Release
else
    CFLAGS += -D_DEBUG
    BUILD_TYPE = Debug
endif

TARGET = $(PROJECT_NAME)
SRCS = main.cpp input.cpp solveRoot.cpp UnitTestSolver.cpp MySqrEquation.h consts.h tests.cpp programFlags.cpp
OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

debug:
	$(MAKE) BUILD=debug

release:
	$(MAKE) BUILD=release

clean:
	rm *.o *.exe 2>nul || exit 0

run: $(TARGET)
	$(TARGET)

.PHONY: clean run
