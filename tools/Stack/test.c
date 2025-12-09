//
// Created by aidankeefe on 12/3/25.
//

#include "Stack.h"
#include <assert.h>
#include <stdlib.h>


void TestStack() {
    CharStack* char_stack = createStack(12);
    if (!char_stack) {
        assert(0);
    }

    assert(push(char_stack, '8') == STACK_OK);

    StackBox stack_box = pop(char_stack);
    assert(stack_box.Error == STACK_OK);
    assert(stack_box.value == 8);

    for (int i = 0; i < 4; i++) {
        push(char_stack, '8');
    }

    assert(pop_all_less_than(char_stack, 9) == STACK_OK);

    assert(char_stack->size == 0);
    assert(char_stack->stack[0] == '\0');
}

void TestPopFromPosition(void) {
    CharStack* char_stack = createStack(12);

    for (int i = 0; i < 11; i++) {
        push(char_stack, '8');
    }

    Stack_Result sr = pop_from_position(char_stack, 4);

    assert(sr == STACK_OK);
    assert(char_stack->size == 3);
    assert(char_stack->stack[4] == '\0');


}


int main(void) {
    TestStack();
    TestPopFromPosition();
    return 0;
}