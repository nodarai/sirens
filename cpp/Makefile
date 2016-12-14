CC = g++
FLAGS = -std=gnu++11


.PHONY: all
all: sirens main tests

sirens:
	g++ $(FLAGS) -c Sirens.cpp -o sirens.o

main: sirens
	g++ $(FLAGS) sirens.o main.cpp -o sirens
	
.PHONY: tests
tests:
	g++ $(FLAGS) sirens.o tests.cpp -o sirens_tests
	
.PHONY: check
check:
	./sirens_tests

.PHONY: clean
clean:
	rm -rf *.o
	rm -rf sirens
	rm -rf tests/sirens_tests
