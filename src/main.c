#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"

void opConstant()
{
    initVM();

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

    freeVM();
    freeChunk(&chunk);
}

void opConstantLong()
{
    Chunk chunk;
    initChunk(&chunk);

    int line = 124;

    writeConstant(&chunk, 10.0, line);

    line++;

    int constant = addConstant(&chunk, 5.5);
    writeChunk(&chunk, OP_CONSTANT, line);
    writeChunk(&chunk, constant, line);

    line++;
    writeChunk(&chunk, OP_RETURN, line);

    disassembleChunk(&chunk, "test constant long");
    freeChunk(&chunk);
}

int main(int argc, const char *argv[])
{
    opConstant();
    opConstantLong();
    return 0;
}
