//
// Created by aidankeefe on 12/3/25.
//


#include <stdio.h>

#include "day3_utils.h"
#include "../Arena/Arena.h"
#include "../cust_fileReader/file_reader.h"
#include "../Stack/Stack.h"

int main(int argc, const char * argv[]) {
    if (argc != 2) {
        printf("Usage: ./day3 <filename>\n");
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    Arena* arena;
    if ((arena = create_arena(1024)) == nullptr) {
        printf("Error creating arena\n");
        fclose(fp);
    }

    char* line;
    long joltage = 0;
    CharStack* ret = createStack(12);
    while ((line = read_line(arena, fp))) {
        find_largest_combo(line, strlen(line), ret);
        printf("%s\n", ret->stack);
        joltage += strtol(ret->stack, NULL, 10);
        reset(ret);
        arena_pop(arena, line);
    }

    printf("Joltage: %ld\n", joltage);
    fclose(fp);
    free(arena);
    return 0;


}