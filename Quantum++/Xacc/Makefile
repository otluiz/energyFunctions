CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11

SRC = testeXacc.cpp
OBJ = $(SRC:.cpp=.o)
EXECUTABLE = xaccBin

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXECUTABLE)
