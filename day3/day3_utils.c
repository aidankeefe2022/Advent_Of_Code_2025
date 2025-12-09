//
// Created by aidankeefe on 12/3/25.
//

#include "day3_utils.h"

#include <stdio.h>

void end_case(char* string, CharStack* stack) {
    int cur_stack_index = 1;
    while (cur_stack_index < stack->capacity) {
        if (*string > stack->stack[cur_stack_index]) {
            pop_from_position(stack, cur_stack_index);
            push(stack, *string);
        }else if (*string > stack->stack[stack->size-1]) {
            pop_from_position(stack, stack->size-1);
            push(stack, *string);
        }else {
            push(stack, *string);
        }
        string++;
        cur_stack_index++;
    }
}

bool find_largest_combo(char* string, const size_t len, CharStack* stack) {
    int remaining = len;
    while (*string) {
        int string_value = *string - '0';
        if (remaining < stack->capacity) {
            end_case(string, stack);
            break;
        }else {
            pop_all_less_than(stack, string_value);
            push(stack, *string);
        }
        remaining--;
        string++;
    }
    return true;
}

