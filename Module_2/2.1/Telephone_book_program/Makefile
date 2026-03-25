CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = telephone_book

SRCS = main.c telephonebook.c user_interface.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

main.o: main.c telephonebook.h user_interface.h
	$(CC) $(CFLAGS) -c main.c

telephonebook.o: telephonebook.c telephonebook.h
	$(CC) $(CFLAGS) -c telephonebook.c

user_interface.o: user_interface.c user_interface.h telephonebook.h
	$(CC) $(CFLAGS) -c user_interface.c

clean:
	rm -f $(OBJS) $(TARGET)