# Compiles the program with g++
CXX = g++

# Uses the -Wall and -std=c++17 flags
CXXFLAGS = -Wall -std=c++17

# The target executable name
TARGET = makefile_demo

# Default target to compile the program
all: $(TARGET)

$(TARGET): makefile_demo.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) makefile_demo.cpp

# Includes a clean target to remove the executable
clean:
	del $(TARGET).exe