//
// Created by aidankeefe on 12/3/25.
//

#ifndef ADVENTOFCODE2025_DAY2_1_H
#define ADVENTOFCODE2025_DAY2_1_H
#include <stdlib.h>
#include <string.h>

typedef struct scanner {
    char* token;
    long remaining;
}Scanner;

bool update_scanner(Scanner* s, long len, long patter_size);

bool check_pattern(Scanner* s, const char* pattern, long patter_size);

bool repeat_checker(char* input, long len);

#endif //ADVENTOFCODE2025_DAY2_1_H