#ifndef clox_vm_h
#define clox_vm_h

#include "chunk.h"
#include "value.h"

#define STACK_MAX 256

typedef struct {
	Chunk* chunk;
	uint8_t* ip;
	Value stack[STACK_MAX];
	Value* stackTop;
} VM;

typedef enum {
	INTERPERET_OK,
	INTERPERET_COMPILE_ERROR,
	INTERPERET_RUNTIME_ERROR,
} InterpreterResult;

void initVM();
void freeVM();
InterpreterResult interperet(const char* source);
void push(Value value);
Value pop();

#endif
