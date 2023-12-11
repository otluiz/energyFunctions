CC = g++
CFLAGS = -std=c++11 -I/usr/include/eigen3/Eigen/ # Substitua /path/to/eigen pelo caminho para a biblioteca Eigen
LDFLAGS = -lm

all: saltoQtico

saltoQtico: saltoQtico.o QuantumGates.o
	$(CC) $(CFLAGS) -o saltoQtico saltoQtico.o QuantumGates.o $(LDFLAGS)

saltoQtico.o: saltoQtico.cpp
	$(CC) $(CFLAGS) -c saltoQtico.cpp

QuantumGates.o: QuantumGates.cpp QuantumGates.h
	$(CC) $(CFLAGS) -c QuantumGates.cpp

clean:
	rm -f saltoQtico saltoQtico.o QuantumGates.o
