#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "value.h"

typedef enum
{
    OP_RETURN,
} OpCode;

typedef struct {
    int count;
    int capacity;
    Byte *code;
    ValueArray constants;
} Chunk;

void initChunk(Chunk *chunk);
void freeChunk(Chunk *chunk);
void writeChunk(Chunk *chunk, Byte byte);
int addConstant(Chunk *chunk, Value value);

#endif
