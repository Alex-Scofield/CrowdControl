# Define the compiler to use
CXX = g++

# Define the flags to pass to the compiler
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

# Define the linker flags
LDFLAGS = -Llib -lopengl32 -lglu32 -lfreeglut

# Define the target executable
TARGET = simulation

# Define the source directory
SRCDIR = src

# Define the binary directory
BINDIR = bin

# Define the source files
SRCS = $(SRCDIR)/main.cpp $(SRCDIR)/graphics.cpp $(SRCDIR)/model.cpp $(SRCDIR)/object.cpp 

# Define the object files
OBJS = $(SRCS:.cpp=.o)

# Default target to build
all: $(BINDIR)/$(TARGET)

# Rule to build the target executable
$(BINDIR)/$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS)
	rm -f $(OBJS)

# Rule to build object files from source files
$(SRCDIR)/main.o :$(SRCDIR)/main.cpp $(SRCDIR)/graphics.hpp $(SRCDIR)/model.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(SRCDIR)/graphics.o: $(SRCDIR)/graphics.cpp $(SRCDIR)/graphics.hpp $(SRCDIR)/model.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(SRCDIR)/model.o: $(SRCDIR)/model.cpp $(SRCDIR)/model.hpp $(SRCDIR)/object.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(SRCDIR)/object.o: $(SRCDIR)/object.cpp $(SRCDIR)/object.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


# Clean up build files
clean:
	rm -f $(TARGET) $(OBJS)
	rm -f $(INDIR)/$(TARGET)

.PHONY: all clean
