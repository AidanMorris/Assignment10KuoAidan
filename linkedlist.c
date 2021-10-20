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
    Value* new_value;
    return (Value*) malloc(sizeof(new_value));
}

bool isNull(Value *value) {
    assert(value != NULL);
    return (value->type == NULL_TYPE);
}

Value *cons(Value *newCar, Value *newCdr) {
    //make the cell.
    //structs are value types, so no need to dereference.

    

    struct ConsCell new_cell;
    new_cell.car = newCar;
    new_cell.cdr = newCdr;

    //make the cons-ted linked list. Set it correctly.
    Value* new_cons_type;
    new_cons_type->type = CONS_TYPE;
    new_cons_type-> c = new_cell;
    
    //make the space.
    Value* returned_cons_type = malloc(sizeof(new_cons_type));

    //copy over, and return.
    *returned_cons_type = *new_cons_type;
    return returned_cons_type;
}

// Return a pointer to the car value for the cons cell 
// at the head of the given linked list. 
// Use assertions here to make sure that this is a legitimate operation 
// (e.g., there is no car value at the head of an empty list).

//The "head" pointer points to the front of your linked list, whatever you choose to call it, should be of type Value *. 
//If the list is empty, it will point to a Value of type NULL_TYPE; 
//otherwise, it will point to a Value of type ConsType (i.e., a Value representing a cons cell). 
//In a non-empty list, the car of the first cons cell points to a Value representing the 
//first item in the linked list, while the cdr points to a Value of type ConsType, 
//representing the next cons cell in the linked list (and so on). 
//At the end of the linked list will be a Value whose cdr variable points to a Value with type NULL_TYPE. 
//As you may recall, this is very close to how lists are represented in Scheme, under the hood!


Value *car(Value *list) {
    assert(list->type != NULL_TYPE);
    return list->c.car;
}

Value *cdr(Value *list) {
    //assert(list->type != NULL_TYPE);
    return list->c.cdr;
}

void display(Value *list) {

    assert(list->type != NULL_TYPE);
    assert(car(list)->type != NULL_TYPE);//iffy
    assert(car(list)->type != CONS_TYPE);//iffy

    Value* current_value = list;

    printf("(");
    
    while(cdr(current_value)->type!=NULL_TYPE){
        switch (car(current_value)->type) {
        case NULL_TYPE:
            break;
        case CONS_TYPE:
            break;
        case INT_TYPE:
            printf("%i ", car(current_value)->i);
            current_value = cdr(current_value);
            break;
        case DOUBLE_TYPE:
            printf("%f ", car(current_value)->d);
            current_value = cdr(current_value);
            break;
        case STR_TYPE:
            printf("\"%s\" ", car(current_value)->s);
            current_value = cdr(current_value);
            break;
        } 
    }
    printf(")\n");
}

Value *reverse(Value *list) {
    Value* new_list = malloc(sizeof(*list));
    return new_list;
}

int length(Value *value) {

    int count = 1;//might be 0 here. iffy.

    Value* current_value = value;

    while((cdr(current_value))->type == CONS_TYPE){
        count++;
        current_value = cdr(current_value);
    }
    return count;
}

void cleanup(Value *list) {

    Value* current_value = list;

    while(cdr(current_value)->type!=NULL_TYPE){
        if(car(current_value)->type==STR_TYPE){free(car(current_value)->s);}
        current_value = cdr(current_value);
    }
    free(list);
}