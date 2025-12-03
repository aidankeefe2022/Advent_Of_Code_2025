//
// Created by aidankeefe on 12/1/25.
//

#include <string.h>

#include "../Arena/Arena.h"
#include "../cust_fileReader/file_reader.h"
#include "day2_utils.h"
#include <stdlib.h>



int main(int argc, const char* argv[]) {

    if (argc != 2) {
        printf("Usage: ./day2_1 <filename>\n");
    }

    FILE* file = fopen(argv[1], "r");
    if (!file) {
        return -1;
    }

    Arena *arena;
    if ((arena = create_arena(1024 * 1024)) == nullptr) {
        fclose(file);
        return -1;
    }

    long long invalid_id_counter = 0;

    char* range;
    while ((range = read_to_delimiter(arena, file, ',')) != nullptr) {
        char* first = strtok(range, "-");
        char* second = strtok(nullptr, "-");
        if (!first || !second)
            goto Error;


        long num1 = strtol(first, nullptr, 10);
        long num2 = strtol(second, nullptr, 10);

        for (long i = num1; i <= num2; i++) {
            memset(second, 0, strlen(second));
            sprintf(second, "%ld", i);
            if (repeat_checker(second, strlen(second))) {
                printf("Repeater: %ld\n", i);
                invalid_id_counter+=i;
            }

        }

        arena_pop(arena, range);
    }

    printf("Number of invalid Ids %lld\n", invalid_id_counter);

    fclose(file);
    free(arena);
    return 0;
Error:
    fclose(file);
    free(arena);
    return 1;
}