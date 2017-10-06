P1=bomb
P2=defuseMe
P3=hidden
#---------------------------------------------
P=defuseTheBomb
Q= program3B
CFLAGS= -g -std=gnu11


##-------------part 1--------------------------
defuseTheBomb:$(P)

$(P): $(P1).o $(P2).o $(P3).o
	gcc $(CFLAGS) $(P1).o $(P2).o $(P3).o -o $(P)

$(P1).o:$(P1).c 
	gcc $(CFLAGS) -c $(P1).c -o $(P1).o

$(P2).o:$(P2).c
	gcc $(CFLAGS) -c $(P2).c -o $(P2).o
##-------------part 2--------------------------
checkmem: $(Q).c
	gcc $(CFLAGS) $(Q).c -o $(Q)
	valgrind ./$(Q)

clean:
	-rm -f $(Q) $(P) $(P1).o $(P2).o

