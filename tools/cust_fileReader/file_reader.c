//
// Created by aidankeefe on 12/1/25.
//

#include "file_reader.h"

char* read_line(Arena* a, FILE f[static 1]) {
    return read_to_delimiter(a, f, '\n');
}

char* read_to_delimiter(Arena* a, FILE f[static 1], char delimiter) {
    long current_line_space = ftell(f);
    long str_len = 0;
    int c;
    while ((c = getc(f)) != delimiter) {
        if (c == EOF)
            break;
        str_len++;
    }

    if (str_len == 0) {
        return nullptr;
    }

    fseek(f, current_line_space , SEEK_SET);
    char* line = arena_alloc(a, sizeof(char) * str_len + 1);
    if (!line) {
        return nullptr;
    }
    fread(line, 1, str_len+1, f);

    //swap delimiter with a end string char
    line[str_len] = '\0';
    return line;
}