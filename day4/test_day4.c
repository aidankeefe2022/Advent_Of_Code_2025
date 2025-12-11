//
// Created by aidankeefe on 12/10/25.
//

#include <assert.h>
#include <stdlib.h>

#include "../tools/Logger/logger.h"
#include "day4_util.h"

void TestCheckCell(void) {
    bool r[3][3] = {{true,true,true},{false, true,false},{true,false,false}};
    bool** c = malloc(sizeof(bool*) * 3);
    for (int i = 0; i < 3; i++) {
        c[i] = malloc(sizeof(bool) * 3);
        for (int j = 0; j < 3; j++) {
            c[i][j] = r[i][j];
        }
    }
    Warehouse w = {3,3, c};
    assert(checkCell(1,1, &w) == false);
    assert(checkCell(2,0, &w) == true);
    assert(checkCell(2,2, &w) == false);
    assert(checkCell(0,0, &w) == false);
}

int main() {
    set_log_level(LOG_DEBUG);
    TestCheckCell();
}