//
// Created by aidankeefe on 12/9/25.
//


#include "day4_util.h"
#include "../tools/cust_fileReader/file_reader.h"
#include "../tools/Logger/logger.h"

int main(int argc, const char *argv[]) {
    set_log_level(LOG_INFO);

    if (argc != 2) {
        log_message(LOG_ERROR, "Usage: day4 <input_file>");
        return 1;
    }

    FILE* f;
    if ((f = fopen(argv[1], "r")) == nullptr) {
        log_message(LOG_ERROR, "Could not open input file %s", argv[1]);
        return 1;
    }

    int file_size = (int)get_file_size(f);
    int line_length = get_line_len(f);

    Warehouse warehouse = {.width = line_length, .length = file_size/line_length};

    Arena* a;
    if ((a = create_arena(file_size * 4)) == nullptr) {
        log_message(LOG_ERROR, "Could not create arena");
        goto Error1;
    }

    createWareHouse(a, &warehouse, f);

    int reachable = -1;
    int new_reachable = 0;
    while (new_reachable > reachable){
        reachable = new_reachable;
        for (int i = 0; i < warehouse.length; i++) {
            for (int j = 0; j < warehouse.width; j++) {
                if (checkCell(i,j,&warehouse)) {
                    warehouse.warehouse[i][j] = false;
                    new_reachable++;
                }
            }
        }
    }

    printf("\n\n\n\n");

    for (int i = 0; i < warehouse.length; i++) {
        for (int j = 0; j < warehouse.width; j++) {
            if (warehouse.warehouse[i][j])  printf("@"); else printf(".");
        }
        printf("\n");
    }

    log_info("Reachable spaces %d", reachable);

    arena_free(a);
    fclose(f);
    return 0;
    Error1:
    fclose(f);
    return 1;

}