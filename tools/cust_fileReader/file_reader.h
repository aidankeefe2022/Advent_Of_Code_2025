//
// Created by aidankeefe on 12/1/25.
//

#ifndef ADVENTOFCODE2025_FILE_READER_H
#define ADVENTOFCODE2025_FILE_READER_H

#include <stdio.h>
#include "../Arena/Arena.h"

typedef struct line {
    int len;
    char* line;
}Line;

/*
 * returns the length of the file in bytes
 */
long get_file_size(FILE* f);
/*
 * returns the number of bytes from current position to the next newline or EOF
 */
int get_line_len(FILE* f);
/*
 * reads the file until the next newline or EOF
 */
Line* read_line(Arena* a, FILE f[static 1]);
/*
 * reads the file until the next charater that == the delimeter
 */
Line* read_to_delimiter(Arena* a, FILE* f, char delimiter);


#endif //ADVENTOFCODE2025_FILE_READER_H