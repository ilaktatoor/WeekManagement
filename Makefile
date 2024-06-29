# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c11

# SQLite3 library
LIBS = -lsqlite3

# Source files
SRC = main.c expenses.c database.c

# Header files
HEADERS = expenses.h 

# Object files
OBJ = $(SRC:.c=.o)

# Output executable
EXEC = expenses_app

# Build target
all: $(EXEC)

# Link object files to create the executable
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

# Compile source files into object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: all clean
