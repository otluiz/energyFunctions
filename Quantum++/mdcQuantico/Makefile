CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11

SRC = mdc.cpp
OBJ = $(SRC:.cpp=.o)
EXECUTABLE = mdc

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXECUTABLE)
