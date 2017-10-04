P= hello
CFLAGS= -g -Wall -std=gnu11

all: $(P)

$(P): $(P).o
	gcc $(CFLAGS) $(P).o -o $(P)

$(P).o: $(P).c
	gcc $(CFLAGS) -c $(P).c -o $(P).o

clean:
	rm $(P).o $(P)

run : $(P)
	./$(P)
