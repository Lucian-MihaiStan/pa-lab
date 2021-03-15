all: build run

build:
	g++ -Wall -Wextra -std=c++17 main.cpp -o main

run: build
	cat in
	./main
	cat out

clean: 
	rm -rf main