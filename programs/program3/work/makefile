P= gdbTest
Q= program3B
CFLAGS= -g -std=gnu11


##-------------part 2--------------------------
checkmem: $(Q).c
	gcc $(CFLAGS) $(Q).c -o $(Q)
	valgrind ./$(Q)

