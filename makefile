# -*- Makefile -*-

#Source code folder
SRC	= src
INCLUDE = include
INSTANCE = instances

PLATFORM = linux64
CC       = g++

# Executable name
KNP_EX = KNP

$(KNP_EX): instance.o main.o
	$(CC) instance.o main.o -o $(KNP_EX)

instance.o: $(SRC)/instance.cpp $(INCLUDE)/instance.h
	$(CC) -c $(SRC)/instance.cpp -o instance.o

main.o: $(SRC)/main.cpp
	$(CC) -c $(SRC)/main.cpp -o main.o

clean:
	rm -rf $(KNP_EX)
	rm -rf *.out
	rm -rf *.o
