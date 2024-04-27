CC=clang
CFLAGS=-I.

all: tcpc tcps

tcpc: client.o common.o
	$(CC) -o tcpc client.o common.o

tcps: server.o common.o
	$(CC) -o tcps server.o common.o

client.o: client.c
	$(CC) -c client.c

server.o: server.c
	$(CC) -c server.c

common.o: common.c
	$(CC) -c common.c

clean:
	rm -f *.o tcpc tcps
