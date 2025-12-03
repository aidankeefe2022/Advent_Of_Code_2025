//
// Created by aidankeefe on 12/3/25.
//

#include <assert.h>
#include <string.h>
#include "day3_utils.h"

void TestFindLargestCombo(void) {

    char ret[2];
    char* string = "2891";
    int len = strlen(string);
    find_largest_combo(ret, string, len);
    assert(strcmp(ret, "91") == 0);

}

int main(void) {
    TestFindLargestCombo();
}