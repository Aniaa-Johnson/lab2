CC = gcc
CFLAGS = -Wall
# Remove -lrt since it's not needed on macOS
LDFLAGS = 

# Source files
SRC = main.c ipc.c time.c
OBJ = $(SRC:.c=.o)

# Target executable
TARGET = time

# Build target
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

# Clean target
clean:
	rm -f $(OBJ) $(TARGET)
