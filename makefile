all: archiver

archiver:
	g++ src/main.cpp -Wall -Wextra --std=c++11 -o bin/archiver