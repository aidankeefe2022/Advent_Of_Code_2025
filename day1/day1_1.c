//
// Created by aidankeefe on 12/1/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../Arena/Arena.h"
#include "../cust_fileReader/file_reader.h"

typedef struct Dial {
    int dial_value;
    int zero_cound;
} Dial;

int adjust_dial(char* line, Dial* dial) {
    int len = strnlen(line, 10);

    int line_value = 0;
    char* num_start = line + 1;
    for (int i = len - 3; i > -1; i--) {
        line_value += (int)pow(10, i) * (*num_start - '0');
        num_start++;
    }

    switch (*line) {
        case 'R':
            while (line_value) {
                dial->dial_value++;
                if (dial->dial_value % 100 == 0) {
                    dial->zero_cound++;
                }
                line_value--;
            }
            return 0;
        case 'L':
            while (line_value) {
                dial->dial_value--;
                if (dial->dial_value % 100 == 0) {
                    dial->zero_cound++;
                }
                line_value--;
            }
            return 0;
    }

}

int main(int argc, const char * argv[]) {

    Arena* arena = create_arena(1024);
    if (!arena) {
        return ARENA_CREATION_ERROR;
    }

    if (argc != 2) {
        printf("Usage: ./day1 [filename]\n");
    }

    FILE* f = fopen(argv[1], "r");
    if (!f) {
        printf("Could not open file %s\n", argv[1]);
        goto Error;
    }
    char* line;
    Dial* dial = &(Dial){
        .zero_cound = 0,
        .dial_value = 50,
    };
    int runs = 0;
    while ((line = read_line(arena, f)) != nullptr) {
        adjust_dial(line, dial);
        arena_pop(arena, line);
    }

    printf("Number of zeroes: %d\n", dial->zero_cound);

    free(arena);
    fclose(f);
    return 0;
Error:
    free(arena);
    return 1;


}