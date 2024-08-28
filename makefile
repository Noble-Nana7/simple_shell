CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89
TARGET = hsh

SRCS = input.c m_shell.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
    $(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

clean:
    rm -f $(OBJS) $(TARGET)

.PHONY: all clean

