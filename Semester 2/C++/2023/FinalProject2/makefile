CC = g++
CFLAGS = -std=c++11 -Wall
LDFLAGS = -lncursesw

# List of source files
SRCS = game.cpp player.cpp main.cpp LoukasP1.cpp MpampisP2.cpp MagicGem.cpp

# Generate corresponding object file names
OBJS = $(SRCS:.cpp=.o)

# Name of the executable
TARGET = game

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# Rule for compiling source files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
