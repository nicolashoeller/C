CC=clang
CFLAGS=-I.

all: chatClient chatServer

chatClient: client.o common.o
	$(CC) -o chatClient client.o common.o

chatServer: server.o common.o
	$(CC) -o chatServer server.o common.o

client.o: client.c
	$(CC) -c client.c

server.o: server.c
	$(CC) -c server.c

common.o: common.c
	$(CC) -c common.c

clean:
	rm -f *.o chatClient chatServer
