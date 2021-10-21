#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "./value.h"
#include "./linkedlist.h"
#include <string.h>

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
    Value* new_value = malloc(sizeof(Value));
    new_value->type = NULL_TYPE;
    return new_value;
}

bool isNull(Value *value) {
    assert(value != NULL);
    return (value->type == NULL_TYPE);
}

Value *cons(Value *newCar, Value *newCdr) {

    Value* returned_cons_type = malloc(sizeof(Value));

    //copy over, and return.
    returned_cons_type->type = CONS_TYPE;
    returned_cons_type->c.cdr = newCdr;
    returned_cons_type->c.car = newCar;

    return returned_cons_type;
}

Value *car(Value *list) {
    assert(list->type == CONS_TYPE);
    return list->c.car;
}

Value *cdr(Value *list) {
    assert(list->type == CONS_TYPE);
    return list->c.cdr;
}

void display(Value *list) {
    //print car
    switch (list->type) {
        case NULL_TYPE:
            break;
        case CONS_TYPE:
            display(car(list));
            display(cdr(list));
        case INT_TYPE:
            printf("%i ", list->i);
            break;
        case DOUBLE_TYPE:
            printf("%f ", list->d);
            break;
        case STR_TYPE:
            printf("\"%s\" ", list->s);
            break;
        default:
            break;
    }
    
}

Value *reverse(Value *list) {
    
    if(list->type == NULL_TYPE){
        Value* empty_value = malloc(sizeof(Value));
        empty_value->type = NULL_TYPE;
        return empty_value;
    }

    Value* new_value = malloc(sizeof(Value));
    while(list->type != NULL_TYPE){

    }

    switch(list->type){
        case NULL_TYPE:
            break;
        case CONS_TYPE:
            cons(reverse(cdr(list)), reverse(car(list)));
            break;
        case STR_TYPE:
            break;
    }
    
    Value* new_list = malloc(sizeof(Value));
    return new_list;
}

int length(Value *value) {
    if(value->type == NULL_TYPE){
        return 0;
    }
    int count = 1;//might be 0 here. iffy.
    Value* current_value = value;
    
    while(cdr(current_value)->type != NULL_TYPE){
        count++;
        current_value = cdr(current_value);
    }
    return count;
}

void cleanup(Value *list) {
    switch(list->type){
        case NULL_TYPE:
            break;
        case CONS_TYPE:
            cleanup(car(list));
            cleanup(cdr(list));
            break;
        case STR_TYPE:
            free(list->s);
            break;
        default:
            break;
    }
    free(list);
}