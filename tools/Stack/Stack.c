//
// Created by aidankeefe on 12/3/25.
//

#include "Stack.h"

#include <stdlib.h>
#include <string.h>

CharStack* createStack(int size) {
    CharStack* stack = malloc(sizeof(CharStack) + size);
    if (!stack) {
        return nullptr;
    }
    *stack = (CharStack) {
        .capacity = size,
        };
    return stack;
}
StackBox pop(CharStack* stack) {
    if (!stack)
        goto UnInit_Error;
    if (stack->size - 1 < 0)
        goto UnderFlow_Error;;
    stack->size--;
    return (StackBox){
        STACK_OK,
        stack->stack[stack->size] - '0',
        };
UnInit_Error:
    return (StackBox){
        .Error = STACK_ERROR,
    };
UnderFlow_Error:
    return (StackBox){
        .Error = STACK_UNDERFLOW,
    };
}

Stack_Result pop_all_less_than(CharStack* stack, int val) {
    if (!stack)
        return STACK_ERROR;
    int stack_ptr = 0;
    while ((stack->stack[stack_ptr] - '0') >= val && stack_ptr < stack->size) {
        stack_ptr++;
    }

    stack->size = stack_ptr;

    while (stack_ptr < stack->capacity) {
        stack->stack[stack_ptr++] = '\0';
    }

    return STACK_OK;
}


Stack_Result push(CharStack* stack, char value) {
    if (!stack) {
        return STACK_ERROR;
    }
    if (stack->size + 1 > stack->capacity) {
        return STACK_OVERFLOW;
    }
    stack->stack[stack->size] = value;
    stack->size++;
    return STACK_OK;
}

Stack_Result pop_from_position(CharStack* stack, int position) {
    int new_size = position;
    if (!stack)
        return STACK_ERROR;
    if (position > stack->size)
        return STACK_OVERFLOW;
    while (position < stack->size) {
        stack->stack[position++] = '\0';
    }

    stack->size = new_size;

    return STACK_OK;
}

Stack_Result reset(CharStack* stack) {
    if (!stack)
        return STACK_ERROR;
    stack->size = 0;
    memset(stack->stack, 0 , stack->capacity);
    return STACK_OK;
}
