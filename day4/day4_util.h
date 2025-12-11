//
// Created by aidankeefe on 12/9/25.
//

#ifndef ADVENTOFCODE2025_DAY4_UTIL_H
#define ADVENTOFCODE2025_DAY4_UTIL_H
#include "../tools/Arena/Arena.h"
#include <stdio.h>

typedef struct warehouse {
    const int width;
    const int length;
    bool** warehouse;
}Warehouse;

bool createWareHouse(Arena* a, Warehouse* w, FILE* f);
bool checkCell(int x, int y, Warehouse* w);




#endif //ADVENTOFCODE2025_DAY4_UTIL_H