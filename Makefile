CC = gcc
CFLAGS = -Wall -g

TARGET = clox
SRC_DIR = src

SRC_FILES = $(SRC_DIR)/*.c $(SRC_DIR)/*.h

$(TARGET):
	$(CC) $(CFLAGS) $(SRC_FILES) -o $(TARGET)

rebuild:
	rm $(TARGET)
	$(CC) $(CFLAGS) $(SRC_FILES) -o $(TARGET)

clean:
	rm $(TARGET)
