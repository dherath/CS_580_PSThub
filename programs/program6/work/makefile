P= program6
CFLAGS= -g -std=gnu11

all: $(P)

run: $(P)
	./$(P)

checkmem: $(P)
	valgrind ./$(P)

clean:
	rm -f $(P).o bst.o $(P)

$(P): $(P).o bst.o
	gcc $(CFLAGS) $(P).o bst.o -o $(P)

$(P).o: $(P).c
	gcc $(CFLAGS) -c $(P).c -o $(P).o

bst.o: bst.h bst.c
	gcc $(CFLAGS) -c bst.c -o bst.o
