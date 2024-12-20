OPT = -O3 -Wall -std=c17

all: build

build: ./src/main.c ./src/proxy_parse.c
	$(CC) $(OPT) ./src/main.c -c -o ./build/proxy.o -lpthread
	$(CC) $(OPT) ./src/proxy_parse.c -c -o ./build/proxy_parse.o -lpthread
	$(CC) $(OPT) ./build/proxy.o ./build/proxy_parse.o -o ./build/main -lpthread

debug:
	$(CC) $(OPT) -g ./src/main.c -c -o ./build/proxy.o -lpthread
	$(CC) $(OPT) -g ./src/proxy_parse.c -c -o ./build/proxy_parse.o -lpthread
	$(CC) $(OPT) -g ./build/proxy.o ./build/proxy_parse.o -o ./build/main -lpthread
	# lldb ./build/main

run: build/main
	./build/main

clean:
	rm -f ./build/*
