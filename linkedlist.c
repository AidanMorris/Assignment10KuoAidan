#include <stdio.h>
#include <assert.h>
#include "./value.h"
#include "./linkedlist.h"

/*
Instead of compiling your code with something like clang -o linkedlist linkedlist.c, 
use the command make. 

This will follow the instructions in Makefile for building your project so 
as to produce an executable called linkedlist. 

At first, it won't build at all because your linkedlist.c file is empty. 
To start, create stubs for every function that you need, with no code inside, 
so that you can get everything to build. 

Once you have done that, you can begin implementing your functions and testing as you proceed.
*/

Value *makeNull() {
    return malloc(sizeof(NULL_TYPE));
}

bool isNull(Value *value) {
    assert(value != NULL && "BAD isNull operation");
    return (value->type == NULL_TYPE);
}