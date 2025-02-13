CC=gcc
CFLAGS=-Wall -Wextra -g -std=c99
TARGET=lista_sequencial

OBJ=main.o lista.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

main.o: main.c lista.h
	$(CC) $(CFLAGS) -c main.c

lista.o: lista.c lista.h
	$(CC) $(CFLAGS) -c lista.c

run: all
	./$(TARGET)

test: all
	./$(TARGET) > output.txt

diff:
	diff output.txt expected_output.txt

clean:
	rm -f $(TARGET) $(OBJ) output.txt