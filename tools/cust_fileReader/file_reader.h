//
// Created by aidankeefe on 12/1/25.
//

#ifndef ADVENTOFCODE2025_FILE_READER_H
#define ADVENTOFCODE2025_FILE_READER_H

#include <stdio.h>
#include "../Arena/Arena.h"


char* read_line(Arena* a, FILE f[static 1]);
char* read_to_delimiter(Arena* a, FILE* f, char delimiter);


#endif //ADVENTOFCODE2025_FILE_READER_H