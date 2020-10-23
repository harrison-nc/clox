#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"

void mainChunk()
{
    Chunk chunk;
    initChunk(&chunk);

    int constant = addConstant(&chunk, 1.2);
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant, 123);

    constant = addConstant(&chunk, 3.4);
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant, 123);

    writeChunk(&chunk, OP_ADD, 123);

    constant = addConstant(&chunk, 5.6);
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant, 123);

    writeChunk(&chunk, OP_DIVIDE, 123);
    writeChunk(&chunk, OP_NEGATE, 123);

    writeChunk(&chunk, OP_RETURN, 123);

    disassembleChunk(&chunk, "test chunk");
    interpret(&chunk);

    freeChunk(&chunk);
}

void addConstantValue(Chunk *chunk, Value value, int line)
{
    int constant = addConstant(chunk, value);
    writeChunk(chunk, OP_CONSTANT, line);
    writeChunk(chunk, constant, line);
}

void challenge15_1A()
{
    Chunk chunk;
    initChunk(&chunk);

    Chunk *chunkPtr = &chunk;
    int line = 1;

    addConstantValue(chunkPtr, 1, line);
    addConstantValue(chunkPtr, 2, line);
    writeChunk(chunkPtr, OP_MULTIPLY, line);

    addConstantValue(chunkPtr, 3, line);
    writeChunk(chunkPtr, OP_ADD, line);
    writeChunk(chunkPtr, OP_RETURN, line);

    disassembleChunk(chunkPtr, "Chapter 15 : Challenge 1");
    interpret(chunkPtr);
    freeChunk(&chunk);
}

void challenge15_1B()
{
    Chunk main;
    initChunk(&main);
    Chunk *chunk = &main;
    int line = 2;


    addConstantValue(chunk, 1, line);
    addConstantValue(chunk, 2, line);
    addConstantValue(chunk, 3, line);
    writeChunk(chunk, OP_MULTIPLY, line);

    addConstantValue(chunk, 4, line);
    addConstantValue(chunk, 5, line);
    writeChunk(chunk, OP_NEGATE, line);
    writeChunk(chunk, OP_DIVIDE, line);
    writeChunk(chunk, OP_SUBTRACT, line);
    writeChunk(chunk, OP_ADD, line);
    writeChunk(chunk, OP_RETURN, line);

    disassembleChunk(chunk, "Chapter 15 : Challenge 1b");
    interpret(chunk);
    freeChunk(chunk);
}

int main(int argc, const char *argv[])
{
    initVM();

    mainChunk();

    challenge15_1A();
    challenge15_1B();

    freeVM();
    return 0;
}
