#ifndef clox_native_h
#define clox_native_h

#include "value.h"

static Value clockNative(int argCount, Value *arg);
static Value toStringNative(int argCount, Value *value);
static Value printNative(int argCount, Value *value);
static Value exitNative(int argCount, Value *value);
#endif
