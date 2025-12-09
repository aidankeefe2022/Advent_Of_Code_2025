//
// Created by aidankeefe on 12/3/25.
//

#ifndef ADVENTOFCODE2025_STACK_H
#define ADVENTOFCODE2025_STACK_H
#include <stddef.h>


typedef enum Stack_Result {
    STACK_OK = 0,
    STACK_OVERFLOW,
    STACK_UNDERFLOW,
    STACK_ERROR,
    STACK_EMPTY,
    STACK_FULL,
}Stack_Result;

typedef struct StackBox {
    Stack_Result Error;
    int value;
}StackBox;

typedef struct IntStack {
    int capacity;
    int size;
    char stack[];
}CharStack;

CharStack* createStack(int size);
StackBox pop(CharStack* stack);
Stack_Result push(CharStack* stack, char value);
Stack_Result pop_all_less_than(CharStack* stack, int val);
Stack_Result pop_from_position(CharStack* stack, int position);

Stack_Result reset(CharStack* stack);



#endif //ADVENTOFCODE2025_STACK_H