//
// Created by aidankeefe on 12/3/25.
//

#include "day2_utils.h"

bool update_scanner(Scanner* s, long len, long patter_size) {
    s->remaining = len - patter_size;
    if (patter_size > s->remaining) {
        return false;
    }
    if (patter_size + s->remaining > len) {
        return false;
    }
    s->token++;

    return true;
}

bool check_pattern(Scanner* s, const char* pattern, long patter_size) {
    if (!pattern)
        return false;
    if (!s)
        return false;
    char* token = s->token;
    while (*token) {
        for (int i = 0; i < patter_size; i++) {
            if (*token != pattern[i]) {
                return false;
            }
            token++;
        }

    }
    return true;
}

bool repeat_checker(char* input, long len) {

    int current_pattern_size = 1;
    Scanner* scanner = (Scanner*)malloc(sizeof(Scanner));
    *scanner = (Scanner){input, len};

    bool ret_flag = false;

    char* pattern = malloc(len * sizeof(char));
    while (update_scanner(scanner, len, current_pattern_size)) {
        memcpy(pattern, input, current_pattern_size);

        if (check_pattern(scanner, pattern, current_pattern_size)) {
            ret_flag = true;
            break;
        }

        memset(pattern, 0, len);
        current_pattern_size++;

    }

    free(pattern);
    free(scanner);
    return ret_flag;
}
