# Compiler settings
CC = gcc
# Compiler flags (modify as needed)
CFLAGS = -Wall -g
# Get all .c files in the directory (using shell to handle special characters)
SRC = $(shell ls *.c)
# Remove the .c extension and add .out to create executable names
EXE = $(SRC:.c=.out)

# Default rule: compile each .c file into an executable with .out extension
all: $(EXE)

# Rule to compile each .c file into its corresponding .out executable
%.out: %.c
	-$(CC) $(CFLAGS) -o $@ "$<"

# Clean rule: remove all executables generated by the build
clean:
	rm -f $(EXE)

