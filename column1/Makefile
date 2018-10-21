PROGRAM = column1-exe
OBJS = main.o
CC = gcc
CFLAGS = -Wall -O2 -g
.SUFFIXES: .o .c

$(PROGRAM): $(OBJS)
	$(CC) -o $(PROGRAM) $^

.c.o:
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	$(RM) $(PROGRAM) $(OBJS)
