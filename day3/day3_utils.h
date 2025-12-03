//
// Created by aidankeefe on 12/3/25.
//

#ifndef ADVENTOFCODE2025_DAY3_UTILS_H
#define ADVENTOFCODE2025_DAY3_UTILS_H
#include <string.h>


bool find_largest_combo(char ret[static 2],char* string, int len) {
    char temp[2];
    long max = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i+1; j < len; j++) {
            temp[0] = string[i];
            temp[1] = string[j];


        }
    }

    return true;
}

#endif //ADVENTOFCODE2025_DAY3_UTILS_H