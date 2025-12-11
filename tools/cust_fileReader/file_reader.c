//
// Created by aidankeefe on 12/1/25.
//

#include "file_reader.h"


long get_file_size(FILE* f) {
    long current_line_space = ftell(f);
    fseek(f, 0, SEEK_END);
    long len = ftell(f);
    fseek(f, current_line_space , SEEK_SET);
    return len;
}

int get_len_to_delimeter(FILE* f, char delimiter) {
    int len = 0;
    int c;
    long current_line_space = ftell(f);
    while ((c = fgetc(f)) != delimiter) {
        if (c == EOF) goto End;
        len++;
    }
    End:
        fseek(f, current_line_space , SEEK_SET);
    return len;
}

int get_line_len(FILE* f){
    return get_len_to_delimeter(f, '\n');
}

Line* read_line(Arena a[static 1], FILE f[static 1]) {
    return read_to_delimiter(a, f, '\n');
}

Line* read_to_delimiter(Arena* a, FILE f[static 1], char delimiter) {
    int str_len = get_len_to_delimeter(f, delimiter);
    char* line = arena_alloc(a, sizeof(char) * str_len + 1);
    if (!line) {
        return  nullptr;
    }
    fread(line, 1, str_len+1, f);

    //swap delimiter with a end string char
    line[str_len+1] = '\0';
    Line* l = arena_alloc(a, sizeof(Line));
    *l = (Line){
        .len = str_len,
        .line = line,
    };
    return l;
}