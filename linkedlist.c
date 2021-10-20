#include <stdio.h>
#include <stdlib.h>
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
    return (Value*) malloc(sizeof(NULL_TYPE));
}

bool isNull(Value *value) {
    assert(value != NULL && "BAD isNull operation");
    return (value->type == NULL_TYPE);
}

Value *cons(Value *newCar, Value *newCdr) {
    
    //structs are value types, so no need to dereference.
    struct ConsCell new_cell;
    new_cell.car = newCar;
    new_cell.cdr = newCdr;

    //make a cons_type Value. Set it correctly.
    Value* new_cons_type;
    new_cons_type->type = CONS_TYPE;
    new_cons_type-> c = new_cell;
    
    //make the space.
    Value* returned_cons_type = malloc(sizeof(new_cons_type));

    //copy over, and return.
    *returned_cons_type = *new_cons_type;
    return returned_cons_type;
}