CFLAGS = -lssh #-std=c11 -g -O0 -pedantic -Wall -Wextra
CC = gcc #clang
EXEC = server, client

.PHONY: clean all 

all: $(EXEC)

clean: 
	rm $(EXEC) *.o

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $^

server: server.c
	$(CC) $(CFLAGS) -o $@ $^

client: client.c
	$(CC) $(CFLAGS) -o $@ $^