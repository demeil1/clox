CC = gcc
CFLAGS = -Wall -g -I$(SRC_DIR)
TARGET = test
SRC_DIR = ../src

TEST_FILE = test.c

LIBRARY = $(shell find $(SRC_DIR) -name '*.c' ! -name 'main.c') $(SRC_DIR)/*.h
SRC_FILES = $(LIBRARY) $(TEST_FILE)

$(TARGET):
	$(CC) $(CFLAGS) $(SRC_FILES) -o $(TARGET)
	./$(TARGET)

clean:
	rm $(TARGET)
