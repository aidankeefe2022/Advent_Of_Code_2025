//
// Created by aidankeefe on 12/3/25.
//


#include <stdio.h>

#include "day3_utils.h"
#include "../Arena/Arena.h"
#include "../cust_fileReader/file_reader.h"

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
    while ((line = read_line(arena, fp))) {
        char ret[2];
        find_largest_combo(ret, line, strlen(line));
        printf("%s\n", ret);
        joltage += strtol(ret, NULL, 10);
        memset(ret, 0, sizeof(ret));
        arena_pop(arena, line);
    }

    printf("Joltage: %ld\n", joltage);
    fclose(fp);
    free(arena);
    return 0;


}