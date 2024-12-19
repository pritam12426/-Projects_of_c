OPT = -O3 -Wall -std=c++20

all: build run

build: src/main.cpp
	$(CXX) $(OPT) $< -o main

run: main
	./main

clean:
	rm -f main
