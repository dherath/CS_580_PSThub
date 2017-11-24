P= program5
CFLAGS= -g -std=gnu11

all: $(P)

run: $(P)
	./$(P)

checkmem: $(P)
	valgrind ./$(P)

clean:
	rm -f $(P).o vector.o list.o $(P)

$(P): $(P).o vector.o list.o
	gcc $(CFLAGS) $(P).o vector.o list.o -o $(P)

$(P).o: $(P).c
	gcc $(CFLAGS) -c $(P).c -o $(P).o

vector.o: vector.h vector.c
	gcc $(CFLAGS) -c vector.c -o vector.o

list.o: list.h list.c
	gcc $(CFLAGS) -c list.c -o list.o
