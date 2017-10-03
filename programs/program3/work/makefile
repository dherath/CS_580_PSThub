P= gdbTest
Q= program3B
CFLAGS= -g -std=gnu11

all: $(P)

$(P): $(P).o
	gcc $(CFLAGS) $(P).o -o $(P)

$(P).o: $(P).c
	gcc $(CFLAGS) -c $(P).c -o $(P).o

##---------------------------------------
checkmem: $(Q).c
	gcc $(CFLAGS)



clean:
	rm $(P).o $(P)

run : $(P)
	./$(P)
