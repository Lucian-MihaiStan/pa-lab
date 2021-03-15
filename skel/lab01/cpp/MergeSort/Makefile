all: build run

build:
	g++ -Wall -Wextra -std=c++17 -Werror=vla *.cpp -o main

run: build
	./main

clean:
	rm -rf main