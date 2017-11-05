P= program4
CFLAGS= -g -std=gnu11

all: $(P)

run: $(P)
	./$(P)

checkmem: $(P)
	valgrind ./$(P)

clean:
	rm -f $(P).o $(P)

$(P): $(P).o tournament.o
	gcc $(CFLAGS) $(P).o  tournament.o -o $(P)

$(P).o: $(P).c
	gcc $(CFLAGS) -c $(P).c -o $(P).o

tournament.o: tournament.h tournament.c
	gcc $(CFLAGS) -c tournament.c -o tournament.o

