CC = g++
CFLAGS = -std=c++11 -I/usr/include/eigen3/Eigen/ # Substitua /path/to/eigen pelo caminho para a biblioteca Eigen
LDFLAGS = -lm

all: matrixSlater

matrixSlater: matrixSlater.o
	$(CC) $(CFLAGS) -o matrixSlater matrixSlater.o $(LDFLAGS)

matrixSlater.o: matrixSlater.cpp
	$(CC) $(CFLAGS) -c matrixSlater.cpp


clean:
	rm -f matrixSlater matrixSlater.o
