CC=gcc
CFLAGS=-I.

all:	binary_st

binary_st:	binary_st.o bstreelib.o
	$(CC) -o binary_st binary_st.o bstreelib.o

binary_st.o:	binary_st.c bstreelib.h
	$(CC) -c binary_st.c

bstreelib.o:	bstreelib.c bstreelib.h
	$(CC) -c bstreelib.c

clean:
	rm -f *.o binary_st
