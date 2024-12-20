OPT = -O3 -Wall -std=c17

all: build run

build: ./src/main.c
	$(CC) $(OPT) $< -o ./build/main

run: build/main
	./build/main

clean:
	rm -f ./build/main
