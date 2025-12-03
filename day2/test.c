//
// Created by aidankeefe on 12/3/25.
//

#include <assert.h>
#include <string.h>

#include "day2_utils.h"
void TestCheckPattern(void) {

    char* s = "1212";
    int len = strlen(s);
    Scanner* scanner = &(Scanner){
        s,
        len-1,
    };

    update_scanner(scanner, len, 1);

    assert(check_pattern(scanner, "1", 1) == false);
    update_scanner(scanner, len, 2);
    assert(check_pattern(scanner, "12", 2) == true);

}

void TestRepeatChecker(void) {
    char* s1 = "1212";
    int len = strlen(s1);

    assert(repeat_checker(s1, len) == true);

    char* s2 = "321";
    len = strlen(s2);
    assert(repeat_checker(s2, len) == false);

    char* s3 = "1188511885";
    len = strlen(s3);
    assert(repeat_checker(s3, len) == true);

    char* s4 = "121212";
    len = strlen(s4);
    assert(repeat_checker(s4, len) == false);

}

int main(void) {
    TestCheckPattern();
    TestRepeatChecker();
}