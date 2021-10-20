#ifndef _VALUE
#define _VALUE

//this defines the types included by valueType?
typedef enum {INT_TYPE, DOUBLE_TYPE, STR_TYPE, CONS_TYPE, NULL_TYPE} valueType;

//Value only includes type and c.
struct Value {
    valueType type;
    union {
        int i;
        double d;
        char *s;
        struct ConsCell {
            struct Value *car;
            struct Value *cdr;
        } c;  // Note the 'c' here, which names this variable
    };
};

//defining a new c will make the data overwrite c. type must also be changed.

typedef struct Value Value;

#endif
