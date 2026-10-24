CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude

TARGET = doubly_linked_list

SRC = main.c doubly_linked_list.c
OBJ = $(SRC:.c=.o)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /Q *.o $(TARGET).exe 2>NUL

run: $(TARGET)
	.\$(TARGET).exe