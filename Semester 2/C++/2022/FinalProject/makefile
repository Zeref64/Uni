# Compiler
CC = g++

# Compiler flags
CFLAGS = -std=c++11 -Wall

# Linker flags
LDFLAGS = -lncurses

# Source files
SRCS = main.cpp game.cpp player.cpp mpampis.cpp loukas.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable file
TARGET = game

# Default target
all: $(TARGET)

# Compile source files into object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files into the executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(TARGET)

# Clean the build directory
clean:
	rm -f $(OBJS) $(TARGET)
