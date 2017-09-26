P = day8
CFLAGS =-g -Wall -std=gnu11

all:day8

day8:day8.o
	gcc $(CFLAGS) $(P).o -o $(P)
	./day8

day8.o: day8.c
	gcc $(CFLAGS) -c $(P).c -o day8.o
