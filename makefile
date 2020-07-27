# -*- Makefile -*-

#Source code folder
SRC	= src
INCLUDE = include
INSTANCE = instances

PLATFORM = linux64
CC       = g++

# Executable name
KNP_EX = KNP

$(KNP_EX): instance.o heuristics.o solution.o main.o
	$(CC) instance.o heuristics.o solution.o main.o -o $(KNP_EX)

heuristics.o: $(SRC)/heuristics.cpp $(INCLUDE)/heuristics.h
	$(CC) -c $(SRC)/heuristics.cpp -o heuristics.o

solution.o: $(SRC)/solution.cpp $(INCLUDE)/solution.h
	$(CC) -c $(SRC)/solution.cpp -o solution.o

instance.o: $(SRC)/instance.cpp $(INCLUDE)/instance.h
	$(CC) -c $(SRC)/instance.cpp -o instance.o

main.o: $(SRC)/main.cpp
	$(CC) -c $(SRC)/main.cpp -o main.o

clean:
	rm -rf $(KNP_EX)
	rm -rf *.out
	rm -rf *.o
	rm -rf *.txt
