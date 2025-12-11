//
// Created by aidankeefe on 12/9/25.
//

#include "day4_util.h"

#include <stdlib.h>
#include <string.h>

#include "../tools/cust_fileReader/file_reader.h"
#include "../tools/Logger/logger.h"

constexpr bool Paper = true;
constexpr bool Empty = false;


bool createWareHouse(Arena a[static 1], Warehouse w[static 1], FILE f[static 1]) {

    bool** warehouse_floor = arena_alloc(a, sizeof(*warehouse_floor) * w->length);
    if (!warehouse_floor) {
        log_message(LOG_ERROR, "Failed to allocate memory for warehouse floor");
    }
    w->warehouse = warehouse_floor;

    for (int i = 0; i < w->length; i++) {
        w->warehouse[i] = arena_alloc(a, sizeof(bool) * w->width);
        if (!w->warehouse[i]) {
            log_message(LOG_ERROR, "Failed to allocate memory for warehouse floor %d", i);
            exit(1);
        }
    }

    Arena* temp = create_arena(w->width + 2 + sizeof(Line));

    for ( int i = 0; i<w->length; i++) {
        Line* line = read_line(temp, f);
        if (line->len != w->width) return false;
        for ( int j = 0; j<line->len; j++) {
            w->warehouse[i][j] = line->line[j] == '@' ? Paper : Empty;
            printf("%c", line->line[j]);
        }
        printf("\n");
        arena_clear(temp);
    }

    printf("\n");
    printf("\n");
    return true;
}

bool is_paper_roll(int x, int y, Warehouse w[static 1]) {
    log_debug("looking at cell %d, %d", x, y);
    if (x < 0 || x >= w->length || y < 0 || y >= w->width) return Empty;
    return w->warehouse[x][y] == Paper;
}

bool checkCell(int x, int y, Warehouse w[static 1]) {

    if (w->warehouse[x][y] == Empty) return false;

    constexpr int x_modifiers[3] = {-1,0,1};
    constexpr int y_modifiers[3] = {-1,0,1};

    int count = 0;
    int iter =0;
    for ( int i = 0; i<3; i++) {
        for ( int j = 0; j<3; j++) {
            if (!((j == 1) && (i == 1))) {
                iter++;
                if (is_paper_roll(x+x_modifiers[i], y+y_modifiers[j], w)) count++;
            }
        }
    }

    if (iter != 8) log_message(LOG_ERROR, "Wrong number of iterations %d", iter);
    constexpr int limit_for_free_space = 4;
    return count  < limit_for_free_space;
}