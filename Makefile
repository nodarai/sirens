CC = g++


.PHONY: all
all: sirens main

sirens:
	g++ -c Sirens.cpp -o sirens.o

main:
	g++ sirens.o main.cpp -o sirens

.PHONY: clean
clean:
	rm -rf *.o
	rm -rf sirens
