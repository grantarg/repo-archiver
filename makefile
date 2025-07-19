all: archiver

archiver:
	g++ src/archiver.cpp -O -O2 -O3 -pedantic -Wall -Wextra --std=c++11 -o bin/archiver