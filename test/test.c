
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"

#define NRM  "\x1B[0m"
#define RED  "\x1B[31m"
#define GRN  "\x1B[32m"

#define TEST_WIDTH 15

#define TEST_EQ(number, name, expected, actual)												\
    char* state = (expected == actual) ? "PASSED" : "FAILED";								\
    char* color = (expected == actual) ? GRN : RED;											\
    int name_len = strlen(name);															\
    printf("TEST %2d: %s", number, name);													\
    for (int _i = name_len; _i < TEST_WIDTH; ++_i) printf((_i == name_len) ? " " : ".");	\
    printf(" %s%s%s\n", color, state, NRM);

static const char* ok_files[] = {
	"print.clox",
	"clock.clox",
	"if.clox",
	"for.clox",
	"while.clox",
	"functions.clox",
	"return.clox",
	"closure.clox",
	"class.clox",
	"this.clox"
};

static const char* err_files[] = {
	"err_params.clox",
	"err_this.clox",
	"err_return.clox"
};

static char* readFile(const char* path) {
	FILE* file = fopen(path, "rb");
	if (file == NULL) {
		fprintf(stderr, "Could not open file \"%s\".\n", path);
		exit(74);
	}

	fseek(file, 0L, SEEK_END);
	size_t fileSize = ftell(file);
	rewind(file);

	char* buffer = (char*)malloc(fileSize + 1);

	if (buffer == NULL) {
		fprintf(stderr, "Not enough memory to read \"%s\".\n", path);
		exit(74);
	}

	size_t bytesRead = fread(buffer, sizeof(char), fileSize, file);
	if (bytesRead < fileSize) {
		fprintf(stderr, "Could not read file \"%s\".\n", path);
		exit(74);
	}

	buffer[bytesRead] = '\0';

	fclose(file);
	return buffer;
}

static bool runFile(const char* path) {
	char* source = readFile(path);
	InterpretResult result = interpret(source);
	free(source); 

	if (result == INTERPRET_COMPILE_ERROR || 
		result == INTERPRET_RUNTIME_ERROR)
		return false;

	return true;
}

int main() {
	initVM();

	printf("\n");

	for (int i = 0; i < 10; ++i) {
		TEST_EQ(i + 1, ok_files[i], true, runFile(ok_files[i]));
		printf("\n\n");
	}

	for (int i = 0; i < 3; ++i) {
		TEST_EQ(i + 1, err_files[i], false, runFile(err_files[i]));
		printf("\n\n");
	}

	freeVM();
}
