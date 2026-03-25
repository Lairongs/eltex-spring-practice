CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude
TARGET = bin/simple_calculator

SRCS = src/main.c src/simple_calculator.c src/user_interface.c
OBJS = build/main.o build/simple_calculator.o build/user_interface.o 

all: $(TARGET)

$(TARGET): $(OBJS) | bin
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

build/main.o: src/main.c include/simple_calculator.h include/user_interface.h | build
	$(CC) $(CFLAGS) -c src/main.c -o build/main.o

build/simple_calculator.o: src/simple_calculator.c include/simple_calculator.h | build
	$(CC) $(CFLAGS) -c src/simple_calculator.c -o build/simple_calculator.o

build/user_interface.o: src/user_interface.c include/user_interface.h | build
	$(CC) $(CFLAGS) -c src/user_interface.c -o build/user_interface.o 

build:
	mkdir -p build

bin: 
	mkdir -p bin

clean:
	rm -f build/*.o $(TARGET)