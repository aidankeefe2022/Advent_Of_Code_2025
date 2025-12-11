//
// Created by aidankeefe on 12/10/25.
//

#include "Matrix.h"

#include <string.h>


typedef struct matrix {
    int rows;
    int columns;
    void **matrix;
} Matrix;

Matrix *new_matrix(Arena* a, int r, int c) {
    double m[r][c] = arena_alloc(a, sizeof(*m));
    memset(m, 0, sizeof(*m));
    Matrix *mt = arena_alloc(a, sizeof(*mt));
    if (mt == nullptr) return nullptr;
    *mt = (Matrix){ r, c , .matrix = (void**)m };
}

Matrix* create_matrix_from_file(FILE* f, Arena* a, int r, int c) {
    Matrix *mt = new_matrix(a, r, c);
    if (!mt) return nullptr;
    for (int i = 0; i < r; i++) {
        Line* line;
        if ((line= read_line(a, f)) == nullptr) return nullptr;
        for (int j = 0; j < line->len; j++) {
            mt->matrix[i][j] = line->line[j];
        }
    }
    return mt;
}