# Define the compiler
CC = gcc

# Define compiler flags
CFLAGS = -Wall -Wextra -std=c11

# Define the target executable
TARGET = gastos_program

# Define the source files
SRCS = main.c expenses.c

# Define the object files
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Rule to link the object files into the final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean up the build
clean:
	rm -f $(OBJS) $(TARGET)

# Rule to run the program
run: $(TARGET)
	./$(TARGET)

# Declare phony targets
.PHONY: all clean run
