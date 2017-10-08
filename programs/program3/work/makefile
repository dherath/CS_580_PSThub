P1=bomb
P2=defuseMe
P3=hidden
#---------------------------------------------
P=defuseTheBomb
Q= program3B
CFLAGS= -g -std=gnu11

all: defuseTheBomb checkmem clean

##-------------part 1--------------------------
# P1-bomb P2-defuseMe P3-hidden
defuseTheBomb:$(P1).o $(P2).o $(P3).o
	gcc $(CFLAGS) $(P1).o $(P2).o $(P3).o -o $(P)

$(P1).o:$(P1).c 
	gcc $(CFLAGS) -c $(P1).c -o $(P1).o

$(P2).o:$(P2).c
	gcc $(CFLAGS) -c $(P2).c -o $(P2).o
##-------------part 2--------------------------
# Q-program3B
checkmem: $(Q).c
	gcc $(CFLAGS) $(Q).c -o $(Q)
	valgrind ./$(Q)
##------------part 3---------------------------
# P-defuseTheBomb P1-bomb P2-defuseMe Q-program3B
clean:
	chmod +x trash.sh
	./trash.sh $(P) $(P1).o $(P2).o $(Q)

