//
// Created by aidankeefe on 12/3/25.
//

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "day3_utils.h"

void TestFindLargestCombo(void) {
    CharStack* char_stack = createStack(3);
    assert(char_stack != NULL);
    char* string = "412345";
    size_t len = strlen(string);
    find_largest_combo(string, len, char_stack);
    assert(strcmp(char_stack->stack, "445") == 0);

}

int main(void) {
    TestFindLargestCombo();
}