OPT = -O3 -Wall -std=c++20

all: build run

build: src/main.cpp
	$(CXX) $(OPT) $< -o build/main

run: build/main
	./build/main

clean:
	rm -f build/main
