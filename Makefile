CC = gcc
CFLAGS = -Wall -std=c99

all:test

ps_naive.o: ps_naive.c points_segments.h
	$(CC) $(CFLAGS) -c ps_naive.c

ps_qsort.o: ps_qsort.c points_segments.h
	$(CC) $(CFLAGS) -c ps_qsort.c

test.o: test.c points_segments.h
	$(CC) $(CFLAGS) -c test.c

test: ps_naive.o ps_qsort.o test.o
	$(CC) $(CFLAGS) -o test ps_naive.o ps_qsort.o test.o

clean:
	rm ps_naive.o ps_qsort.o test.o test
