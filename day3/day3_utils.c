//
// Created by aidankeefe on 12/3/25.
//

#include "day3_utils.h"


bool find_largest_combo(char ret[static 2],char* string, size_t len) {
    char temp[2];
    long max = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i+1; j < len; j++) {
            temp[0] = string[i];
            temp[1] = string[j];
            long val = strtol(temp, NULL, 10);
            if (val > max) {
                ret[0] = temp[0];
                ret[1] = temp[1];
                max = val;
            }
        }
    }

    return true;
}

