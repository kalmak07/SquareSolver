MODE = extend

PROJECT_NAME = myApp.exe
VERSION = 0.4.2

PROGRAM = myApp.exe

SRC_FILES = $(wildcard *.cpp)
HDR_FILES = $(wildcard *.h)
ALL_FILES = $(SRC_FILES) $(HDR_FILES)
TXT_FILES = $(ALL_FILES:.cpp=.txt) $(HDR_FILES:.h=.txt)

CC=g++
CFLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline \
-Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default \
-Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy \
-Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op \
-Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith \
-Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits \
-Wwrite-strings -Werror=vla -D_EJUDGE_CLIENT_SIDE #-DEXTENDED_DEBUG_MODE=$(EXTENDED_DEBUG_MODE) #-std=c99
LDFLAGS = -static-libgcc -static-libstdc++ -mconsole

# Флаги для Windows API
ifeq ($(OS),Windows_NT)
    CFLAGS += -D_WIN32_WINNT=0x0600
    LDFLAGS += -luser32 -lgdi32
endif


ifeq ($(MODE),release)
    BUILD_TYPE = Release
	CFLAGS += -DEXTENDED_DEBUG_MODE=0
else ifeq ($(MODE),debug)
    CFLAGS += -D_DEBUG -DEXTENDED_DEBUG_MODE=0
	BUILD_TYPE = Debug
else
	CFLAGS += -DEXTENDED_DEBUG_MODE=1
	CFLAGS += -D_DEBUG
	BUILD_TYPE = Debug
endif

TARGET = $(PROJECT_NAME)
SRCS = main.cpp input.cpp solveRoot.cpp UnitTestSolver.cpp MySqrEquation.h consts.h tests.cpp programFlags.cpp
OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

%.txt: %.cpp
	cat $< >> $@

%.txt: %.h
	cat $< >> $@

extend: $(PROGRAM) $(TXT_FILES)

debug:
	$(MAKE) MODE=debug

release:
	$(MAKE) MODE=release

clean:
	rm *.o *.exe *.txt 2>nul || exit 0

run: $(TARGET)
	$(TARGET)

.PHONY: clean run
